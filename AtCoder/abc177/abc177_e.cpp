#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://atcoder.jp/contests/abc177/tasks/abc177_e
ll gcd(ll x, ll y){
    if(x < y) swap(x,y);
    if(y == 0) return x;
    else return gcd(y, x%y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ans[] ={"pairwise coprime","setwise coprime","not coprime"};
    ll n;
    cin >> n;
    vector<ll> v(1010101);
    vector<ll> num(1010101);
    ll g = 0;
    for(int i = 0;i<n;i++){
        cin >> v[i];
        g = gcd(g,v[i]);
        num[v[i]]++;
    }
    ll val = -1;
    int i;
    for(i = 2;i<=1000000;i++){
        ll x = 0;
        for(int j = i;j<=1000000;j+=i){
            x += num[j];
        }
        if(x >= 2)
            break;
    }
    if(i == 1000001) val = 0;
    else if(g == 1) val = 1;
    else val = 2;
    cout << ans[val];
    
    return 0;
}