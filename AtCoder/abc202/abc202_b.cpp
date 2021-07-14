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
// https://atcoder.jp/contests/abc202/tasks/abc202_b
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for(ll i = s.length()-1;i>=0;i--){
        if(s[i] == '6') cout << 9;
        else if(s[i] == '9') cout << 6;
        else cout << s[i];
    }

    return 0;
}