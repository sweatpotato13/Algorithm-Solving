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
// https://atcoder.jp/contests/abc180/tasks/abc180_c
vll v;
void getDivisors(ll n)
{
    for (ll i = 1; i*i <= n; i++) {
		if(i*i == n) v.push_back(i);
		else if(n % i == 0){
			v.push_back(i);
			v.push_back(n/i);
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	ll n;
	cin >> n;
	getDivisors(n);
	sort(all(v));
	for(auto k : v) cout << k << "\n";

	return 0;
}
