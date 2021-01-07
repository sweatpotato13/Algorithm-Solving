#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://codeforces.com/problemset/problem/1360/E
string ans[2] = {"NO", "YES"};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t;
	cin >> t;
	while(t--){
		bool isAnswer = true;
		ll n;
		cin >> n;
		vector<ll> v[50];
		for(int i =0;i<n;i++){
			for(int j = 0;j<n;j++){
				char e;
				cin >> e;
				v[i].push_back(e-'0');
			}
		}
		for(int i = n-2;i>=0;i--){
			for(int j = n-2;j>=0;j--){
				if(v[i][j] && !v[i+1][j] && !v[i][j+1])
					isAnswer = false;
			}
		}

		cout << ans[isAnswer] << "\n";

	}

	return 0;
}