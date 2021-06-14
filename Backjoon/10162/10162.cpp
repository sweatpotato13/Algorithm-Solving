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
// https://www.acmicpc.net/problem/10162
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll count[3] = {0};
    ll t;
    cin >> t;

    count[0] = t / 300;
    t -= count[0] * 300;

    count[1] = t / 60;
    t -= count[1] * 60;

    count[2] = t / 10;
    t -= count[2] * 10;

    if (t == 0) {
        cout << count[0] << " " << count[1] << " " << count[2];
    } else {
        cout << -1;
    }

    return 0;
}
