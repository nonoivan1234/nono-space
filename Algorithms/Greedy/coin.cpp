#include<iostream>
using namespace std;

int main(){
    int n, cnt;
    int money[5]={500, 100, 50, 10, 1};
    int number[5]={1, 4, 8, 12, 50};
    cin>>n;
    for(int i=0;i<5;i++){
        cnt = 0;
        while(n>=money[i] && cnt<number[i]){
            n-=money[i];
            cnt++;
        }
        cout<<money[i]<<"->"<<cnt<<"\n";
        if (n==0)   break;
    }
    return 0;
}