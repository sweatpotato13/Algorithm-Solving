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
// https://www.acmicpc.net/problem/2583
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
bool isVisited[101][101] = {0,};
vll ans;
ll m,n,k;
ll dfs(ll x, ll y){
    ll cnt = 1;
    isVisited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        ll nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if (!isVisited[nx][ny]) cnt += dfs(nx, ny);
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> k;
    rep(i,k){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        for(int x = a;x<c;x++){
            for(int y = b;y<d;y++){
                isVisited[y][x] = true;
            }
        }
    }

    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(!isVisited[i][j]){
                ans.push_back(dfs(i,j));
            }
        }
    }

    sort(all(ans));
    cout << ans.size() << "\n";
    for(int i = 0;i<ans.size();i++){
        cout << ans[i] << ' ';
    }
    
    return 0;
}
