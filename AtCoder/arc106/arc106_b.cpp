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
// https://atcoder.jp/contests/arc106/tasks/arc106_b
ll n, m;
vector<ll> adj[202020];
bool isVisited[202020] = {0,};
vector<ll> a(202020);
vector<ll> b(202020);
ll sa = 0;
ll sb = 0;
void dfs(ll n){
    if(!isVisited[n]){
        isVisited[n] = true;
        sa += a[n];
        sb += b[n];
        for(auto k : adj[n]){
            dfs(k);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, m){
        ll s, e;
        cin >> s >> e;
        s--;
        e--;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    rep(i,n){
        if(!isVisited[i]){
            sa = 0;
            sb = 0;
            dfs(i);
            if(sa != sb) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}
