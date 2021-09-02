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
// https://atcoder.jp/contests/abc216/tasks/abc216_e
vll a;
ll n, k;
ll ok(ll line) {
    ll cnt = 0;
    for (auto aa : a) {
        if (aa >= line) {
            cnt += aa - line;
        }
    }
    return cnt <= k;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    a.resize(n);
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = 0;
    if (sum <= k) {
        for (auto aa : a) {
            ans += (aa * (aa + 1)) / 2;
        }
        cout << ans;
        return 0;
    }

    ll bottom = 0;
    ll top = 2 * 1e9;
    while (top - bottom > 1) {
        ll mid = (top + bottom) / 2;
        if (ok(mid)) {
            top = mid;
        } else
            bottom = mid;
    }
    ll line = top;
    for (auto aa : a) {
        if (aa >= line) {
            k -= aa - line;
            ans += ((line + 1 + aa) * (aa - line)) / 2;
        }
    }
    ans += k * line;
    cout << ans;
    return 0;
}