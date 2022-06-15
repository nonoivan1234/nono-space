#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

const int N = 105;
int arr[N][4];

signed main(){
    nono_is_handsome

    int n, d, ans=0, tot=0;
    cin>>n>>d;
    for(int i=0;i<n;i++){
        for(int j=1;j<=3;j++)
            cin>>arr[i][j];
    }
    for(int i=0;i<n;i++){
        int mx=0, mn=1000, t=0;
        for(int j=1;j<=3;j++){
            mx = max(mx, arr[i][j]);
            mn = min(mn, arr[i][j]);
            t+=arr[i][j];
        }
        if (mx-mn>=d){
            ans++;
            tot+=t/3;
        }
    }
    cout<<ans<<" "<<tot<<'\n';
}