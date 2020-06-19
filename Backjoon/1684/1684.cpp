#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/1684
ll gcd(ll a, ll b) { 
    ll temp;
    if(a < b){
        temp = a;
        a = b;
        b = temp;
    }
   if (b == 0) 
      return a; 
   else return gcd(b, a%b); 
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> p;
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(all(v));
    for(int i = 1;i<n;i++){
        p.push_back(v[i]-v[i-1]);
    }
    ans = p[0];
    for(auto k : p){
        ans = gcd(ans,k);
    }
    cout << ans;
    
	return 0;
}