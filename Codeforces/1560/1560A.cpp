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
// https://codeforces.com/contest/1560/problem/A
bool is_pass(ll n){
    if(n % 3 == 0) return true;
    if(n % 10 == 3) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll a[1001] = {0};
    a[1] = 1;
    for(int i = 2;i<=1000;i++){
        ll val = a[i-1];
        val++;
        while(is_pass(val)) val++;
        a[i] = val;
    }
    tc(n){
        ll x;
        cin >> x;
        cout << a[x] << "\n";
    }

    return 0;
}