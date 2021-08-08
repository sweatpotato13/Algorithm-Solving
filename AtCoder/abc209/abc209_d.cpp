#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc209/tasks/abc209_d
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;
    vll path[101010];
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        path[a-1].push_back(b-1);
        path[b-1].push_back(a-1);
    }
    queue<ll> que;
    vll dis(n, -1);
    que.push(0);
    dis[0] = 0;
    while (!que.empty()) {
        ll now = que.front();
        que.pop();
        for (auto next : path[now]) {
            if (dis[next] == -1) {
                dis[next] = dis[now] + 1;
                que.push(next);
            }
        }
    }
    rep(i, q) {
        ll c, d;
        cin >> c >> d;
        if (dis[c-1] % 2 == dis[d-1] % 2) cout << "Town" << endl;
        if (dis[c-1] % 2 != dis[d-1] % 2) cout << "Road" << endl;
    }

    return 0;
}