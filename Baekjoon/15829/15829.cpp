#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/15829
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll r = 1;
	ll M = 1234567891;
	ll H = 0;
	int l;
	cin >> l;
	string s;
	cin >> s;
	for(int i = 0;i<l;i++){
		int e = s[i] - 'a' + 1;
		H += (e * r) % M;
		r = (r*31)%M;
	}
	cout << H << "\n";
	

	return 0;

}