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
// https://atcoder.jp/contests/abc204/tasks/abc204_a
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x,y;
    cin >> x >> y;
    bool flag[3] = {0,};
    flag[x] = true;
    flag[y] = true;
    if(x == y) cout << x;
    if(x != y){
        for(ll i = 0;i<3;i++){
            if(!flag[i]){
                cout << i;
                break;
            }
        }
    }


    return 0;
}