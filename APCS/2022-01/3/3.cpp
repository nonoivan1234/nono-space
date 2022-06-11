#include<bits/stdc++.h>
#define int long long
#define nono cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
const int N = 5e4;
signed main(){
	nono

	int m, ans=0;
	set<string> st;
	string s[N];
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>s[i];
		st.insert(s[i]);
	}

	for(int i=0;i<m;i++){
		int len = s[i].length();
		if (len<3)	continue;	// 長度不可能低於3
		for(int j=1;j<=len/2;j++){
			if (s[i].substr(0, j) == s[i].substr(len-j, j)){	// 尋找前後j個位的相同字串
				if (st.count(s[i].substr(j, len-j*2)) > 0){	// 如果中間的字串也在st中，就多一對合法字串
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}