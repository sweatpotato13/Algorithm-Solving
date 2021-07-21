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
// https://atcoder.jp/contests/abc205/tasks/abc205_b
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    bool flag[1001] = {false,};
    rep(i,n){
        ll a;
        cin >> a;
        if(flag[a]){
            cout << "No" << endl;
            return 0;
        }
        else{
            flag[a] = true;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}