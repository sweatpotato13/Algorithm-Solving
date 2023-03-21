#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/4149
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
ll mod_pow(ll x, ll y, ll m){
    ll res = 1;
    x = x % m;
    while(y > 0){
        if(y & 1){
            res = (res * x) % m;
        }
        y = y >> 1;
        x = (x*x) % m;
    }
    return res;
}
ll pollard_rho(ll n, ll k){
    if(n == 1) return 1;
    if(n % 2 == 0) return 2;
    ll x = (rand()%(n-2))+2;
    ll y = x;
    ll c = (rand()%(n-1))+1;
    ll d = 1;
    ll idx = 0;
    while (d == 1 && idx < 70000)
    {
        idx++;
        x = (mod_pow(x, 2, n) + k) % n;
        y = (mod_pow(y, 2, n) + k) % n;
        y = (mod_pow(y, 2, n) + k) % n;
        d = gcd(abs(y - x), n);
    }
    if (d == n) return n;
    if (d == 1) return n;
    return d;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> v;
    ll n;
    cin >> n;
    for(int i = 3;i<=100000000;i+=2){
        while(n % i == 0){
            v.push_back(i);
            n/=i;
        }
        if(n == 1) break;
    }
    while(n>1){
        ll e = pollard_rho(n,17);
        v.push_back(e);
        n = n / e;
    }
    sort(all(v));
    for(int i = 0 ;i<v.size();i++){
        cout << v[i] << "\n";
    }
    return 0;
}
