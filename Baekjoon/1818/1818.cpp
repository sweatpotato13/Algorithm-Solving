#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/1818
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
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
    cout << n - dp.size() << "\n";

	return 0;
}
