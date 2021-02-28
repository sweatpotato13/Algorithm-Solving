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
// https://atcoder.jp/contests/abc192/tasks/abc192_d
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string x;
    ll m;
    cin >> x >> m;
    if (x.size() == 1) {
        if (stoi(x) <= m)
            cout << 1;
        else
            cout << 0;
        return 0;
    }

    ll d = 0;
    for (auto k : x) d = max(d, ll(k - '0'));
    ll ac = d, wa = m + 1;
    while (ac + 1 < wa) { 
        ll wj = (ac + wa) / 2;
        ll v = 0;
        for (auto k : x) {
            if (v > m / wj)
                v = m + 1;
            else
                v = v * wj + (k - '0');
        }
        if (v <= m)
            ac = wj;
        else
            wa = wj;
    }
    cout << ac - d << endl;

    return 0;
}
