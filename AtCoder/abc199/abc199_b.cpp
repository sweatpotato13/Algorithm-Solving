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
// https://atcoder.jp/contests/abc199/tasks/abc199_b
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vll a(n);
    vll b(n);
    ll maxA=-1, minB=1010;
    rep(i,n){
        cin >> a[i];
        maxA = max(maxA,a[i]);
    }
    rep(i,n){
        cin >> b[i];
        minB = min(minB,b[i]);
    }
    ll ans = minB - maxA + 1;
    if(ans <= 0) cout << 0;
    else cout << ans;

    return 0;
}
