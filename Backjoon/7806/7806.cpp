#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
using namespace std;
// https://www.acmicpc.net/problem/7806
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    while(true){
        cin >> n >> k;
        if(cin.eof()) break;
        ll ans = 1;
        for (int i = 2; i*i <= k; i++){
            ll powK = 0;
            while(k % i == 0){
                k /= i;
                powK++;
            }
            if (powK){
                ll powN = 0;
                for (int j = i; j <= n; j *= i)
                    powN += (n / j);
                for(int j = 0;j<min(powK,powN);j++)
                    ans *= i;
            }
            if(k < i)
                break;
        }
        if (k > 1 && k <= n)
            ans *= k;
        cout << ans << "\n";
    }
}