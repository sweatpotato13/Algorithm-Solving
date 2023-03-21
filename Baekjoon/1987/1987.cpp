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
// https://www.acmicpc.net/problem/1987
char board[21][21];
map<char, ll> m;
ll ans = 0;
ll dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll r, c;
void dfs(ll x, ll y, ll cnt) {
    ans = max(ans, cnt);
    rep(i, 4) {
        ll nx = x + dir[i][0];
        ll ny = y + dir[i][1];
        if (ny < 0 || ny >= c || nx < 0 || nx >= r) {
            continue;
        }
        char next = board[nx][ny];
        if (m[next]) {
            continue;
        }
        m[next] = 1;
        dfs(nx, ny, cnt + 1);
        m[next] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    rep(i, r) rep(j, c) cin >> board[i][j];
    m[board[0][0]] = 1;
    dfs(0, 0, 1);
    cout << ans;

    return 0;
}
