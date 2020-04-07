#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/1032
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<string> v(n);
	string answer = "";
	for(int i = 0;i<n;i++){
		cin >> v[i];
	}
	int length = v[0].length();
	for(int i = 0;i<length;i++){
		bool isSame = true;
		char ch = v[0][i];
		for(int j=0;j<n;j++){
			if(ch != v[j][i]){
				isSame = false;
				break;
			}
		}
		if(isSame)
			answer += ch;
		else
			answer += "?";
	}
	cout << answer << "\n";

	return 0;
}