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
// https://atcoder.jp/contests/abl/tasks/abl_c
vector<ll> v[101010];
bool isVisited[101010] ={0,};
ll cnt = 0;
void dfs(ll x){
    isVisited[x] = 1;
    for(auto k : v[x]){
        if(isVisited[k] == 0){
            dfs(k);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    repn(i,n){
        if(isVisited[i] == 0){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt-1;

    return 0;
}
