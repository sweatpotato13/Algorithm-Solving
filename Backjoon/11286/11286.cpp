#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/11286
bool cmp(ll a, ll b){
    if(abs(a) < abs(b)){
        return true;
    }
    else if(abs(a) == abs(b)){
        if(a < b) return true;
        else false;
    }
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    priority_queue<ll> minus, plus;
    while(n--){
        ll x;
        cin >> x;
        if(x != 0){
            if(x < 0){
                minus.push(x);
            }
            else{
                plus.push(-x);
            }
        }
        else{
            if(minus.empty() && plus.empty()){
                cout << "0\n";
            }
            else if(!minus.empty() && !plus.empty()){
                if(-minus.top() <= -plus.top()){
                    cout << minus.top() << "\n";
                    minus.pop();
                }
                else{
                    cout << -plus.top() << "\n";
                    plus.pop();
                }
            }
            else if(!plus.empty() && minus.empty()){
                cout << -plus.top() << "\n";
                plus.pop();

            }
            else if(plus.empty() && !minus.empty()){
                cout << minus.top() << "\n";
                minus.pop();
            }
        }
    }

    return 0;
}
