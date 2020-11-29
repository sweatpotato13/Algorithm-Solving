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
// https://atcoder.jp/contests/abc183/tasks/abc183_c
ll n,m;
ll a[10][10] = {0,};
ll ans = 0;
ll isVisited[10] ={0,};
void dfs(int u , int cnt , int sum)
{
	if(cnt == n - 1)
	{
		sum += a[u][1];
		if(sum == m) ans ++ ;
		return ;
	}
	isVisited[u] = 1;
	repn(i , n)
	{
		if(isVisited[i]) continue ;
		isVisited[i] = 1;
		dfs(i , cnt + 1 , sum + a[u][i]);
		isVisited[i] = 0;
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
    cin >> n >> m;
    repn(i,n){
        repn(j,n){
            cin >> a[i][j];
        }
    }
    dfs(1,0,0);
    cout << ans;

	return 0;
}
