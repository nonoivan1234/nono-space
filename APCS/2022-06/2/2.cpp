#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 105;
signed main(){
    nono_is_handsome

    int m, n;
    char e[N][N], s[N], t[N];
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>e[i];
    }
    cin>>s;
    for(int i=m;i>=1;i--){
        int I=0, l=0, r=n-1, ind;
        for(int j=0;j<n;j++){
            if (e[i][j]=='0'){
                t[l++] = s[I++];
            }
            else{
                t[r--] = s[I++];
            }
        }
        for(int j=0;j<n;j++){
            s[j] = t[j];
        }
        if (count(e[i], e[i]+n, '1')%2==1){
            I = 0;
            if (n%2==1) ind = n/2+1;
            else    ind = n/2;
            for(int j=ind;j<n;j++){
                t[I++] = s[j];
            }
            if (n%2==1)    t[I++] = s[n/2];
            for(int j=0;j<n/2;j++){
                t[I++] = s[j];
            }
            for(int j=0;j<n;j++){
                s[j] = t[j];
            }
        }
    }
    cout<<s<<'\n';
}