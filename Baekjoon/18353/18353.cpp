#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
using namespace std;
// https://www.acmicpc.net/problem/18353
vector<ll> v;
vector<ll> dp;
ll upper(ll a){
    for(int i = 1;i<dp.size();i++){
        if(dp[i] < a && dp[i-1] > a){
            return i;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    v.resize(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
        if(dp.empty()) dp.push_back(v[i]);
        else{
            if(dp.back() > v[i]){
                dp.push_back(v[i]);
            }
            else{
                ll it = upper(v[i]);
                dp[it] = v[i];
            }
        }
    }
    cout << n - dp.size() << "\n";
	return 0;
}