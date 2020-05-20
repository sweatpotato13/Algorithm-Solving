#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/10464
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while(t--){
        ll s,f;
        cin >> s >> f;
        bool sEven = !(s%2);
        bool fEven = !(f%2);
        ll ans;
        if(sEven && fEven){
            if((f-s+1) % 4 == 1){
                ans = f;
            }
            else{
                ans = f+1;
            }
        }
        else if(!sEven && fEven){
            if((f-s+1) % 4 == 0){
                ans = (s^f)-1;
            }
            else{
                ans = s^f;
            }
        }
        else if(sEven && !fEven){
            if((f-s+1) % 4 == 0){
                ans = 0;
            }
            else{
                ans = 1;
            }
        }
        else{
            if((f-s+1) % 4 == 1){
                ans = s;
            }
            else{
                ans = s-1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}