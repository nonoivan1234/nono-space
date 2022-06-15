#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

int solve(vector<int> a, vector<int> b){
    int ret = -1e18;
    int la = a.size();
    int lb = b.size();
    for (int d = -la+1;d<=lb-1;d++){
        int s = 0;
        int p = 0;
        for (int i = max(0LL,-d); i<min(la,lb-d);i++){
            s += a[i]*b[i+d];
            ret = max(ret,s-p);
            p = min(p,s);
        }
    }
    return ret;
}

signed main(){
    nono_is_handsome

    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<m;i++)    cin>>b[i];
    int ans = solve(a, b);
    reverse(a.begin(), a.end());
    ans = max(ans, solve(a, b));
    cout<<ans<<'\n';
}