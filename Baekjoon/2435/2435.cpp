#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/2435
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    ll ans = INT_MIN;
    ll l = 0;
    ll r = k-1;
    ll temp = 0;
    for(int i = 0;i<=r;i++){
        temp += v[i]; 
    }
    ans = max(ans, temp);
    r++;
    while(r<n){
        temp -= v[l++];
        temp += v[r++];
        ans = max(ans,temp);
    }
    cout << ans;



	return 0;
}
