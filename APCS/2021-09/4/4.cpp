#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 1e6+5;
int arr[N], mp[N], dp[N], tmp[N], lft[N];

signed main(){
    nono_is_handsome

    int n, k;
    cin>>n>>k;
    int maxn = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        if (mp[arr[i]]!=0){
            lft[i] = mp[arr[i]]+1;
        }
        else{
            lft[i] = 1;
        }
        mp[arr[i]] = i;
        lft[i] = max(maxn, lft[i]);
        maxn = max(maxn, lft[i]);
    }

    for(int i=0;i<k;i++){
        for(int j=1;j<=n;j++){
            tmp[j] = max(tmp[j-1], dp[lft[j]-1] + j-lft[j]+1);
        }
        for(int j=1;j<=n;j++)   dp[j] = tmp[j];
    }

    cout<<dp[n]<<'\n';
}