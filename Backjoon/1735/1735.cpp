#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/1735
ll gcd(ll a, ll b){
    if(b == 0)
        return a;
    else 
        return gcd(b, a%b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll u1, u2, d1, d2;
    cin >> u1 >> d1 >> u2 >> d2;
    ll uans = u1 * d2 + u2 * d1;
    ll dans = d1 * d2;
    ll d = gcd(max(uans,dans), min(uans,dans));
    cout << uans / d << " " << dans / d;



	return 0;
}
