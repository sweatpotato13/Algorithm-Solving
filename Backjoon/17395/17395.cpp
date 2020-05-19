#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/17395
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x,n;
    cin >> x >> n;
    vector<ll> v;
    map<ll,ll> m;
    vector<ll> ans;
    ll temp = x;
    while(x){
        v.push_back(x%2);
        m[x%2]++;
        x /= 2;
    }
    if(m[1] < n)
        cout << -1 << "\n";
    else{
        for(int i = 0;i<n-1;i++){
            while(v.back() == 0){
                v.pop_back();
            }
            temp -= pow(2,v.size()-1);
            v.pop_back();
            ans.push_back(temp);
        }
        ans.push_back(0);
    }
    for(auto k : ans){
        cout << k << " ";
    }
	return 0;
}
