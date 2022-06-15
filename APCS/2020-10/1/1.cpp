#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    int a[2], b[2], c[2], n;
    for(int i=0;i<2;i++)    cin>>a[i]>>b[i]>>c[i];
    cin>>n;
    int ans = -1e10;
    for(int i=0;i<=n;i++){
        ans = max(ans, a[0]*i*i+b[0]*i+c[0] + a[1]*(n-i)*(n-i)+b[1]*(n-i)+c[1]);
    }
    cout<<ans<<endl;
}