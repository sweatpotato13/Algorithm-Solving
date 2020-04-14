#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/15663
vector<int> arr;
int ans[8] = {0,};
bool isVisited[8] = {0,};
int n,m;
void solve(int cnt){
	if(cnt == m){
		for(int i = 0;i<cnt;i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	int prev = -1;
	for(int i = 0;i<n;i++){
		if(!isVisited[i] && prev != arr[i]){
			prev = arr[i];
			isVisited[i] = true;
			ans[cnt] = arr[i];
			solve(cnt+1);
			isVisited[i] = false;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	arr.resize(n);
	for(int i = 0;i<n;i++)
		cin >> arr[i];
	sort(all(arr));
	solve(0);


	return 0;
}