#include<bits/stdc++.h>
using namespace std;
pair<int, int> p[1001];

bool cmp(pair<int, int> p1, pair<int, int> p2){
    return p1.second>p2.second;   // return greater value one
}

int main(){
    int n, m, total=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
    }
    sort(p, p+n, cmp);
    for(int i=0;i<n;i++){
        if(m>p[i].first){   // can take all of the mineral
            total+=p[i].first*p[i].second;
            m-=p[i].first;
        }
        else{
            total+=p[i].second*m;   // running out of backpack capacity
            break;
        }
    }
    cout<<total<<"\n";
    return 0;
}