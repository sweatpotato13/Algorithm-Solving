#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/10434
ll che[10001] ={0,};
bool dp[10001] ={0,0};
void getChe(ll num) {
    for (int i = 2; i <= num; i++) {
        che[i] = i;
    }
    for (int i = 2; i <= num; i++) { 
        if (che[i] == 0) 
            continue;
        for (int j = i + i; j <= num; j += i) {
            che[j] = 0;
        }
    }
}
bool happy(ll m){
    while(true){
        if(m == 1) return true;
        else{
            if(dp[m] == 1) return false;
            else dp[m] = 1;
            ll temp = 0;
            while(m){
                temp += (m%10) * (m%10);
                m /= 10;
            }
            m = temp;
        }        
    }
}
bool solve(ll m){
    if(che[m]){
        if(happy(m)) return true;
        else return false;
    }
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    getChe(10000);
    string ans[2] = {"NO","YES"};
    ll t;
    cin >> t;
    while(t--){
        memset(dp,0,sizeof(dp));
        ll c,m;
        bool isAnswer = false;
        cin >> c >> m;
        isAnswer = solve(m);
        cout << c << " " << m << " " << ans[isAnswer] << "\n";
    }

    

    return 0;
}
