#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
const int INF = 1e6;

int solve(vector<int> a, vector<int> b){
    int n = a.size(), m = b.size();

    int ans=-INF;
    for(int i=-m;i<n;i++){  // 枚舉a的起點
        int sum=0;
        for(int j=0;j<m;j++){
            if (i+j<0 || i+j>=n)    continue;
            sum += a[i+j]*b[j];
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
    }

    return ans;
}

int main(){
    nono_is_handsome

    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<m;i++)    cin>>b[i];


    int ans=solve(a, b);
    reverse(a.begin(), a.end());
    ans = max(ans, solve(a, b));
    
    cout<<ans<<'\n';
}