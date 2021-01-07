#pragma warning(disable : 4996)
#include <bits/stdc++.h>
extern "C" {
#include <quadmath.h>
}
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://codeforces.com/problemset/problem/1363/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ans[2] = {"No", "Yes"};
    ll t;
    cin >> t;
    while(t--){
        bool isPossible = false;
        ll odd = 0;
        ll even = 0;
        ll n,x;
        cin >> n >> x;
        vector<ll> v(n);
        for(int i = 0;i<n;i++){
            cin >> v[i];
            if(v[i] % 2 == 0) even++;
            else odd++;
        }
        if(odd == 0) isPossible = false;
        else if(n == x && odd % 2 == 0) isPossible = false;
        else if(x % 2 == 0 & even == 0) isPossible = false;
        else isPossible = true;
        cout << ans[isPossible] << "\n";
    }



	return 0;
}