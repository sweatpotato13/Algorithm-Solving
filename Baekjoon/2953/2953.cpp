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
// https://www.acmicpc.net/problem/2953
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ansa = 0;
    ll ansb = 0;
    for(int i = 0;i<5;i++){
        ll temp = 0;
        for(int j = 0;j<4;j++){
            ll e;
            cin >> e;
            temp += e;
        }
        if(temp > ansa){
            ansa = temp;
            ansb = i+1;
        }
    }
    cout << ansb << " " << ansa;

    return 0;
}
