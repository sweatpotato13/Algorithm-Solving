#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
#define PI 3.1415926535897
typedef long long int ll;
using namespace std;
// https://codeforces.com/problemset/problem/1354/C2
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        long double ans;
        ans = cos(PI/(4*n)) / sin(PI/(2*n));
        cout << fixed;
        cout.precision(9);
        cout << ans << "\n";
    }

	return 0;
}
