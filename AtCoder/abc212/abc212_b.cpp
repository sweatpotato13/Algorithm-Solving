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
// https://atcoder.jp/contests/abc212/tasks/abc212_b
char row[22] = {'0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5'};
bool isWeak(string s){
    if(s[0] == s[1] && s[1] == s[2]  && s[2] == s[3]) return true;
    ll idx = 0;
    rep(i,14){
        if(s[0] == row[i]){
            idx = i;
            break;
        }
    }
    rep(i,4){
        if(s[i] != row[idx+i]){
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    if(isWeak(s)) cout << "Weak";
    else cout << "Strong";

    return 0;
}