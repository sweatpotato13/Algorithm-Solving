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
// https://atcoder.jp/contests/abc194/tasks/abc194_a
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b;
    cin >> a >> b;
    if(a+b >= 15 && b >= 8) cout << 1;
    else if(a+b >= 10 && b >= 3) cout << 2;
    else if(a+b >= 3) cout << 3;
    else cout << 4;

    return 0;
}
