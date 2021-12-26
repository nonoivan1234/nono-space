#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define N 200000

int w[N], t[N], r[N], l[N], prefixSum[N];

int main(){
    nono_is_handsome

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>l[i]>>r[i]>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    prefixSum[0] = t[0];
    for(int i=1;i<n;i++){
        prefixSum[i] = t[i]+prefixSum[i-1];
    }
    
    
}