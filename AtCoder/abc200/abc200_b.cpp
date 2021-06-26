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
// https://atcoder.jp/contests/abc200/tasks/abc200_b
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    while(k--){
        if(n%200 == 0){
            n = n/200;
        }
        else{
            if(k >= 2){
                n = n*5+1;
                k--;
            }
            else{
                n = n*1000+200;
            }
        }
    }
    cout << n;
    return 0;
}
