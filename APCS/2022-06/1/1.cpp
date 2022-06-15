#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    int arr[10], p=0, s;
    memset(arr, 0, sizeof(arr));
    for(int i=0, t;i<3;i++){
        cin>>t;
        arr[t]++;
        p = max(p, arr[t]);
    }
    cout<<p<<' ';
    for(int i=9;i>=1;i--){
        if (arr[i]!=0){
            cout<<i<<' ';
        }
    }
    cout<<'\n';
}