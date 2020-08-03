#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://atcoder.jp/contests/abc174/tasks/abc174_c
ll gcd(ll a, ll b){
    if(a < b) swap(a,b);
    if(b == 0)
        return a;
    else return gcd(b, a%b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k;
    cin >> k;
    if(k%7 == 0){
        k /= 7;
    }
    if(gcd(10,k) != 1){
        cout << -1;
    }
    else{
        ll temp = 1 % k;
        ll ans = 1;
        while(temp != 0){
            temp = (10 * temp + 1) % k;
            ans++;
        }
        cout << ans;
    }

    return 0; 
}