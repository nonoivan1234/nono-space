#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

struct boss{
    bool alive;
    int r, c, s, t;
};

signed main(){
    nono_is_handsome

    int n, m, k;
    cin >> n >> m >> k;
    vector<boss> v(k);
    int mp[n][m], cp[n][m];
    memset(mp, 0, sizeof(mp));
    memset(cp, 0, sizeof(cp));

    for(int i = 0; i < k; i++){
        v[i].alive=1;
        cin >> v[i].r >> v[i].c >> v[i].s >> v[i].t;
    }

    while(1){
        bool flag=0;
        for(int i=0;i<k;i++){
            if (v[i].alive){
                if (mp[v[i].r][v[i].c]==0){
                    cp[v[i].r][v[i].c]=1;
                    v[i].r+=v[i].s;
                    v[i].c+=v[i].t;
                    if (v[i].r<0 || v[i].r>=n || v[i].c<0 || v[i].c>=m){
                        v[i].alive=0;
                    }
                }
                else{
                    cp[v[i].r][v[i].c]=0;
                    v[i].alive=0;
                }
                flag=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i][j]=cp[i][j];
            }
        }
        if (!flag) break;
    }

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=mp[i][j];
        }
    }

    cout << ans << endl;

    return 0;
}