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
// https://www.acmicpc.net/problem/1289
ll mod = 1e9 + 7;
vector<pll> adj[101010];
ll ans = 0;
ll solve(ll v, ll b) {
    ll now = 1;
    for (auto i : adj[v])
        if (i.first != b) {
            ll t = solve(i.first, v) * i.second % mod;
            ans += now * t % mod;
            ans %= mod;
            now += t;
            now %= mod;
        }
    return now;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    solve(1, 0);
    cout << ans;

    return 0;
}