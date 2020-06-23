#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// http://codeforces.com/problemset/problem/110/A
string ans[2] = {"NO", "YES"};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool isLucky = false;
    ll n;
    cin >> n;
    ll lucky = 0;
    while(n){
        ll temp = n%10;
        if(temp == 7 || temp == 4){
            lucky++;
        }
        n /= 10;
    }
    if(lucky == 7 || lucky == 4) {
        isLucky = true;
    }

    cout << ans[isLucky];

	return 0;
}