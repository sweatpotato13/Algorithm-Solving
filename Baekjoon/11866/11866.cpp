#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
bool isAlive[1001] ={0,};
// https://www.acmicpc.net/problem/11866
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	memset(isAlive,1,sizeof(isAlive));
	vector<int> v(n);
	int idx = 0;
	int count = k;
	for(int i = 0;idx!=n;i++){
		i = i % n;
		if(isAlive[i]){
			if(count != 1)
				count--;
			else if(count == 1){
				isAlive[i] = false;
				v[idx] = i;
				idx++;
				count = k;
			}
		}
	}
	cout << "<";
	for(int i = 0;i<n-1;i++){
		cout << v[i]+1 << ", ";
	}
	cout << v[n-1]+1 <<">\n";

	return 0;
}