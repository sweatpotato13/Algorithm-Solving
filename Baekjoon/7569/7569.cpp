#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/7569
int boxes[100][100][100] = {0,};
int dir[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int m,n,h;
queue<pair<pair<int, int>, int>> q;
bool isTomatoEnd(){
	for(int i = 0;i<h;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(boxes[j][k][i] == 0) return false;
			}
		}
	}
	return true;
}
bool isAvailable(int x, int y, int z){
	if(x >= 0 && y >= 0 && z >= 0 && x < m && y < n && z < h)
		return true;
	else return false;
}
void bfs(){
	int ans = 0;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			int x,y,z;
			y = q.front().first.first;
			x = q.front().first.second;
			z = q.front().second;
			q.pop();
			for(int i = 0;i<6;i++){
				int dy = y + dir[i][0];
				int dx = x + dir[i][1];
				int dz = z + dir[i][2];

				if(isAvailable(dx,dy,dz)){
					if(boxes[dy][dx][dz] == 0){
						boxes[dy][dx][dz] = 1;
						q.push({{dy,dx},dz});
					}
				}
			}
			if(q.empty() && isTomatoEnd()){
				cout << ans << "\n";
				return;
			}
			else if(q.empty() && !isTomatoEnd()){
				cout << -1 << "\n";
				return;
			}
		}
		ans++;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> m >> n >> h;

	for(int i = 0;i<h;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				cin >> boxes[j][k][i];
				if(boxes[j][k][i] == 1){
					q.push({{j,k},i});
				}
			}
		}
	}
	
	if(isTomatoEnd()){
		cout << 0 << "\n";
	}
	else{
		bfs();
	}

	return 0;
}