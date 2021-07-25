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
// https://atcoder.jp/contests/abc208/tasks/abc208_c
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vll a(n), ans(n), order(n);
    rep(i, n) { cin >> a[i]; }
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&](int i, int j) { return a[i] < a[j]; });
    if (k >= n) {
        ll t = k / n;
        rep(i, n) {
            ans[i] = t;
            k -= t;
        }
    }
    rep(i, k % n) { ans[order[i]]++; }
    rep(i, n) cout << ans[i] << '\n';

    return 0;
}