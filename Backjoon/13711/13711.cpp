#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/13711
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> b(n+1);
    vector<ll> dp;
    for(int i = 1;i<=n;i++){
        ll e;
        cin >> e;
        a[e] = i;
    }
    for(int i = 1;i<=n;i++){
        cin >> b[i];
    }
    for(int i = 1;i<=n;i++){
        if(dp.empty()) dp.push_back(a[b[i]]);
        else{
            if(dp.back() < a[b[i]]){
                dp.push_back(a[b[i]]);
            }
            else{
                auto it = lower_bound(all(dp), a[b[i]]);
                *it = a[b[i]];
            }
        }
    }
    cout << dp.size() << "\n";

	return 0;
}
