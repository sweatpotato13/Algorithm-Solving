#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/1407
ll f(ll n){
    ll res = n;
    for(ll i=2;i<=n;i*=2) 
        res +=(n/i)*(i/2);
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a,b;
    cin >> a >> b;
    cout << f(b) - f(a-1);

	return 0;
}