#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/16409
ll mobius[10000010]={0,};
ll solve(ll x, ll y){
    ll val = 0;
    for(int i = 1;i<=min(x,y);i++){
        val += (x/i) * (y/i) * mobius[i];
    }
    return val;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(ll i = 1;i<=10000000;i++){	//u(1) = 1
		mobius[i] = 1;
	}
	for(ll i = 2;i*i<=10000000;i++){
		if(mobius[i] == 1){
			for(int j = i;j<=10000000;j+=i){
				mobius[j] *= -i;
			}
			for(int j = i*i;j<=10000000;j += i*i){
				mobius[j] = 0;
			}
		}
	}
	for(ll i = 2;i<=10000000;i++){
		if(mobius[i] == i){
			mobius[i] = 1;
		}
		else if(mobius[i] == -i){
			mobius[i] = -1;
		}
		else if(mobius[i] > 0){
			mobius[i] = -1;
		}
		else if(mobius[i] < 0){
			mobius[i] = 1;
		}
	}

    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    ans = solve(b,d) - solve(a-1,d) - solve(b,c-1) + solve(a-1,c-1);
    cout << ans;

	return 0;
}
