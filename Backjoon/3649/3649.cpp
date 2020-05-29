#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/3649
vector<ll> v;
string ansStr[2] = {"danger", "yes"};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll target = 10000000;
    while(true){
        bool existAnswer = false;
        vector<ll> ans(2);
        ll x,n;
        cin >> x >> n;
        if(cin.eof()) break;
        vector<ll> v(n);
        for(int i = 0;i<n;i++)
            cin >> v[i];
        sort(all(v));
        if(n < 2){
            cout << ansStr[existAnswer] << "\n";
            continue;
        }
        ll l = 0;
        ll r = n-1;
        while(l < r){
            if(v[l] + v[r] == x * target){
                ans[0] = v[l];
                ans[1] = v[r];
                l++;
                r--;
                existAnswer =true;
                break;
            }
            else if(v[l] + v[r] < x * target){
                l++;
            }
            else{
                r--;
            }
        }
        if(existAnswer){
            cout << ansStr[existAnswer] << " " << ans[0] << " " << ans[1] << "\n";
        }
        else{
            cout << ansStr[existAnswer] << "\n";
        }
    }

    return 0;
}