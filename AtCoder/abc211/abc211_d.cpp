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
// https://atcoder.jp/contests/abc211/tasks/abc211_d
vll v[202020];
ll mod = 1e9 + 7;
ll n,m;
ll isVisited[202020]={0,};
ll ans[202020] = {0,};
void bfs(ll start){
    queue<ll> q;
    q.push(start);
    isVisited[start] = 0;
    while(!q.empty()){
        ll now = q.front();
        q.pop();
        for(ll next:v[now]){
            if(isVisited[next] == 0){
                isVisited[next] = isVisited[now] + 1;
                q.push(next);
                ans[next] = ans[now];
            }
            else if(isVisited[next] == isVisited[now] + 1){
                ans[next] += ans[now];
                ans[next] %= mod;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ans[1] = 1;
    bfs(1);
    cout << ans[n];

    return 0;
}