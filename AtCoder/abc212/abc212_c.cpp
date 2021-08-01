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
// https://atcoder.jp/contests/abc212/tasks/abc212_c
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;
    vll a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    ll x=0, y = 0;
    ll ans = INT_MAX;
    while(x<n && y<m){
        ans = min(ans, abs(a[x]-b[y]));
        if(a[x] > b[y]) y++;
        else x++;
    }
    cout << ans;

    return 0;
}