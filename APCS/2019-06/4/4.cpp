#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    int m, n;
    cin>>m>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];

    map<string, int> mp;
    int tmp=0, ans=0;
    for(int i=0;i<m;i++){
        if (!mp.count(v[i]) || mp[v[i]]==0)    tmp++, mp[v[i]]=1;
        else    mp[v[i]]++;
    }
    if (tmp==m) ans++;

    for(int i=m;i<n;i++){
        if (mp[v[i-m]]==1)  tmp--;
        mp[v[i-m]]--;
        if (mp[v[i]]==0)    tmp++;
        mp[v[i]]++;
        if (tmp==m) ans++;
    }

    cout<<ans<<"\n";
}