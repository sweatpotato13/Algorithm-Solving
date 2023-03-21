#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/1748
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i *= 10){
		ans += n - i + 1;
	}
	cout << ans << "\n";

	return 0;
}