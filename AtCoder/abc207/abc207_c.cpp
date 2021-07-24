#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc207/tasks/abc207_c
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vld l(n), r(n);
    rep(i, n) {
        ll t;
        cin >> t >> l[i] >> r[i];
        t--;
        if (t & 1) r[i] -= -0.5;
        if (t & 2) l[i] += 0.5;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            ans += (max(l[i], l[j]) <= min(r[i], r[j]));
        }
    }
    cout << ans;

    return 0;
}