#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/1188
ll gcd(ll a, ll b){
    if(a < b) swap(a,b);
    if(b == 0) return a;
    else return gcd(b, a%b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n,m;
    cin >> n >> m;
    ll ans = m - gcd(n,m);
    cout << ans;


    return 0;
}
