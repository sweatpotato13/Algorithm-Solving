#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
//https://www.acmicpc.net/problem/1168
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	
	for(int i = 0;i<n;i++)
		v[i] = i;
	
	int idx = 0;
	cout << "<";
	while(v.size() != 1){
		idx += k-1;
		if(idx >= v.size())
			idx %= v.size();
		cout << v[idx]+1 << ", ";
		v.erase(v.begin() + idx);
	}
	cout << v[0]+1 << ">\n";
	return 0;
}