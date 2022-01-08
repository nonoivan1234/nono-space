#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define N 200001
#define int long long

int w, r, l, load[N]={0}, t[N], total=0;

bool cmp(int i, int j){
    return i>j;
}

signed main(){
    nono_is_handsome

    int n,m;
    cin>>n>>m;

    for (int i=0;i<m;i++){
        cin>>l>>r>>w;
        load[l] += w;
        load[++r] -= w;
    }

    for (int i=1;i<=n;i++){
        load[i] += load[i-1];
    }

    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    sort(load, load+n+1, cmp);
    sort(t, t+n);
    
    for (int i=0;i<n;i++){
        total += t[i]*load[i];
    }

    cout<<total<<"\n";

    return 0;
}