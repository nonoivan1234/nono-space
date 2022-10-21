#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 2e5+5;

int rec(vector<int> a, int l, int r){
    int n = a.size();
    if (n<3)    return 0;
    int mid = (l+r)/2;
    vector<int> small, big, between(N, 0);
    
    int ans=0, num=0;
    for(int i=0;i<n;i++){
        // cout<<a[i]<<" "<<num<<" "<<mid<<"\n";
        if (a[i]<=mid){
            small.push_back(a[i]);
            ans += num;
        }
        else{
            big.push_back(a[i]);
            if (between[a[i]]){
                between[a[i]]=0;
                num--;
            }
            else{
                between[a[i]]=1;
                num++;
            }
        }
    }
    return ans + rec(small, l, mid) + rec(big, mid+1, r);
}

signed main(){
    nono_is_handsome

    int n;
    cin>>n;
    vector<int> v(N);
    for(int i=0;i<2*n;i++)    cin>>v[i];

    cout<<rec(v, 1, n)<<"\n";
    return 0;
}