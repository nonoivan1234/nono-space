#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

struct glass{
    int x, y, k;
};
vector<glass> v;

bool cmp(glass g1, glass g2){
    if (g1.x!=g2.x) return g1.x<g2.x;
    return g1.y<g2.y;
}

signed main(){
    nono_is_handsome

    glass g;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>g.x>>g.y>>g.k;
        v.push_back(g);
    }
    sort(v.begin(), v.end(), cmp);
    int ans=0, flag = 1, x=0, y=0, ind=-1;
    pair<int, int> dir={1, 0};

    while(flag){
        // cout<<x<<' '<<y<<endl;
        if (dir.first==1){
            ind++;
            while(v[ind].y!=y){
                ind++;
                if (ind==v.size()){
                    flag = 0;
                    break;
                }
            }
            if (v[ind].k==1){
                dir = {0, -1};
            }
            else{
                dir = {0, 1};
            }
            x = v[ind].x;
            ans++;
        }
        else if (dir.first==-1){
            ind--;
            while(v[ind].y!=y){
                ind--;
                if (ind<0){
                    flag = 0;
                    break;
                }
            }
            if (v[ind].k==1){
                dir = {0, 1};
            }
            else{
                dir = {0, -1};
            }
            x = v[ind].x;
            ans++;
        }
        else if (dir.second==1){
            ind++;
            while(v[ind].x!=x){
                ind++;
                if (ind==v.size()){
                    flag = 0;
                    break;
                }
            }
            if (v[ind].k==1){
                dir = {-1, 0};
            }
            else{
                dir = {1, 0};
            }
            y = v[ind].y;
            ans++;
        }
        else if (dir.second==-1){
            ind--;
            while(v[ind].x!=x){
                ind--;
                if (ind<0){
                    flag = 0;
                    break;
                }
            }
            if (v[ind].k==1){
                dir = {1, 0};
            }
            else{
                dir = {-1, 0};
            }
            y = v[ind].y;
            ans++;
        }
    }
    cout<<ans-1<<'\n';
}