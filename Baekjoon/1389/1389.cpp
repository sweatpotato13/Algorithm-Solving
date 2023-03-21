#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://acmicpc.net/problem/1389
int link[101][101]={0,};
bool isVisited[101]={0,};
int connect[101]={0,};
int n,m;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void bfs(int node)
{
	isVisited[node] = true;
	queue<int> q;
	q.push(node);
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(int i = 1;i<=n;i++){
			if(link[curr][i] && !isVisited[i]){
				isVisited[i] = true;
				connect[i] = connect[curr]+1;
				q.push(i);
			}
		}
	}
	int sum = 0;
	for(int i = 1;i<=n;i++){
		sum += connect[i];
	}
	pq.push({sum,node});
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for(int i = 0;i<m;i++){
		int e,s;
		cin >> e >> s;
		link[e][s] = 1;
		link[s][e] = 1;
	}
	for(int i = 1;i<=n;i++){
		bfs(i);
		memset(isVisited,0,sizeof(isVisited));
		memset(connect, 0, sizeof(connect));
	}
	cout << pq.top().second << "\n";

	return 0;
}