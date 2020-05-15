#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://codeforces.com/contest/1353/problem/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans = 0;
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);        
        vector<ll> b(n);
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        for(int i = 0;i<n;i++){
            cin >> b[i];
        }
        sort(all(a));
        sort(all(b));
        ll aIdx = 0;
        ll bIdx = n-1;
        while(k--){
            if(b[bIdx] > a[aIdx]){
                swap(b[bIdx], a[aIdx]);
                aIdx++;
                bIdx--;
            }
            else{
                break;
            }
        }
        for(int i = 0;i<n;i++){
            ans += a[i];
        }
        cout << ans << "\n";
    }

	return 0;
}
