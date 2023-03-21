#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/2579
ll dp[301] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i = 1;i<=n;i++){
        cin >> v[i];
        if(i==1){
            dp[i] = v[i];
        }
        else if(i==2){
            dp[i] = v[i] + v[i-1];
        }
        else if(i == 3){
            dp[i] = max(v[i-1] + v[i], v[i-2]+v[i]);
        }
        else {
            dp[i] = max(dp[i-2] + v[i], dp[i-3]+v[i-1]+v[i]);
        }
    }
    cout << dp[n];

    return 0;
}
