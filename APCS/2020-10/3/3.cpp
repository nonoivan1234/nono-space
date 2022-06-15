#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int M = 55;
const int N = 1e5+5;
int arr[N], dp[M][N], l[N], r[N];
signed main(){
    nono_is_handsome

    int m, n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[j];
            if (j==1)   l[j] = dp[i-1][j] + arr[j];
            else    l[j] = max(l[j-1], dp[i-1][j]) + arr[j];
        }
        for(int j=n;j>=1;j--){
            if (j==n)   r[j] = dp[i-1][j] + arr[j];
            else    r[j] = max(r[j+1], dp[i-1][j]) + arr[j];
        }
        for(int j=1;j<=n;j++){
            dp[i][j] = max(l[j], r[j]);
        }
    }
    int ans = -1e10;
    for(int i=1;i<=n;i++){
        ans = max(ans, dp[m][i]);
    }
    cout<<ans<<'\n';
}