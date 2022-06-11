#include<bits/stdc++.h>
#define int long long
#define nono cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
signed main(){
	nono

	int n, k, r=0, l=0;
	cin>>n>>k;
	vector<int> h(n), w(k);
	for(int i=0;i<n;i++){
		cin>>h[i];
		r = max(r, h[i]);
	}
	r++;
	for(int i=0;i<k;i++){
		cin>>w[i];
	}

	while(r-l>1){
		int mid = l + (r-l)/2;
		int cnt=0, ind=0, flag=0;
		for(int i=0;i<n;i++){
			if (h[i]>=mid){
				cnt++;
				if (cnt>=w[ind]){
					cnt-=w[ind];
					if (ind==k-1){
						flag = 1;
						break;
					}
					ind++;
				}
			}
			else	cnt=0;
		}
		if (flag)	l=mid;
		else	r=mid;
	}
	cout<<l<<endl;
	return 0;
}