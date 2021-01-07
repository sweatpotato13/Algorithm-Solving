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
// http://codeforces.com/problemset/problem/339/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ans = "";
    string s;
    map<ll, ll> m;
    cin >> s;
    for (auto k : s) {
        if (k != '+') {
            m[k - '0']++;
        }
    }
    for (auto k : m) {
        ll num = k.first;
        ll cnt = k.second;
        while(cnt--){
            ans += (num+'0');
            ans += '+';
        }
    }
    ans.pop_back();
    cout << ans;

    return 0;
}