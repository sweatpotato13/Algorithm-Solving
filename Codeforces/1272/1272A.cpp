#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://codeforces.com/contest/1272/problem/A
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll q;
	cin >> q;
	while(q--){
		vector<ll> v(3);
		cin >> v[0] >> v[1] >> v[2];
		sort(all(v));
		ll ans = (2 * v[2]) - (2 * v[0]);
		ans = ans - 4;
		if(ans < 0) ans = 0;
		cout << ans << "\n";
	}



	return 0;
}