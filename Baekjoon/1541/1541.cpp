#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://acmicpc.net/problem/1541
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	bool isMinus = false;
	int ans = 0;
	string temp = "";
	string s;
	cin >> s;
	for(int i = 0;i<s.length();i++){
		if(s[i] != '+' && s[i] != '-'){
			temp += s[i];
		}
		else{
			if(isMinus){
				ans -= atoi(temp.c_str());
			}
			else{
				ans += atoi(temp.c_str());
			}
			if(s[i] == '-'){
				isMinus = true;
			}
			temp = "";
		}	
	}
	if(isMinus){
		ans -= atoi(temp.c_str());
	}
	else{
		ans += atoi(temp.c_str());
	}
	cout << ans << "\n";
	return 0;
}