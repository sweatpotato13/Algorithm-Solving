#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/15723
int dp[27][27] ={0,};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n,m;
	cin >> n;
	for(int i = 0;i<n;i++){
		string a,b,c;
		cin >> a >> b >> c;
		dp[a[0]-'a'][c[0]-'a'] = 1;
	}
    for(int i = 0;i<26;i++){
         for(int j = 0;j<26;j++){
            for(int k = 0;k<26;k++){
                if(dp[j][i] && dp[i][k])
                    dp[j][k] = 1;
            }
        }   
    }
	cin >> m;
	for(int i = 0;i<m;i++){
		string a,b,c;
		cin >> a >> b >> c;
		if(dp[a[0]-'a'][c[0]-'a'])
			cout << "T\n";
		else
			cout << "F\n";
	}

	return 0;
}