#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
int arr[101][101], passby[101][101], proce_max=0, end_max=0, m,n;

struct node{
    int x, y;
} nd[101][101];

// line=1 dot=2

int area_cnt(){
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if (arr[i][j] != 0) cnt++;
        }
    }
    return cnt;
}

void add(int r, int c){
    int index_up=r-1, index_down=r+1, index_left=c-1, index_right=c+1;
    arr[r][c] = 2;
    // up
    while(index_up>=-1){
        if (index_up==-1){
            index_up=r;
            break;
        }
        if(arr[index_up][c]==2)    break;
        index_up--;
    }
    // down
    while(index_down<=m){
        if (index_down==m){
            index_down=r;
            break;
        }
        if(arr[index_down][c]==2)    break;
        index_down++;
    }
    // left
    while(index_left>=-1){
        if (index_left==-1){
            index_left=c;
            break;
        }
        if(arr[r][index_left]==2)    break;
        index_left--;
    }
    // down
    while(index_right<=n){
        if (index_right==n){
            index_right=c;
            break;
        }
        if(arr[r][index_right]==2)    break;
        index_right++;
    }
    for(int i=index_up+1;i<index_down;i++){
        if (i==r)   continue;
        nd[i][c].y = 1;
        arr[i][c] = 1;
    }
    for(int i=index_left+1;i<index_right;i++){
        if (i==c)   continue;
        nd[r][i].x = 1;
        arr[r][i] = 1;
    }

}

void remove(int r, int c){
    int index_up=r-1, index_down=r+1, index_left=c-1, index_right=c+1;
    arr[r][c] = 0;
    // up
    while(index_up>=-1){
        if (index_up==-1){
            index_up=r;
            break;
        }
        if(arr[index_up][c]==2)    break;
        index_up--;
    }
    // down
    while(index_down<=m){
        if (index_down==m){
            index_down=r;
            break;
        }
        if(arr[index_down][c]==2)    break;
        index_down++;
    }
    // left
    while(index_left>=-1){
        if (index_left==-1){
            index_left=c;
            break;
        }
        if(arr[r][index_left]==2)    break;
        index_left--;
    }
    // down
    while(index_right<=n){
        if (index_right==n){
            index_right=c;
            break;
        }
        if(arr[r][index_right]==2)    break;
        index_right++;
    }
    for(int i=index_up+1;i<index_down;i++){
        nd[i][c].y = 0;
        if (nd[i][c].x==0 && nd[i][c].y==0) arr[i][c] = 0;
    }
    for(int i=index_left+1;i<index_right;i++){
        nd[r][i].x = 0;
        if (nd[r][i].x==0 && nd[r][i].y==0) arr[r][i] = 0;
    }
}

int main(){
    nono_is_handsome
 
    int h,r,c,t;
    cin>>m>>n>>h;
    while(h--){
        cin>>r>>c>>t;
        if (t==0)   add(r, c);
        else if (t==1)  remove(r, c);
        proce_max = max(area_cnt(), proce_max);
    }
    end_max = area_cnt();
    cout<<proce_max<<"\n"<<end_max;
}