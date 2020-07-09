#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/13241
ll gcd(ll a, ll b){
    if(b == 0) return a;
    else gcd(b, a%b);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a,b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a,b;
    cin >> a >> b;
    if(a < b) swap(a,b);
    cout << lcm(a,b);

	return 0;
}
