#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/10253
ll gcd(ll a, ll b){
    if(a < b) swap(a,b);
    if(b == 0) return a;
    else return gcd(b, a%b);
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;   
        if(a != 1){
            do{
                ll cur = (b%a==0) ? b/a : b/a+1;
                a = a*cur-b;
                b = b * cur;
                ll g = gcd(a,b);
                a /= g;
                b /= g;
            }while(a != 1);
        }
        cout << b << "\n";
    }

    return 0;
}
