#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/1701
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    ll ans = 0;
	for (int p = 0; p < s.size(); p++) {
		ll fail[5001] = { 0 };
		for (int i = 1,j=0; i < s.size()-p; i++) {
			while (j > 0 && s[p + i] != s[p+j])
				j = fail[j - 1];
			if (s[p + i] == s[p+j]) {
				fail[i] = ++j;
				ans = max(ans, fail[i]);
			}
		}
	}
    cout << ans;

    return 0;
}
