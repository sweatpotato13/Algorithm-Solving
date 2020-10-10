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
// https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_b
ll h,w;
ll dir[4][2] ={{0,1},{0,-1},{1,0},{-1,0}};
bool isAvailable(ll x, ll y){
    if(x >= 0 && y >= 0 && x < h && y < w) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    vector<string> v(h);
    rep(i,h){
        cin >> v[i];
    }
    ll ans = 0;
    rep(i,h){
        rep(j,w){
            if(v[i][j] == '.'){
                rep(k,4){
                    ll x = i+dir[k][0];
                    ll y = j+dir[k][1];
                    if(isAvailable(x,y) && v[x][y] == '.') ans++;
                }
            }
        }  
    }

    cout << ans/2;


    return 0;
}
