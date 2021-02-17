#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://www.acmicpc.net/problem/2410
ll dp[1010101] ={0,};
vll numbers;
ll mod = 1000000000;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i <<= 1) numbers.push_back(i);
    dp[0] = 1;
    for(int i = 0;i<numbers.size();i++){
        for(int j = numbers[i];j<=n;j++){
            dp[j] = (dp[j] + dp[j - numbers[i]]) % mod;
        }
    }

    cout << dp[n];

    return 0;
}
