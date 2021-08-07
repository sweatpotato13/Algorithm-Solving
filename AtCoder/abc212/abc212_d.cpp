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
// https://atcoder.jp/contests/abc212/tasks/abc212_d
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll q;
    cin >> q;
    priority_queue<ll, vll, greater<ll>> pq;
    ll sum = 0;
    ll x;
    while (q--) {
        ll p;
        cin >> p;
        if (p == 1) {
            cin >> x;
            pq.push(x - sum);
        } else if (p == 2) {
            cin >> x;
            sum += x;
        } else {
            x = pq.top();
            cout << x + sum << "\n";
            pq.pop();
        }
    }

    return 0;
}