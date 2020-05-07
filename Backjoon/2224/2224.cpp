#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/2224
int dp[70][70] ={0,};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll cnt = 0;
	ll n,m;
	cin >> n;
	for(int i = 0;i<n;i++){
		string a,b,c;
		cin >> a >> b >> c;
		if(a[0] == c[0]) continue;
		dp[a[0]-'A'][c[0]-'A'] = 1;
	}
    for(int i = 0;i<70;i++){
         for(int j = 0;j<70;j++){
            for(int k = 0;k<70;k++){
                if(dp[j][i] && dp[i][k]){                    
					dp[j][k] = 1;
				}
            }
        }   
    }
    for(int i = 0;i<70;i++){
         for(int j = 0;j<70;j++){
            if(dp[i][j] && i != j){                    
				cnt++;
			}
        }   
    }
	cout << cnt << "\n";
	for(int i = 0;i<70;i++){
		for(int j = 0;j<70;j++){
			if(dp[i][j] && i != j){
				char s = i+'A';
				char e = j+'A';
				cout << s << " => " << e << "\n";
			}
		}
	}

	return 0;
}