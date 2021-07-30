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
// https://atcoder.jp/contests/abc210/tasks/abc210_c
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vll c(303030);
    map<ll, ll> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i <= k; i++) m[c[i]]++;
    ll ans = m.size();
    for (int i = k + 1; i <= n; i++) {
        m[c[i]]++;
        m[c[i - k]]--;
        if (m[c[i - k]] == 0) m.erase(c[i - k]);
        ans = max(ans, (ll)m.size());
    }
    cout << ans;

    return 0;
}