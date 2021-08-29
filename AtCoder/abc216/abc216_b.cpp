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
// https://atcoder.jp/contests/abc216/tasks/abc216_b
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<string> s(n);
    vector<string> t(n);
    vector<string> name(n);
    rep(i, n) {
        cin >> s[i] >> t[i];
        name[i] = s[i] + " " + t[i];
    }
    sort(all(name));
    for (int i = 1; i < n; i++) {
        if (name[i] == name[i - 1]) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

    return 0;
}