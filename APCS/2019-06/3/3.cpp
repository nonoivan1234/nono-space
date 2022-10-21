#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    int n, m, ans=0, v[50];
    string s;
    cin>>m>>n;
    unordered_map<int, int> mp;
    mp.clear();

    int mask = 0;
    for(int i=0;i<m;i++)    mask|=(1LL<<i);
    // cout<<mask<<endl;
    for(int i=0;i<n;i++){
        cin>>s;
        memset(v, 0, sizeof(v));
        int tmp;
        for(int j=0;j<s.size();j++){
            char c = s[j];
            if (c>='A' && c<='Z')   tmp = c-'A';
            else          tmp = c-'a'+26;
            v[tmp]=1;
        }
        int t=0;
        for(int j=0;j<m;j++){
            if (v[j])   t|=(1LL<<j);
        }
        mp[t]++;

        if (mp.count(t^mask)) ans+=mp[t^mask];
    }

    cout<<ans<<"\n";
}