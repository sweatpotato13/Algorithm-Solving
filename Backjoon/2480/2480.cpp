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
// https://www.acmicpc.net/problem/2480
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;
    if (a == b && a == c && b == c) {
        cout << 10000 + a * 1000;
    } else if (a != b && b != c && a != c) {
        ll m = max(max(a, b), c);
        cout << m * 100;
    } else {
        ll s;
        if(a == b) s = a;
        if(a == c) s = a;
        if(b == c) s = b;
        cout << 1000 + s * 100;
    }

    return 0;
}