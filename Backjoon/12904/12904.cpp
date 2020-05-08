#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/12904
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	bool isChecked = false;
	string s,t;
	cin >> s >> t;
	queue<string> q;
	q.push(t);
	while(!q.empty()){
		string temp = q.front();
		q.pop();
		if(!temp.compare(s)){
			isChecked = true;
			break;
		}
		if(temp.length() > s.length()){
			string next = "";
			if(temp[temp.length()-1] == 'A'){
				next = temp.substr(0,temp.length()-1);
				q.push(next);
			}
			if(temp[temp.length()-1] == 'B'){
				next = temp.substr(0,temp.length()-1);
				reverse(all(next));
				q.push(next);
			}
		}
	}

	if(isChecked)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";

	return 0;
}