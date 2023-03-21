#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/16287
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll w,n;
    cin >> w >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    vector<ll> ww(800000);
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(v[i] + v[j] > w)
                continue;
            if(ww[w-v[i]-v[j]]){
                cout << "YES";
                return 0;
            }
        }
        for(int j = 0;j<i;j++){
            if(v[i]+v[j] < w)
                ww[v[i]+v[j]]++;
        }
    }
    cout << "NO";


	return 0;
}
