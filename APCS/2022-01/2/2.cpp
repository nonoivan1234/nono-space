#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define MAXN 1005

int main(){
    nono_is_handsome

    int n, m, i, ind, lose[MAXN]={0};
    cin>>n>>m;
    long long s[MAXN], t[MAXN];
    long long a, b, c, d;
    vector<int> v_ind, v_win, v_lose;
    for(i=1;i<=n;i++){
        cin>>s[i];
    }
    for(i=1;i<=n;i++){
        cin>>t[i];
    }
    for(i=1;i<=n;i++){
        cin>>ind;
        v_ind.push_back(ind);
    }
    while(v_ind.size()>1){
        for(i=0;i<=v_ind.size()-2;i+=2){
            long long x = v_ind[i], y = v_ind[i+1];
            long long a = s[x], b = t[x], c = s[y], d = t[y];
            if (a * b >= c * d){    // x win, y lose
                s[x] = a + (c * d)/(2 * b);
                t[x] = b + (c * d)/(2 * a);
                s[y] = c + c/2;
                t[y] = d + d/2;
                lose[y]++;
                if (lose[y]<m){
                    v_lose.push_back(y);
                }
                v_win.push_back(x);
            }
            else{   // y win, x lose
                s[y] = c + (a * b)/(2 * d);
                t[y] = d + (a * b)/(2* c);
                s[x] = a + a/2;
                t[x] = b + b/2;
                lose[x]++;
                if (lose[x]<m){
                    v_lose.push_back(x);
                }
                v_win.push_back(y);
            }
        }
        if (v_ind.size()%2==1)  v_win.push_back(v_ind.back());
        v_ind = v_win;
        for(int it:v_lose) v_ind.push_back(it);
        v_win.clear();
        v_lose.clear();
    }
    cout<<v_ind[0]<<"\n";
}