#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/2436
ll gcd(ll x, ll y){
    if(y == 0)
        return x;
    else return gcd(y, x%y);
}
bool isCoPrime(ll x, ll y){
    if(x < y) swap(x,y);
    if(gcd(x,y) == 1) return true;
    else return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    ll x,y;
    cin >> x >> y;
    ll temp = y / x;
    ll a,b;
    ll mm = INT_MAX;
    for(ll i = 1;i*i<=temp;i++){
        if(temp % i == 0){
            ll aa = i;
            ll bb = temp/i;
            if(abs(aa-bb) < mm && isCoPrime(aa,bb)){
                mm = abs(aa-bb);
                a = aa * x;
                b = bb * x;
            }
        }
    }
    if(a > b) swap(a,b);
    cout << a << " " << b;

	return 0;
}
