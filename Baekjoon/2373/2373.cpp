#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://www.acmicpc.net/problem/2373
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll fibo[100] = { 0,};
    fibo[1] = fibo[2] = 1;
    for (int i = 3; i < 100; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    ll n;
    cin >> n;
	ll tempN = n;
	while (true) {
		ll temp = n; 
		for (int i = 1; i < 100; i++) {
			if (temp < fibo[i]) {
				temp = fibo[i - 1];
				break;
			}
		}
		if (temp == n) {
			break;
		}

		n -= temp;
	}
    if(n == tempN) cout << -1;
	else cout << n;
    
    return 0;
}