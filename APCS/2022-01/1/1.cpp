#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define MAXN 101

int main(){
    nono_is_handsome

    int n, d, buy=MAXN, sell=0, ans=0, a;
    cin>>n>>d;
    cin>>buy;   // buy at first price
    n--;    // already bought
    while(n--){
        cin>>a;
        if (a-buy>=d){  // price difference between a and buy >= d, than buy it
            ans+=a-buy;
            sell = a;   // set sell price to a
            buy = MAXN; // set buy price to MAXN
        }
        else if (sell-a>=d){    // price difference between sell and a >= d, than sell it
            buy = a;    // set buy price to a
            sell = 0;   // set sell price to 0
        }
    }
    cout<<ans<<"\n";
    return 0;
}