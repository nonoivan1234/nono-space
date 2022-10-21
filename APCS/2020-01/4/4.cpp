#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 1e6+5;
const int M = 1e4+5;
int n, m;
vector<int> w(N<<1), l(N), r(N), dp(N<<1), Q(M);

int build(int i){
    if (i>=n)   return dp[i] = w[i];

    return dp[i] = build(l[i])+build(r[i]);
}

signed main(){
    nono_is_handsome

    cin >> n >> m;
    for(int i=n;i<2*n;i++)    cin>>w[i];
    for(int i=0;i<m;i++)    cin>>Q[i];
    for(int i=0;i<n-1;i++){
        int p, s, t;
        cin >> p >> s >> t;
        l[p] = s;
        r[p] = t;
    }

    build(1);

    for(int j=0;j<m;j++){
        int i=1, q=Q[j];
        while(i<n){
            dp[i] += q;
            if (dp[l[i]] <= dp[r[i]]){
                i = l[i];
            }
            else{
                i = r[i];
            }
        }
        dp[i]+=q;
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}