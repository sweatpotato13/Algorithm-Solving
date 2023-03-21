#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/2467
vector<int> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll ans[2] = {0,};
	int n;
	cin >> n;
	v.resize(n);
	for(int i = 0;i<n;i++){
		cin >> v[i];
	}
	sort(all(v));
	int l = 0;
	int h = v.size()-1;
	int temp = 2100000000;
	while(l < h){
		if(abs(v[l] + v[h]) < temp){
			temp = abs(v[l] + v[h]);
			ans[0] = v[l];
			ans[1] = v[h];
		}
		if(v[l]+v[h] < 0) l++;
		else h--;
	}
	cout << ans[0] << " " << ans[1];
	return 0;
}