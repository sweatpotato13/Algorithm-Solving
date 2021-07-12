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
// https://atcoder.jp/contests/abc201/tasks/abc201_a
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vll a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(all(a));
    if(a[2] - a[1] == a[1] - a[0]) cout << "Yes";
    else cout << "No";

    return 0;
}
