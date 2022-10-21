#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    int win=0, lose=0;
    for(int i=0;i<2;i++){
        int p1=0, p2=0;
        for(int j=0;j<4;j++){
            int x; cin>>x;
            p1+=x;
        }
        for(int j=0;j<4;j++){
            int x; cin>>x;
            p2+=x;
        }
        if(p1>p2) win++;
        else if(p1<p2) lose++;
        cout<<p1<<":"<<p2<<endl;
    }
    if(win>lose) cout<<"Win"<<endl;
    else if(win<lose) cout<<"Lose"<<endl;
    else cout<<"Tie"<<endl;
}