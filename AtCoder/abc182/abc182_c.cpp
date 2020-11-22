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
// https://atcoder.jp/contests/abc182/tasks/abc182_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;
    ll len = n.length();
    ll val=0, one=0, two=0;
    for(auto k : n){
        ll temp = k - '0';
        val += temp;
        if(temp % 3 == 1) one++;
        else if(temp % 3 == 2) two++;
    }
    val = val % 3;
    if(val == 0) cout << 0;
    else if((val == 1 && one > 0 && len > 1) || (val == 2 && two > 0 && len > 1)) cout << 1;
    else if((val == 1 && two > 1 && len > 2) || (val == 2 && one > 1 && len > 2)) cout << 2;
    else cout << -1;

    return 0;
}