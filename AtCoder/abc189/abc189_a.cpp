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
// https://atcoder.jp/contests/abc189/tasks/abc189_a
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char s[3];
    rep(i,3) cin >> s[i];
    if(s[0] == s[1] && s[1] == s[2]) 
        cout << "Won";
    else
        cout << "Lost";

    return 0;
}