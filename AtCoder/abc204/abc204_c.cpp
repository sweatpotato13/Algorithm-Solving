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
// https://atcoder.jp/contests/abc204/tasks/abc204_c
vector<vll> road;
bool isVisited[2020] = {0,};
void dfs(ll v){
    if(isVisited[v]) return;
    isVisited[v]=true;
    for(auto k : road[v]){
        dfs(k);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;
    road.resize(n);
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        road[a-1].push_back(b-1);
    }
    ll ans = 0;
    rep(i,n){
        rep(j,n){
            isVisited[j] = false;
        }
        dfs(i);
        rep(j,n){
            if(isVisited[j]) ans++;
        }
    }
    cout << ans;
    
    return 0;
}