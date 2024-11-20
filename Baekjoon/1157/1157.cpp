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
// https://www.acmicpc.net/problem/1157
map<char, int> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    for (auto c : s) {
        if (c >= 'a') c -= 32;
        m[c]++;
    }

    ll max = 0;
    char ans;
    for (auto p : m) {
        if (p.second > max) {
            max = p.second;
            ans = p.first;
        } else if (p.second == max) {
            ans = '?';
        }
    }

    cout << ans;

    return 0;
}