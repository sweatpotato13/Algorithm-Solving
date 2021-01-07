#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
using namespace std;
// https://codeforces.com/problemset/problem/1354/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a <= b){
            cout << b << "\n";
        }
        else if(a > b && c <= d){
            cout << -1 << "\n";
        }
        else{
            ll temp = ceil((double)(a-b)/(c-d)) * c;
            cout << b + temp << "\n";
        }
    }


	return 0;
}
