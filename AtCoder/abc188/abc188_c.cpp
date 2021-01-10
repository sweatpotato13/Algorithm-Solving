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
// https://atcoder.jp/contests/abc188/tasks/abc188_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vll a(pow(2,n));
    for(int i = 0;i<pow(2,n);i++){
        cin >> a[i];
    }
    ll max1 = 0, max2 = 0;
    ll idx1 = 0, idx2 = 0;
    for(int i = 0;i<a.size()/2;i++){
        if(max1 < a[i]){
            max1 = a[i];
            idx1 = i+1;
        }
    }
    for(int i = a.size()/2;i<a.size();i++){
        if(max2 < a[i]){
            max2 = a[i];
            idx2 = i+1;
        }
    }
    if(max1 > max2) cout << idx2;
    else cout << idx1;

    return 0;
}