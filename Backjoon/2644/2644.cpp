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
// https://www.acmicpc.net/problem/2644
vll v[101];
bool isVisited[101] ={0,};
ll chon[101] = {0,};
ll n;
void bfs(ll x){
    queue<ll> q;
    isVisited[x] = true;
    q.push(x);
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(int i = 0;i<v[cur].size();i++){
            ll next = v[cur][i];
            if(!isVisited[next]){
                isVisited[next] = true;
                chon[next] = chon[cur]+1;
                q.push(next);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    ll a,b;
    cin >> a >> b;
    ll m;
    cin >> m;
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(a);
    if(chon[b]){
        cout << chon[b];
    }
    else cout << -1;

    return 0;
}
