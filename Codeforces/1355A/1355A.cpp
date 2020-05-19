#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://codeforces.com/problemset/problem/1355/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll a,k;
        cin >> a >> k;
        for(int i = 0;i<k-1;i++){
            vector<ll> v;
            ll temp = a;
            while(temp){
                v.push_back(temp%10);
                temp /= 10;
            }
            ll maxDigit = *max_element(all(v));
            ll minDigit = *min_element(all(v));
            if(minDigit == 0) break;
            else
                a = a + maxDigit * minDigit;
        }  
        cout << a << "\n";
    }
	return 0;
}
