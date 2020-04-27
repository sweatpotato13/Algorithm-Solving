#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/13977
ll dpFacto[4000001] = {0,1,};
ll dpInv[4000001] = {0,};
#define MOD 1000000007
ll modInverse(ll a, ll m) { 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) { 
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 

    return x; 
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	cin >> m;
	for(int i = 2;i<=4000000;i++){
		dpFacto[i] = (dpFacto[i-1] * i) % MOD;
	}
	dpInv[4000000] = modInverse(dpFacto[4000000],MOD);
	for(int i = 3999999;i>=0;i--){
		dpInv[i] = (dpInv[i+1] * (i+1)) % MOD;
	}
	ll ans;
	while(m--){
		int n,k;
		cin >> n >> k;
		ans = (((dpFacto[n] * dpInv[k]) % MOD) * dpInv[n-k]) % MOD;
		cout << ans << "\n";
	}
	return 0;
}