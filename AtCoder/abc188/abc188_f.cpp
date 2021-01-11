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
// https://atcoder.jp/contests/abc188/tasks/abc188_f
map<ll,ll> dp;
ll X,Y;
ll solve(ll y) {
	if(y==1) return abs(X-y);
	if(dp.count(y)) return dp[y];
	ll ans=INT64_MAX;
	if(y%2==0) {
		ans=min(abs(X-y),1+solve(y/2));
	}
	else {
		ans=min(abs(X-y),2+solve((y+1)/2));
		ans=min(ans,2+solve((y-1)/2));
	}
	return dp[y]=ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> X >> Y;
    ll ans = solve(Y);
    cout << ans;

    return 0;
}