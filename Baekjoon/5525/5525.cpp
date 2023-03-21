#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://acmicpc.net/problem/5525
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans = 0;
	int n,m;
	string s;
	cin >> n >> m >> s;
	for(int i = 0;i<m;i++){
		if(s[i] == 'I' && s[i+1] == 'O'){
			int cnt = 0;
			while(s[i+1] == 'O' && s[i+2] == 'I'){
				i += 2;
				cnt++;
				if(cnt == n && s[i] == 'I'){
					ans++;
					cnt--;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}