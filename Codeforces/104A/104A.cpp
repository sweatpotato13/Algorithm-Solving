#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://codeforces.com/problemset/problem/104/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll ans = 0;
    if(n <= 10) ans = 0;
    else if(n <= 19) ans = 4;
    else if(n == 20) ans = 15;
    else if(n == 21) ans = 4;
    else ans = 0;
    
    cout << ans;

	return 0;

}