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
// https://atcoder.jp/contests/abc195/tasks/abc195_b
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, w;
    cin >> a >> b >> w;
    w *= 1000;
    bool flag = true;
    ll min = ceill((ld)w / b);
    if (w / min < a) flag = false;
    ll max = w / a;
    if (w / max > b) flag = false;
    if (flag)
        cout << min << " " << max;
    else
        cout << "UNSATISFIABLE";

    return 0;
}
