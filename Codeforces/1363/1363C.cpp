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
// https://codeforces.com/problemset/problem/1363/C
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n,x;
        cin >> n >> x;
        vector<ll> degree(n+1);
        for(int i = 0;i<n-1;i++){
            ll s,e;
            cin >> s >> e;
            degree[s]++;
            degree[e]++;
        }
        if(degree[x] <= 1){
            cout << "Ayush" << "\n";
        }
        else{
            if(n % 2 == 0) cout << "Ayush" << "\n";
            else cout << "Ashish" << "\n";
        }
    }

	return 0;
}