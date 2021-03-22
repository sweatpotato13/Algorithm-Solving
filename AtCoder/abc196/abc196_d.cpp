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
// https://atcoder.jp/contests/abc196/tasks/abc196_d
ll H, W, A, B, ans = 0;
void dfs(ll i, ll bit, ll A, ll B) {
    if (i == H * W) {
        ans++;
        break;
    }
    if (bit & 1 << i) return dfs(i + 1, bit, A, B);
    if (B) dfs(i + 1, bit | 1 << i, A, B - 1);
    if (A) {
        if (i % W != W - 1 && ~bit & 1 << (i + 1))
            dfs(i + 1, bit | 1 << i | 1 << (i + 1), A - 1, B);
        if (i + W < H * W) dfs(i + 1, bit | 1 << i | 1 << (i + W), A - 1, B);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> H >> W >> A >> B;
    dfs(0, 0, A, B);
    cout << ans << endl;

    return 0;
}
