#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// http://codeforces.com/problemset/problem/32/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ans = "";
    string a;
    cin >> a;
    ll n = a.length();
    for(int i = 0;i<n;i++){
        if(a[i] == '.'){
            ans += '0';
        }
        else if(a[i] == '-'){
            if(a[i+1] == '.'){
                ans += '1';
            }
            else if(a[i+1] == '-'){
                ans += '2';
            }
            i++;
        }
    }
    cout << ans;

	return 0;
}