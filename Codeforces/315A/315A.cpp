#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://codeforces.com/problemset/problem/315/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(1001);
    for(int i = 0;i<n;i++){
        cin >> a[i] >> b[i];
        c[b[i]]++;
    }
    for(int i = 0;i<n;i++){
        c[b[i]]--;
        if(c[a[i]] == 0){
            ans++;
        }
        c[b[i]]++;
    }

    cout << ans << "\n";


	return 0;

}