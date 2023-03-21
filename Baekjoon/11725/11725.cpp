#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/11725
vector<ll> tree[100001];
ll ans[100001] = {0,};
bool isVisited[100001] = {0,};
void DFS(ll n){
	isVisited[n] = true;
	for(int i = 0;i<tree[n].size();i++){
		ll e = tree[n][i];
		if(isVisited[e] == false){
			ans[e] = n;
			DFS(e);
		}
	}	
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll n;
	cin >> n;
	for(int i = 0;i<n-1;i++){
		ll e,s;
		cin >> e >> s;
		tree[e].push_back(s);
		tree[s].push_back(e);
	}
	DFS(1);
	for(int i = 2;i<=n;i++){
		cout << ans[i] << "\n";
	}

    return 0;
}