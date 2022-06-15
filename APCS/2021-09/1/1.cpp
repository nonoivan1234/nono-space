#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    int n, arr[2][7];
    cin>>n;
    while(n--){
        bool none = 1;
        for(int i=0;i<2;i++){
            for(int j=0;j<7;j++){
                cin>>arr[i][j];
            }
        }
        
        // case A
        for(int i=0;i<2;i++){
            if (arr[i][1]==arr[i][3] || arr[i][1]!=arr[i][5]){
                cout<<"A";
                none = 0;
                break;
            }
        }

        // case B
        if (arr[0][6]!=1 || arr[1][6]!=0){
            cout<<"B";
            none = 0;
        }

        // case C
        if (arr[0][1]==arr[1][1] || arr[0][3]==arr[1][3] || arr[0][5]==arr[1][5]){
            cout<<"C";
            none = 0;
        }

        // case None
        if (none){
            cout<<"None";
        }

        cout<<'\n';
    }
}