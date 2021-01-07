#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://codeforces.com/problemset/problem/1360/A
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t;
	cin >> t;
	while(t--){
		ll ans = 0;
		ll e,s;
		cin >> e >> s;
		if(e > s) swap(e,s);
		if(e == s){
			ans = 4*e*e;
		}
		else{
			if(e <= s/2){
				ans = s*s;
			}
			else{
				ans = 4*e*e;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}