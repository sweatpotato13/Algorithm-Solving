#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
int land[500][500] ={0,};
// https://www.acmicpc.net/problem/18111
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll max = -1;
	ll min = INT_MAX;
	ll answerTime = INT_MAX;
	ll height = -1;
	int n,m,b;
	cin >> n >> m >> b;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			int e;
			cin >> e;
			land[i][j] = e;
			if(max < e) max = e;
			if(min > e) min = e;
		}
	}
	for(int i = min; i<=max;i++){
		int make=0, remove = 0;
		for(int j=0;j<n;j++){
			for(int k = 0;k<m;k++){
				int e = land[j][k] - i;
				if(e < 0) make -= e;
				if(e > 0) remove += e;
			}
		}
		if(b - make + remove >= 0){
			int time = remove * 2 + make;
			if(answerTime >= time){
				height = i;
				answerTime = time;
			}
		}
	}
	cout << answerTime << " " << height << "\n";
	return 0;

}