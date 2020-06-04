#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// http://codeforces.com/problemset/problem/467/C
ll dp[5001][5001] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> v(n+1);
    vector<ll> vSum(n+1);
    for(int i = 1;i<=n;i++){
        cin >> v[i];
        vSum[i] = vSum[i-1] + v[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i* m > j) dp[i][j] = 0;
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-m]+vSum[j]-vSum[j-m]);
            }
        }
    }

    cout << dp[k][n];

	return 0;

}