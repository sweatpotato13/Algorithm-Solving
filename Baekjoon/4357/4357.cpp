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
// https://www.acmicpc.net/problem/4357
ll p, b, n;
ll powmod(ll a, ll b) {
    ll res = 1;
    a = a % p;
    if (a == 0) return 0;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % p;
        }
        b = b >> 1;
        a = (a * a) % p;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while ((cin >> p >> b >> n)) {
        ll m = ceil(sqrt(p));
        set<ll> s;
        ll val = 1;
        for (int i = 0; i < m; i++) {
            s.insert(val);
            val *= b;
            val %= p;
        }
        bool flag = false;
        val = 1;
        for (int i = 0; i < m; i++) {
            if (s.find((n * val) % p) != s.end()) {
                ll temp = 1;
                for (int j = 0; j < m; j++) {
                    if (temp == (n * val) % p) {
                        cout << i * m + j << "\n";
                        flag = true;
                        break;
                    }
                    temp *= b;
                    temp %= p;
                }
                break;
            }
            val *= powmod(powmod(b, m), p - 2);
            val %= p;
        }
        if (!flag) {
            cout << "no solution\n";
        }
    }

    return 0;
}