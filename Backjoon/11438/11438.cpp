#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/11438
ll par[100001][21], visited[100001], d[100001];
vector<vector<ll>> v;
void dfs(int here,int depth) {
    visited[here] = true;
    d[here] = depth;
    for (int there : v[here]) {
        if (visited[there])
            continue;
        par[there][0] = here;
        dfs(there, depth + 1);
    }
}
void f(ll n) {
    for (int j = 1; j < 21; j++) {
        for (int i = 1; i <= n; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}
int lca(int x, int y) {
    if (d[x] > d[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (d[y] - d[x] >= (1 << i)) 
            y = par[y][i];
    }
    if (x == y)return x;
    for (int i = 20; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll n;
	cin >> n;
	v.resize(n+1);
	for(int i = 0;i<n-1;i++){
		ll s,e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	dfs(1,0);
	f(n);
	ll m;
	cin >> m;
	for(int i = 0;i<m;i++){
		ll s,e;
		cin >> s >> e;
		cout << lca(s,e) << "\n";
	}

    return 0;
}