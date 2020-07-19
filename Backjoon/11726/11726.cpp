#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/11726
ll dp[1001] ={0,1,2,3,0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll mod = 10007;
    for(int i = 4;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2])%mod;
    }
    cout << dp[n];
    return 0;
}
