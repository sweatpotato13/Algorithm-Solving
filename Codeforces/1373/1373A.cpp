#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://codeforces.com/problemset/problem/1373/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a < c) cout << 1 << " ";
        else cout << -1 << " ";
        if(a*b > c) cout << b << "\n";
        else cout << -1 << "\n";
    }
    
	return 0;
}