#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 105;
const int INF = 1e18;
int a[N][N], b[N][N], ans=INF, R;
int s, t, n, m, cntA=0, c=0;

void cnt(int x, int y){
    int ret=0, cntB=0;
    for(int i=0;i<s;i++){
        for(int j=0;j<t;j++){
            if (a[i][j]!=b[i+x][j+y])    ret++;
            cntB+=b[i+x][j+y];
        }
    }

    if (ret<=R){
        c++;
        ans = min(ans, abs(cntB-cntA));
    }
    // cout<<x<<" "<<y<<" "<<cntA<<" "<<cntB<<" "<<ret<<"\n";
}

signed main(){
    nono_is_handsome

    cin >> s >> t >> n >> m >> R;
    for(int i=0;i<s;i++)    for(int j=0;j<t;j++)    cin>>a[i][j], cntA+=a[i][j];
    for(int i=0;i<n;i++)    for(int j=0;j<m;j++)    cin>>b[i][j];

    for(int i=0;i+s<=n;i++){
        for(int j=0;j+t<=m;j++){
            cnt(i, j);
        }
    }

    cout<<c<<"\n";
    if (ans==INF)   cout<<"-1\n";
    else    cout<<ans<<"\n";
    return 0;
}