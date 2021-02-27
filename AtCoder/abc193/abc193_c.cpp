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
// https://atcoder.jp/contests/abc193/tasks/abc193_d
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> k;
    string s, t1;
    cin >> s >> t1;
    ll num[10] = {};
    rep(i, 10) num[i] = k;
    rep(i, 4) {
        ll a = s[i] - '0';
        ll b = t1[i] - '0';
        --num[a];
        --num[b];
    }
    vll t(10, 0), a(10, 0);
    rep(k, 4) {
        t[s[k] - '0']++;
        a[t1[k] - '0']++;
    }
    ld ans = 0;
    for (ll i = 1; i <= 9; i++) {
        auto ti = t;
        ti[i]++;
        ll sc_t = 0;
        for (ll l = 1; l <= 9; l++) {
            sc_t += l * pow(10, ti[l]);
        }
        for (ll j = 1; j <= 9; j++) {
            ll aj = a;
            aj[j]++;
            if (ti[i] + aj[i] > k) continue;
            if (ti[j] + aj[j] > k) continue;
            ll sc_a = 0;
            for (ll l = 1; l <= 9; l++) {
                sc_a += l * pow(10, aj[l]);
            }
            ld ch1 = num[i];
            ld ch2 = num[j];
            if (i == j) ch2--;
            if (sc_t > sc_a) ans += ch1 / (9 * k - 8) * ch2 / (9 * k - 9);
        }
    }
    cout << fixed;
    cout.precision(10);
    cout << ans;
    return 0;
}