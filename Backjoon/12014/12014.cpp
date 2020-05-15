#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/12014
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll idx= 1;
    ll t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        vector<ll> v(n);
        vector<ll> dp;
        for(int i = 0;i<n;i++){
            cin >> v[i];
            if(dp.empty()) dp.push_back(v[i]);
            else{
                if(dp.back() < v[i]){
                    dp.push_back(v[i]);
                }
                else{
                    auto it = lower_bound(all(dp), v[i]);
                    *it = v[i];
                }
            }
        }
        cout << "Case #" << idx++ << "\n";
        if(dp.size() < k) cout << 0 << "\n";
        else cout << 1 << "\n";
    }
	return 0;
}
