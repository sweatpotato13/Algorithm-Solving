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
// https://atcoder.jp/contests/abc185/tasks/abc185_b
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool isOk = true;
    ll n, m, t;
    cin >> n >> m >> t;
    ll tmp = 0, maxCap = n;
    rep(i, m)
    {
        ll a, b;
        cin >> a >> b;
        n -= a - tmp;
        if (n < 1) {
            cout << "No";
            return 0;
        }
        n = min(n + (b - a), maxCap);
        tmp = b;
    }
    n -= t - tmp;
    if (n < 1) {
        cout << "No";
        return 0;
    } else
        cout << "Yes";

    return 0;
}