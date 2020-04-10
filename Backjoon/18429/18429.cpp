#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/18429
int n,k;
vector<int> v;
int value = 0;
int answer = 0;
int arr[8] = {0,1,2,3,4,5,6,7};
int ans[8] = {0,};
bool isVisited[8]={0,};
void solve(int cnt){
	if(value < 0) return;
	if(cnt == n){
		answer++;
	}
	for(int i =0;i<n;i++){
		if(!isVisited[i]){
			isVisited[i] = true;
			value += v[i];
			solve(cnt+1);
			value -= v[i];
			isVisited[i] = false;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	v.resize(n);
	for(int i = 0;i<n;i++){
		int e;
		cin >> e;
		v[i] = e - k;
	}
	solve(0);
	cout << answer << "\n";


	return 0;
}