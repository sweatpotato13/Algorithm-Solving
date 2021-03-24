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
// https://atcoder.jp/contests/abc194/tasks/abc194_c
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vll a(n);
    ll sum = 0;
    rep(i, n) { 
        cin >> a[i]; 
        sum += a[i];
    }
    ll ans = n;
    ll sqrsum = 0;
    rep(i, n) {
        ll temp = a[i] * a[i];
        sqrsum += temp;
    }
    ans *= sqrsum;
    ans -= sum * sum;
    cout << ans;

    return 0;
}
