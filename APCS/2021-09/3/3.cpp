#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 3e5+5;
int arr[N], pre[N];
vector<int> ind;

bool cmp(int a, int b){
    return arr[a]>arr[b];
}

signed main(){
    nono_is_handsome

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ind.push_back(i);
    }
    sort(ind.begin(), ind.end(), cmp);
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1]+arr[i];
    }
    int l=1, r=n, ans=0;
    while(r>l){
        while(ind.back()<l || ind.back()>r) ind.pop_back();
        if (ind.empty()) break;
        int id = ind.back();
        if (pre[id-1] - pre[l-1] > pre[r] - pre[id+1-1]){
            r = id-1;
        }
        else{
            l = id+1;
        }
    }
    cout<<arr[l]<<'\n';
}