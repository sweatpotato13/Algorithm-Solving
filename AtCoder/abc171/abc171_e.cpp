#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc171/tasks/abc171_e
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll xorSum = 0;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i]; 
        xorSum ^= a[i];
    }
    vector<ll> ans(n);
    for(int i = 0;i<n;i++){
        ll temp = xorSum ^ a[i];
        ans[i] = temp;
    }

    for(auto k : ans){
        cout << k << " ";
    }


	return 0;
}
