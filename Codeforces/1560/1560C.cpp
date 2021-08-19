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
// https://codeforces.com/contest/1560/problem/C
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll a[31624] = {0};
    a[1] = 1;
    a[2] = 2;
    a[3] = 5;
    ll add = 5;
    for (int i = 4; i < 31624; i++) {
        a[i] = a[i - 1] + add;
        add += 2;
    }
    tc(n) {
        ll x;
        cin >> x;
        if (x == 1) {
            cout << "1 1\n";
            continue;
        }
        ll start = 0;
        for (int i = 1;; i++) {
            if (a[i] <= x && a[i + 1] > x) {
                start = i;
                break;
            }
        }
        if (x < a[start] + start - 1) {
            cout << x - a[start] + 1 << " " << start << "\n";
        } else if (x == a[start] + start - 1) {
            cout << start << " " << start << "\n";
        } else {
            cout << start << " " << start - x + a[start] + start - 1 << "\n";
        }
    }

    return 0;
}