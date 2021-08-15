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
// https://atcoder.jp/contests/abc214/tasks/abc214_b
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll s,t;
    cin >> s >> t;
    ll ans = 0;
    for(int i = 0;i<=100;i++){
        for(int j = 0;j<=100-i;j++){
            for(int k = 0;k<=100-i-j;k++){
                if(i+j+k <= s && i*j*k <= t){
                    ans++;
                }
            }
        }
    }
    cout << ans;

    return 0;
}