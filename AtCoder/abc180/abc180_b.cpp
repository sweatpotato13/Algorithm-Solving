#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc180/tasks/abc180_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	ll n;
	cin >> n;
	ll Manhattan = 0;
	ld Euclidian = 0;
	ll Chebyshev = 0;
	rep(i,n){
		ll e;
		cin >> e;
		e = abs(e);
		Manhattan += e;
		Chebyshev = max(Chebyshev, e);
		Euclidian += (e*e);
	}
	Euclidian = sqrt(Euclidian);
	cout << fixed;
	cout.precision(15);
	cout << Manhattan << "\n";
	cout << Euclidian << "\n";
	cout << Chebyshev << "\n";

	
}
