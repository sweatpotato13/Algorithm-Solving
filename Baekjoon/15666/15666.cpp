#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/15666
vector<int> arr;
int ans[8] = {0,};
int n,m;
void solve(int cnt, int idx){
	if(cnt == m){
		for(int i = 0;i<cnt;i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	int prev = -1;
	for(int i = idx;i<n;i++){
		if(prev != arr[i]){
			prev = arr[i];
			ans[cnt] = arr[i];
			solve(cnt+1,i);
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
	solve(0,0);


	return 0;
}