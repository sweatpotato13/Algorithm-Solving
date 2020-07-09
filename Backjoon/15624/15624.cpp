#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/15624
const ll mod = 1e9+7;
ll fibo[1000001]={0,1,1,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for(int i = 3;i<=n;i++){
        fibo[i] = (fibo[i-1] + fibo[i-2]) % mod;
    }
    cout << fibo[n];

	return 0;
}
