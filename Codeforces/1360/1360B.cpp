#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://codeforces.com/problemset/problem/1360/B
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t;
	cin >> t;
	while(t--){
		ll ans = 1e9;
		ll n;
		cin >> n;
		vector<ll> v(n);
		for(int i = 0;i<n;i++){
			cin >> v[i];
		}
		sort(all(v));
		for(int i = 1;i<n;i++){
			ans = min(v[i] - v[i-1], ans);
		}
		cout << ans << "\n";
	}

	return 0;
}