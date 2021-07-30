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
// https://atcoder.jp/contests/abc210/tasks/abc210_b
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    string s;
    cin >> n >> s;
    rep(i,n){
        if(s[i] == '1'){
            if(i % 2){
                cout << "Aoki";
            }
            else{
                cout << "Takahashi";
            }
            return 0;
        }
    }

    return 0;
}