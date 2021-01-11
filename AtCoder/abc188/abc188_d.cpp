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
// https://atcoder.jp/contests/abc188/tasks/abc188_d
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, C;
    cin >> N >> C;
    vll a(N), b(N), c(N);
    set<ll> s;
    map<ll, ll> changes;
    rep(i, N) {
        cin >> a[i] >> b[i] >> c[i];
        s.insert(a[i]), s.insert(b[i] + 1);
        changes[a[i]] += c[i];
        changes[b[i] + 1] -= c[i];
    }
    vll v(s.begin(), s.end());
    ll M = v.size();
    ll ans = 0, acc = 0;
    for (ll i = 0; i < M - 1; i++) {
        acc += changes[v[i]];
        ans += min(C, acc) * (v[i + 1] - v[i]);
    }
    cout << ans;

    return 0;
}