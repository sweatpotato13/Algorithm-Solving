#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/1322
ll x_2[65] ={0,};
ll k_2[65] ={0,};
ll y_2[65] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll cnt = 0;
    ll x,k;
    cin >> x >> k;
    for(ll i = 0;i<=64;i++){
        ll temp = x%2;
        x_2[i] = temp;
        x /= 2;
        if(x == 0) break;
    }
    for(ll i = 0;i<=64;i++){
        ll temp = k%2;
        k_2[i] = temp;
        k /= 2;
        if(k == 0) break;
    }
    ll idx = 0;
    for(int i = 0;i<=64;i++){
        if(x_2[i] == 0){
            y_2[i] = k_2[idx++];
        }
    }
    ll sqr = 1;
    for(int i = 0;i<=64;i++){
        ans += (sqr * y_2[i]);
        sqr *= 2;
    }
    cout << ans;
	return 0;
}