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
#define X first
#define Y second
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://www.acmicpc.net/problem/1059
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll l;
    cin >> l;
    vll s(l);
    rep(i, l) { cin >> s[i]; }
    ll n;
    cin >> n;
    sort(all(s));
    ll hi = INT_MAX, lo = INT_MIN;
    for (int i = 0; i < l; i++) {
        if (s[i] >= n) hi = min(hi, s[i]-n);
        else lo = max(lo, s[i]-n);
    }
    if(hi != INT_MAX && lo != INT_MIN && hi != 0) cout << abs(hi*lo)-1;
    else if(lo == INT_MIN && hi != 0) cout << n * hi -1;
    else cout << 0;

    return 0;
}
