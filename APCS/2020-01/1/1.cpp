#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

int rev(int n){
    if (n==2)   return 5;
    if (n==0)   return 2;
    if (n==5)   return 0;
    return -1;
}

int judge(int x, int y){    // 1: win, 2: lose, 3: draw
    if (y==rev(x))  return 1;
    if (x==rev(y))  return 2;
    return 3;
}

signed main(){
    nono_is_handsome

    int s;
    int n;
    cin >> s >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)    cin>>v[i];

    for(int i=1;i<=n;i++){
        int t = judge(s, v[i]);
        cout<<s<<" ";
        if (t==1){
            cout<<": Won at round "<<i<<"\n";
            return 0;
        }
        else if (t==2){
            cout<<": Lost at round "<<i<<"\n";
            return 0;
        }
        if (i>1 && v[i]==v[i-1]){
            s = rev(rev(v[i]));
        }
    }
    cout<<": Drew at round "<<n<<"\n";
    return 0;
}