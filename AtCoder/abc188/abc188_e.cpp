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
// https://atcoder.jp/contests/abc188/tasks/abc188_e
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    vll A(N);
    rep(i, N)
        cin >> A[i];

    vector<vll> graph(N);
    rep(i, M){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].emplace_back(v);
    }

    vll B(N, INT64_MAX);
    rep(v, N){
        for (auto u : graph[v]) {
            if (B[v] != INT64_MAX) B[u] = min(B[u], B[v]);
            B[u] = min(B[u], A[v]);
        }
    }

    ll ans = INT64_MIN;
    rep(i, B.size()){
        ans = max(ans, A[i] - B[i]);
    }
    cout << ans;

    return 0;
}