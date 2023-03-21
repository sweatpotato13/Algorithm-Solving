#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/1992
string board[64];
string ans = "";
void solve(int x, int y, int size){
	if(size == 1){
		if(board[x][y] == '1') ans += "1";
		else ans += "0";
		return;
	}
	bool isChecked[2] = {0,};
	for(int i = x; i < x+size;i++){
		for(int j = y;j<y+size;j++){
			if(board[i][j] == '1'){
				isChecked[1] = true;
			}
			else{
				isChecked[0] = true;
			}
		}
	}
	if(isChecked[0] && !isChecked[1]){
		ans += "0";
	}
	else if(isChecked[1] && !isChecked[0]){
		ans += "1";
	}
	else{
		ans += "(";
		int next = size / 2;
		solve(x, y, next);
		solve(x, y + next, next);
		solve(x + next, y, next);
		solve(x + next, y + next, next);
		ans += ")";
	}

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> board[i];
	}

	solve(0, 0, n);
	cout << ans << "\n";

	return 0;
}