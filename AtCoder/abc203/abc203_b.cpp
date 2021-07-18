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
// https://atcoder.jp/contests/abc203/tasks/abc203_b
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=k;j++){
            ans += i*100+j;
        }
    }
    cout << ans;

    return 0;
}