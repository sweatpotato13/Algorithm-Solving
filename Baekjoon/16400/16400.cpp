#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/17425
ll che[40001] ={0,};
ll dp[40001] = {0,};
vector<ll> p;
void getChe(ll num) {
    for (int i = 2; i <= num; i++) {
        che[i] = i;
    }
    for (int i = 2; i <= num; i++) { 
        if (che[i] == 0) 
            continue;
        for (int j = i + i; j <= num; j += i) {
            che[j] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll mod = 123456789;
    ll n;
    cin >> n;
    ll ans = 0;
    getChe(40000);
    for(int i = 2;i<=40000;i++){
        if(che[i] != 0)
            p.push_back(i);
    }
    dp[0] = 1;
    for(int i = 0;i<p.size();i++){
        for(int j = p[i];j<=n;j++){
            dp[j] = (dp[j] + dp[j-p[i]]) % mod;
            dp[j] %= mod;
        }
    }
    cout << dp[n];

	return 0;
}