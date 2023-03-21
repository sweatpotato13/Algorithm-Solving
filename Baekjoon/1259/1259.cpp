#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/1259
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string answer[2] = {"no","yes"};
	string s;
	while(getline(cin, s)){
		bool isAnswer = true;
		if(!s.compare("0")) break;
		int length = s.length();
		for(int i = 0;i<length/2;i++){
			if(s[i] != s[length-1-i]){
				isAnswer = false;
				break;
			}
		}
		cout << answer[isAnswer] << "\n";
	}
	

	return 0;

}