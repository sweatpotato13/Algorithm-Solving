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
// https://atcoder.jp/contests/abc194/tasks/abc197_b
ll h, w, x, y;
vector<string> s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w >> x >> y;
    s.resize(h);
    rep(i, h) { cin >> s[i]; }
    ll ans = -3;
    x--;
    y--;
    for (ll i = x; i < h && s[i][y] != '#'; i++) ans++;
    for (ll i = x; i >= 0 && s[i][y] != '#'; i--) ans++;
    for (ll j = y; j < w && s[x][j] != '#'; j++) ans++;
    for (ll j = y; j >= 0 && s[x][j] != '#'; j--) ans++;

    cout << ans;

    return 0;
}
