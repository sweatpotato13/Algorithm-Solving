#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://codeforces.com/problemset/problem/1360/C
string ans[2] ={"NO" , "YES"};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t;
	cin >> t;
	while(t--){
		bool isAnswer = false;
		ll evenC = 0;
		ll oddC = 0;
		ll oneC = 0;
		ll n;
		cin >> n;
		vector<ll> v(n);
		for(int i = 0;i<n;i++){
			cin >> v[i];
			if(v[i]%2)	oddC++;
			else evenC++;
		}
		sort(all(v));
		for(int i = 1;i<=n;i++){
			if(v[i] - v[i-1] == 1 && v[i]%2 != v[i-1]%2)
				oneC++;
		}
		if(oddC%2 == 0 && evenC%2 == 0){
			isAnswer = true;
		}
		else if(oddC%2 == 1 && evenC%2 == 1 && oneC){
			isAnswer = true;
		}
		cout << ans[isAnswer] << "\n";
	}

	return 0;
}