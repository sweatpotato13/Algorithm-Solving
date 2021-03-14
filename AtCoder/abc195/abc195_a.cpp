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
// https://atcoder.jp/contests/abc195/tasks/abc195_a
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll m,h;
    cin >> m >> h;
    bool isAnswer = false;
    if(h % m == 0){
        isAnswer = true;
    }
    else isAnswer = false;
    if(isAnswer) cout << "Yes";
    else cout << "No";

    return 0;
}
