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
// https://atcoder.jp/contests/abc216/tasks/abc216_a
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ld t;
    cin >> t;
    ll tt = (ll)(t * 10);
    ll x = tt / 10;
    ll y = tt % 10;
    if (y <= 2)
        cout << x << "-";
    else if (y <= 6)
        cout << x;
    else
        cout << x << "+";

    return 0;
}