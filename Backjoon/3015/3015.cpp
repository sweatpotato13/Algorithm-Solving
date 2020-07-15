#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/3015
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    stack<pll> s;
    ll ans = 0;
    for(int i = 0;i<n;i++){
        while(!s.empty() && s.top().first < v[i]){
            ans += s.top().second;
            s.pop();
        }
        if(s.empty()){
            s.push({v[i],1});
        }
        else{
            if(v[i] < s.top().first){
                s.push({v[i],1});
                ans += 1;
            }
            else if(v[i] == s.top().first){
                pll temp = s.top();
                s.pop();
                ans += temp.second;
                temp.second += 1;
                if(!s.empty()){
                    ans += 1;
                }
                s.push(temp);
            }
        }
    }
    cout << ans;


	return 0;
}
