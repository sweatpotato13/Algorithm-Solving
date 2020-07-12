#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/1431
bool cmp(pair<string,ll> a, pair<string,ll> b){
    if(a.first.size() != b.first.size()){
        return a.first.size() < b.first.size();
    }
    else if(a.second != b.second)
        return a.second < b.second;
    else{
        return a.first < b.first;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<pair<string,ll>> v(n);
    for(int i = 0;i<n;i++){
        string s;
        cin >> s;
        ll val = 0;
        for(int j = 0;j<s.length();j++){
            if(s[j] >= '0' && s[j] <= '9'){
                val += s[j]-'0';
            }
        }
        v[i] = {s,val};
    }
    sort(all(v),cmp);
    for(auto k : v){
        cout << k.first << "\n";
    }

    



	return 0;
}
