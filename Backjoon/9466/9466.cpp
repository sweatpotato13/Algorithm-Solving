#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/9466
bool isVisited[100001] ={0,};
bool recur[100001] ={0,};
vector<int> v;
int cnt = 0;
void DFS(int i){
	isVisited[i] = true;
	int e = v[i];
	if(!isVisited[e]) DFS(e);
	else if(!recur[e]){
		for(int j = e;j != i;j=v[j])
			cnt++;
		cnt++;
	}
	recur[i] = true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		memset(isVisited,0,sizeof(isVisited));
		memset(recur,0,sizeof(recur));
		cnt = 0;
		int n;
		cin >> n;
		v.resize(n+1,0);
		for(int i = 1;i<=n;i++){
			 cin >> v[i];
		}
		for(int i = 1;i<=n;i++){
			if(!isVisited[i]) 
				DFS(i);
		}
		cout << n - cnt << "\n";
	}

	return 0;
}