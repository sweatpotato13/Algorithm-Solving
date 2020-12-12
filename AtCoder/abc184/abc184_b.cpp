#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc184/tasks/abc184_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,x;
    string s;
    cin >> n >> x;
    cin >> s;

    for(ll i = 0;i<n;i++){
        if(s[i] == 'x'){
            if(x != 0) x--;
        }
        else{
            x++;
        }
    }
    cout << x;
    
    return 0;
}