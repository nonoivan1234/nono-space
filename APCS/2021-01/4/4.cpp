#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
typedef pair<int, int> pii;

vector<pii> v;
vector<int> dp;

signed main(){
    nono_is_handsome

    int n, x, y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    for(int i=0;i<n;i++){
        int y = v[i].second;
        if (dp.empty() || y>=dp.back())   dp.push_back(y);
        else    dp[upper_bound(dp.begin(), dp.end(), y)-dp.begin()] = y;
    }

    cout<<dp.size()<<'\n';
}