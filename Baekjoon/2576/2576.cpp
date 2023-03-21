#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/2576
vector<int> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 7;
	int s = 0;
	while(n--){
		int e;
		cin >> e;
		if(e%2){
			s += e;
			v.push_back(e);
		}
	}
	sort(all(v));
	int m;
	if(v.empty()) 
		cout << -1;
	else 
		cout << s << "\n" << v[0];
	return 0;
}