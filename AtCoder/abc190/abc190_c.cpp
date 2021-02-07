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
// https://atcoder.jp/contests/abc190/tasks/abc190_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    vll a(m), b(m);
    rep(i,m) cin >> a[i] >> b[i];
    ll k;
    cin >> k;
    vll c(k), d(k);
    rep(i,k) cin >> c[i] >> d[i];
    ll ans = 0;
    ll k2 = 1 << k;
    for (int i = 0 ; i < k2; i++) {
        vector<int> dish(n + 1);
        for (int s = 0; s < k; s++) {
            if (i >> s & 1) {

                dish[c[s]]++;
            } else {
                dish[d[s]]++;
            }
        }
        ll now = 0;
        for (int i = 0; i < m; i++) {
            if (dish[a[i]] == 0) continue;
            if (dish[b[i]] == 0) continue;
            now++;
        }
        ans = max(ans, now);
    }
 
    cout << ans;

    return 0;
}