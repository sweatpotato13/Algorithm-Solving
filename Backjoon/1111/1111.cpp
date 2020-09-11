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
// https://www.acmicpc.net/problem/1111
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    vll v(n);
    ll x,y;
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    if(n == 1) cout << "A";
    else if(n == 2){
        if(v[0] == v[1]) cout << v[1];
        else cout << "A";
    }
    else{
        bool hasAnswer = true;
        ll a = 0, b = 0;
        ll x = v[1] - v[0];
        ll y = v[2] - v[1];
        if(x != 0) a = y/x;
        b = v[1] - a*v[0];
        for(int i = 1;i<n;i++){
            if(v[i] != (v[i-1] * a + b)){
                hasAnswer = false;
                break;
            }
        }
        if(hasAnswer) cout << v[n-1] * a + b;
        else cout << "B";
    }
    
    return 0;
}
