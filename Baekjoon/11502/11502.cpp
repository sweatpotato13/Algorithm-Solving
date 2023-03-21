#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/11502
ll che[1001] ={0,};
vector<ll> prime;
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
void getPrime(ll num){
    for(int i = 2;i<=num;i++){
        if(che[i])
            prime.push_back(i);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    getChe(1000);
    getPrime(1000);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> ans;
        for(int i = 0;i<prime.size();i++){
            for(int j = 0;j<prime.size() && (n - prime[i]) >= prime[j];j++){
                for(int k = 0;k<prime.size() && (n-prime[i] - prime[j]) >= prime[k];k++){
                    if(prime[i] + prime[j] + prime[k] == n){
                        ans.push_back(prime[i]);
                        ans.push_back(prime[j]);
                        ans.push_back(prime[k]);
                        goto END;
                    }
                }
            }
        }
        END:
        if(ans.size() == 3){
            for(int i = 0;i<3;i++){
                cout << ans[i] << " ";
            }
        }
        else{
            cout << "0";
        }
        cout << "\n";
    }

    return 0;
}
