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
// https://www.acmicpc.net/problem/13294
ld stirling(ll n){
    return n * log10(n) - n / log(10);
}
ld diff(ll n){
    return stirling(n) - stirling(1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string n;
    cin >> n;
    ll len = n.length()-1;
    map<string,ll> ma;
    ma["1"] = 1;
    ma["2"] = 2;
    ma["6"] = 3;
    ma["24"] = 4;
    ma["120"] = 5;
    if(ma[n] != 0){
        cout << ma[n];
        return 0;
    }
    if(len < 100){
        ld r = log10(120);
        ll idx = 5;
        while(true){
            idx++;
            r += log10(idx);
            if((ll)r == len){
                cout << idx;
                return 0;
            }
        }
    }

    ll l = 0;
    ll h = 230000;
    while(l +1 < h){
        ll m = (l+h)/2;
        if((ll)diff(m) <= len)
            l = m;
        else h = m;
    }
    cout << l;

    return 0;
}
