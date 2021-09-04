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
// https://www.acmicpc.net/problem/1562
ll mod = 1e9;
ll dp[101][10][1024];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    dp[1][0][1] = 0;
    dp[1][1][2] = 1;
    dp[1][2][4] = 1;
    dp[1][3][8] = 1;
    dp[1][4][16] = 1;
    dp[1][5][32] = 1;
    dp[1][6][64] = 1;
    dp[1][7][128] = 1;
    dp[1][8][256] = 1;
    dp[1][9][512] = 1;

    for (ll i = 2; i <= n; ++i) {
        for (ll cur = 0; cur <= 9; ++cur) {
            for (ll j = 0; j <= 1023; ++j) {
                if (cur == 0) {
                    dp[i][cur][j | (1 << cur)] =
                        (dp[i][cur][j | (1 << cur)] + dp[i - 1][cur + 1][j]) %
                        mod;
                } else if (cur == 9) {
                    dp[i][cur][j | (1 << cur)] =
                        (dp[i][cur][j | (1 << cur)] + dp[i - 1][cur - 1][j]) %
                        mod;
                } else {
                    dp[i][cur][j | (1 << cur)] =
                        (dp[i][cur][j | (1 << cur)] + dp[i - 1][cur + 1][j]) %
                        mod;
                    dp[i][cur][j | (1 << cur)] =
                        (dp[i][cur][j | (1 << cur)] + dp[i - 1][cur - 1][j]) %
                        mod;
                }
            }
        }
    }

    ll ans = 0;
    rep(i,10){
		ans = (ans + dp[n][i][1023]) % mod;
    }
    cout << ans;
    return 0;
}
