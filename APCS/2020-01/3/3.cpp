#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int INF = 1e18;
signed main(){
    nono_is_handsome

    int n, l;
    cin>>n>>l;
    vector<int> x(n+2, 0), h(n+2, INF), alive;
    for(int i=1; i<=n; i++) cin>>x[i];
    for(int i=1; i<=n; i++) cin>>h[i];
    x[n+1] = l;
    
    alive.push_back(0);
    int cnt=0, mx=0;
    for(int i=1;i<=n;i++){
        if (x[i]-h[i] >= x[alive.back()] || x[i]+h[i] <= x[i+1]){
            cnt++;
            mx = max(mx, h[i]);
            int ind = alive.back();
            while(!alive.empty() && x[ind]+h[ind] <= x[i+1]){
                cnt++;  mx = max(mx, h[ind]);
                alive.pop_back();
                ind = alive.back();
            }
        }
        else    alive.push_back(i);
    }

    cout<<cnt<<"\n"<<mx<<endl;
    return 0;
}