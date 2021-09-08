#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc217/tasks/abc217_b
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<string,bool> m;
    rep(i,3){
        string s;
        cin >> s;
        m[s] = true;
    }
    if(!m["ABC"]) cout << "ABC";
    if(!m["ARC"]) cout << "ARC";
    if(!m["AGC"]) cout << "AGC";
    if(!m["AHC"]) cout << "AHC";

    return 0;
}