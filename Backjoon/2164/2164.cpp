#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/2164
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	bool isDrop = true;
	int n;
	cin >> n;
	queue<int> q;
	for(int i = 1;i<=n;i++)
		q.push(i);
	
	while(q.size() != 1){
		if(isDrop){
			q.pop();
		}
		else{
			int e = q.front();
			q.pop();
			q.push(e);
		}
		isDrop = !isDrop;
	}
	cout << q.front() << "\n";
	return 0;
}
