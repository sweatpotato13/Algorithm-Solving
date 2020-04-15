#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
//https://www.acmicpc.net/problem/11728
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
	vector<int> C(n+m);
	for(int i = 0;i<n+m;i++)
		cin >> C[i];
	sort(all(C));
	for(int i = 0;i<C.size();i++){
		cout << C[i] << " ";
	}
	cout << "\n";

	return 0;
}