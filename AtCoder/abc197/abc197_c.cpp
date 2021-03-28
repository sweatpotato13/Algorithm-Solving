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
// https://atcoder.jp/contests/abc194/tasks/abc197_c
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vll a(n);
    rep(i, n) { cin >> a[i]; }
    ll ans = INT_MAX;
    for (int i = 0; i < 1 << (n - 1); i++) {
        ll xor_ = 0;
        ll or_ = 0;
        for (int j = 0; j <= n; j++) {
            if (j < n) {
                or_ |= a[j];
            }
            if (j == n || (i >> j & 1)) {
                xor_ ^= or_ ;
                or_ = 0;
            }
        }
        ans = min(ans, xor_);
    }
    cout << ans;
    return 0;
}
