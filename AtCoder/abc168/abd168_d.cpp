#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://atcoder.jp/contests/abc168/tasks/abc168_d
string ans[2] = {"No", "Yes"};
bool isVisited[200001] ={0,};
vector<ll> v[200001];
vector<ll> r(200001);
ll cnt = 0;
void BFS(ll start){
	queue<ll> q;
	q.push(start);
	isVisited[start] = true;
	while(!q.empty()){
		ll e = q.front();
		q.pop();
		for(int i = 0;i<v[e].size();i++){
			if(!isVisited[v[e][i]]){
				isVisited[v[e][i]] = true;
				q.push(v[e][i]);
				r[v[e][i]] = e;
			}
		}
	}
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll n,m;
	cin >> n >> m;
	for(int i = 0;i<m;i++){
		ll s,e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	BFS(1);
	cout<<"Yes\n";
	for(int j = 2; j <= n; j++) 
		cout<<r[j]<<'\n';
    return 0;
}