#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/1780
int board[2200][2200]={0,};
int plusOne = 0;
int Zero = 0;
int minusOne = 0;
void check(int x, int y, int size){
	if(size == 1){
		if(board[x][y] == -1) minusOne++;
		if(board[x][y] == 0) Zero++;
		if(board[x][y] == 1) plusOne++;
		return;
	}
	bool isChecked[3] = {0,};
	for(int i = x;i<x+size;i++){
		for(int j = y;j<y+size;j++){
			if(board[i][j] == -1)
				isChecked[0] = true;
			if(board[i][j] == 0)
				isChecked[1] = true;
			if(board[i][j] == 1)
				isChecked[2] = true;
		}
	}
	if(isChecked[0] && !isChecked[1] && !isChecked[2]) minusOne++;
	else if(isChecked[1] && !isChecked[0] && !isChecked[2]) Zero++;
	else if(isChecked[2] && !isChecked[1] && !isChecked[0]) plusOne++;
	else{
		check(x, y, size / 3);
		check(x, y + size / 3, size / 3);
		check(x, y + (size / 3) * 2, size / 3);
		check(x + size / 3, y, size / 3);
		check(x + size / 3, y + size / 3, size / 3);
		check(x + size / 3, y + (size / 3) * 2, size / 3);
		check(x + (size / 3) * 2, y, size / 3);
		check(x + (size / 3) * 2, y + size / 3, size / 3);
		check(x + (size / 3) * 2, y + (size / 3) * 2, size / 3);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	 
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin >> board[i][j];
		}
	}

	check(0,0,n);

	cout << minusOne << "\n" << Zero << "\n" << plusOne << "\n";

	return 0;
}