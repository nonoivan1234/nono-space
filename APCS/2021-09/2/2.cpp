#include<bits/stdc++.h> // not finished
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 105;
const int K = 505;
int arr[N][N];  // 1 bomb
int r[K], c[K], s[K], t[K];
int n, m, k;

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" \n"[j==m-1];
        }
    }
}

signed main(){
    nono_is_handsome

    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        cin>>r[i]>>c[i]>>s[i]>>t[i];
    }
    memset(arr, 0, sizeof arr);
    int cnt=k;
    while(k){
        for(int i=0;i<k;i++){
            print();
            if (r[i]==-1)   continue;
        }
    }
    // int ans = 0;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if (arr[i][j]==1){
    //             ans++;
    //         }
    //     }
    // }
    // cout<<ans<<'\n';
}