#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 2e5+5;
const int M = 1e5+5;
typedef pair<int, int> pii;
vector<pii> e, v[M];
vector<int> now[N];
int color[N];
int n, m, x, y, p, k;

bool dfs(int x, int pre){
    for(int i:now[x]){
        if (i== pre)    continue;
        if (!color[i]){
            color[i] = 3-color[x];
            if (!dfs(i, x))    return false;
        }
        else if (color[i]==color[x])    return false;
    }
    return true;
}

bool check(int x){
    for(int i=1;i<=n;i++){
        color[i] = 0;
        now[i].clear();
    }
    for(pii i:e){
        now[i.first].push_back(i.second);
        now[i.second].push_back(i.first);
    }
    for(int i=1;i<=x;i++){
        for(pii j:v[i]){
            now[j.first].push_back(j.second);
            now[j.second].push_back(j.first);
        }
    }
    for(int i=1;i<=n;i++){
        if (!color[i]){
            color[i] = 1;
            if (!dfs(i, 0))    return false;
        }
    }
    return true;
}

signed main(){
    nono_is_handsome

    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        x++, y++;
        e.push_back({x, y});
    }
    cin>>p>>k;
    for(int i=1;i<=p;i++){
        for(int j=0;j<k;j++){
            cin>>x>>y;
            x++, y++;
            v[i].push_back({x, y});
        }
    }
    int l=0, r=p;
    for(int i=0;i<3;i++){
        while(r-l>1){
            int mid = (l+r)>>1;
            if (check(mid))    l = mid;
            else    r = mid;
        }
        cout<<r<<'\n';
        v[r].clear();
        l = r;
        r = p;
        if (check(p))   break;
    }
}