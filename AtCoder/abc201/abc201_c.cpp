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
// https://atcoder.jp/contests/abc201/tasks/abc201_c
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    ll ans = 0;
    for (ll i = 0; i <= 9999; i++) {
        vector<bool> flag(10);
        ll X = i;
        for (ll j = 0; j < 4; j++) {
            flag[X % 10] = true;
            X /= 10;
        }
        bool flag2 = true;
        for (ll j = 0; j < 10; j++) {
            if (s[j] == 'o' && !flag[j]) flag2 = false;
            if (s[j] == 'x' && flag[j]) flag2 = false;
        }
        ans += flag2;
    }
    cout << ans;

    return 0;
}