#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 55;
int arr[N][N], tmp[N][N];
signed main(){
    nono_is_handsome

    int r, c, k, m;
    cin>>r>>c>>k>>m;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
            tmp[i][j] = arr[i][j];
        }
    }
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    while(m--){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int num = arr[i][j]/k;
                for(int d=0;d<4;d++){
                    int x = i+dir[d][0], y = j+dir[d][1];
                    if(x>=0 && x<r && y>=0 && y<c && arr[x][y]!=-1){
                        tmp[x][y] += num;
                        tmp[i][j] -= num;
                    }
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                arr[i][j] = tmp[i][j];
            }
        }
    }
    int mx = -100, mn = 100;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            // cout<<arr[i][j]<<" \n"[j==c-1];
            if (arr[i][j]!=-1){
                mx = max(mx, arr[i][j]);
                mn = min(mn, arr[i][j]);    
            }
        }
    }
    cout<<mn<<endl;
    cout<<mx<<endl;
}