#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 1e4+5;
const int M = 55;
int m, n, arr[M][N], dp[M][N][3];   // dp[i][j][k] = max sum of path to (i, j) from (k=1 left, k=2 right) k=0 is the optimal solution of (i, j)

signed main(){
    nono_is_handsome

    cin>>m>>n;

    for(int i=1;i<=m;i++)   for(int j=1;j<=n;j++)   cin>>arr[i][j];

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)   dp[i][j][1] = max(dp[i][j-1][1], dp[i-1][j][0]) + arr[i][j];
        for(int j=n;j>=1;j--)   dp[i][j][2] = max(dp[i][j+1][2], dp[i-1][j][0]) + arr[i][j];
        for(int j=1;j<=n;j++)   dp[i][j][0] = max(dp[i][j][1], dp[i][j][2]);
    }

    int ans=0;
    for(int i=1;i<=n;i++)   ans = max(ans, dp[m][i][0]);
    cout<<ans<<"\n";
    return 0;
}