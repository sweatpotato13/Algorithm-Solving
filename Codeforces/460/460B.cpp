#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://codeforces.com/problemset/problem/460/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll cnt = 0;
    vector<ll> ans;
    ll a,b,c;
    cin >> a >> b >> c;
    for(int i = 1;i<=81;i++){
        ll sxa = 1;
        for(int k = 0;k<a;k++){
            sxa *= i;
        }
        ll temp = b * sxa + c;
        if(temp > 1e9) break;
        ll j = temp;
        ll digitS = 0;
        while(j > 0){
            digitS += j % 10;
            j /= 10;
        }
        if(digitS == i){
            cnt++;
            ans.push_back(temp);
        }
    }

    cout << cnt << "\n";
    for(auto k : ans){
        cout << k << " ";
    }

	return 0;

}