#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int INF = 1e18;
const int N = 105;
int arr[N][N], vis[N][N];

signed main(){
    nono_is_handsome

    int n, m, x, y, mn=INF;
    cin>>n>>m;
    memset(vis, 1, sizeof(vis));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            vis[i][j]=0;
            if (arr[i][j]<mn){
                mn=arr[i][j];
                x=i;
                y=j;
            }
        }
    }

    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int ans=0;
    while(1){
        // cout<<"x: "<<x<<" "<<y<<endl;
        int mn = INF, nxt_x, nxt_y;
        vis[x][y]=1;
        ans+=arr[x][y];
        for(int i=0;i<4;i++){
            int nx = x+dir[i][0], ny=y+dir[i][1];
            // cout<<nx<<" "<<ny<<endl;
            if (!vis[nx][ny] && arr[nx][ny]<mn){
                mn=arr[nx][ny];
                nxt_x=nx;
                nxt_y=ny;
            }
        }
        x = nxt_x;
        y = nxt_y;
        if (mn==INF) break;
    }
    cout<<ans<<endl;
}