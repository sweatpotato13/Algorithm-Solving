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
// https://codeforces.com/contest/1560/problem/C
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    tc(n) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll s = max(a, b);
        ll e = min(a, b);
        ll dif = s - e - 1;
        ll end = s + dif - e + 1;
        if (end < s || end < e || end < c) {
            cout << -1 << "\n";
            continue;
        }
        if ((e + dif + 1) % end != s % end) {
            cout << -1 << "\n";
            continue;
        }
        ll ans = (c + end / 2) % end;
        if (ans == 0) ans = end;
        cout << ans << "\n";
    }

    return 0;
}