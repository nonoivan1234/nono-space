#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 3e4+5;
struct glass{
    int x, y, t;
};

bool cmp_x(glass g1, glass g2){
    if (g1.x!=g2.x) return g1.x<g2.x;
    return g1.y<g2.y;
}

bool cmp_y(glass g1, glass g2){
    if (g1.y!=g2.y) return g1.y<g2.y;
    return g1.x<g2.x;
}

signed main(){
    nono_is_handsome

    int n;
    cin>>n;

    vector<vector<glass>> X(N), Y(N*2);
    glass g;
    for(int i=0;i<n;i++){
        cin>>g.x>>g.y>>g.t;
        g.y+=N;
        X[g.x].push_back(g);
        Y[g.y].push_back(g);
    }

    int cnt=0, flag = 1, x=0, y=N, dx=1, dy=0;
    while(flag){
        // cout<<x-N<<' '<<y-N<<endl;
        if (dx==1){
            auto next = upper_bound(Y[y].begin(), Y[y].end(), (glass){x, y, 0}, cmp_x);
            if (next==Y[y].end()){
                flag = 0;
                break;
            }
            if (next->t==1){
                dx = 0;
                dy = -1;
            }
            else{
                dx = 0;
                dy = 1;
            }
            x = next->x;
        }
        else if (dx==-1){
            auto next = lower_bound(Y[y].begin(), Y[y].end(), (glass){x, y, 0}, cmp_x);
            if (next==Y[y].begin()){
                flag = 0;
                break;
            }
            next--;
            if (next->t==1){
                dx = 0;
                dy = 1;
            }
            else{
                dx = 0;
                dy = -1;
            }
            x = next->x;
        }
        else if (dy==1){
            auto next = upper_bound(X[x].begin(), X[x].end(), (glass){x, y, 0}, cmp_y);
            if (next==X[x].end()){
                flag = 0;
                break;
            }
            if (next->t==1){
                dx = -1;
                dy = 0;
            }
            else{
                dx = 1;
                dy = 0;
            }
            y = next->y;
        }
        else if (dy==-1){
            auto next = lower_bound(X[x].begin(), X[x].end(), (glass){x, y, 0}, cmp_y);
            if (next==X[x].begin()){
                flag = 0;
                break;
            }
            next--;
            if (next->t==1){
                dx = 1;
                dy = 0;
            }
            else{
                dx = -1;
                dy = 0;
            }
            y = next->y;
        }
        cnt++;
    }

    cout<<cnt<<'\n';
    return 0;
}