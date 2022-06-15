#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
typedef pair<int, int> pii;
vector<pii> v;
set<int> s;

bool cmp(pii p1, pii p2){
    if (p1.second != p2.second) return p1.second < p2.second;
    return p1.first < p2.first;
}

signed main(){
    nono_is_handsome

    int x, t, n, l;
    cin>>n>>l;
    s.insert(0);
    s.insert(l);
    for(int i=0;i<n;i++){
        cin>>x>>t;
        v.push_back({x, t});
    }
    sort(v.begin(), v.end(), cmp);
    int ans = 0;
    for(auto p: v){
        s.insert(p.first);
        auto it = s.lower_bound(p.first);
        ans += *next(it) - *prev(it);
    }
    cout<<ans<<'\n';
}