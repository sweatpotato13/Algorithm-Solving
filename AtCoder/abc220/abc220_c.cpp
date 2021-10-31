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
// https://atcoder.jp/contests/abc220/tasks/abc220_c
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    ll x;
    cin >> x;
    ll sum = 0;
    for (ll val : a) sum += val;
    ll p = x / sum;
    ll sumb = p * sum;
    ll ans = p * n;
    for (ll val : a) {
        sumb += val;
        ans++;
        if (sumb > x) {
            cout << ans ;
            return 0;
        }
    }

    return 0;
}
