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
// https://www.acmicpc.net/problem/1212
string bit[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
string initBit[8] = {"", "1", "10", "11", "100", "101", "110", "111"};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    string ans = "";
    bool isInit = true;
    if(s == "0"){
        cout << s;
        return 0;
    }
    for (auto k : s) {
        if (isInit) {
            cout << initBit[k - '0'];
            isInit = false;
        } else
            cout << bit[k - '0'];
    }

    return 0;
}
