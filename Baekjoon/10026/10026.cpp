#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/10026
bool isVisited[100][100] ={0,};
char board[100][100] ={0,};
char dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int answer_a = 0;
int answer_b = 0;
int n;
bool isAvailable(int x, int y){
	if(x >= 0 && y >= 0 && x < n && y < n)
		return true;
	else
		return false;
}
char isRG(char ch){
	if(ch == 'B') return ch;
	else return 'R';
}
void BFSbr(int x, int y, char ch){
	queue<pair<int,int>> q;
	q.push({x,y});

	isVisited[x][y] = true;
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i = 0;i<4;i++){
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if(!isVisited[xx][yy] && isAvailable(xx,yy) && isRG(board[xx][yy]) == isRG(ch)){
				q.push({xx,yy});
				isVisited[xx][yy] = true;
			}
		}
	}
}
void BFS(int x, int y, char ch){
	queue<pair<int,int>> q;
	q.push({x,y});

	isVisited[x][y] = true;
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i = 0;i<4;i++){
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if(!isVisited[xx][yy] && isAvailable(xx,yy) && board[xx][yy] == ch){
				q.push({xx,yy});
				isVisited[xx][yy] = true;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin >> board[i][j];
		}
	}

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(!isVisited[i][j]){
				BFS(i,j,board[i][j]);
				answer_a++;
			}
		}
	}
	memset(isVisited,0,sizeof(isVisited));
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(!isVisited[i][j]){
				BFSbr(i,j,board[i][j]);
				answer_b++;
			}
		}
	}
	cout << answer_a << " " << answer_b << "\n";
	return 0;
}