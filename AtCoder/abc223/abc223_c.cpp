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
#define X first
#define Y second
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc223/tasks/abc223_c
vector<pll> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ld> a(n), b(n);
    rep(i, n) { cin >> a[i] >> b[i]; }
    ld t = 0, ans = 0;
    rep(i, n) t += a[i] / b[i];
    t /= 2;
    rep(i, n) {
        ans += min(a[i], t * b[i]);
        t -= min(a[i] / b[i], t);
    }
    cout << fixed << setprecision(15);
    cout << ans << endl;

    return 0;
}