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
// https://atcoder.jp/contests/abc213/tasks/abc213_d
vll path[202020];
bool isVisited[202020] = {0};
void dfs(ll start) {
    isVisited[start] = true;
    cout << start << " ";
    for (auto k : path[start]) {
        if (!isVisited[k]) {
            isVisited[k] = true;
            dfs(k);
            cout << start << " ";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    for (ll i = 0; i <= n; i++) {
        sort(all(path[i]));
    }
    dfs(1);

    return 0;
}