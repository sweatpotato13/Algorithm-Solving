#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1747
ll che[2000001] ={0,};
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll cnt = 0;
    ll n;
    cin >> n;
    getChe(2000000);
    for(int i = 0;i<=2000000;i++){
        if(che[i] >= n){
            if(che[i] < 10)
                cnt++;
            else{
                string s;
                ll temp = che[i];
                while(temp > 0){
                    s += (temp%10 + '0');
                    temp /= 10;
                }
                bool isPelin = true;
                for(int j = 0;j<s.length();j++){
                    if(s[j] != s[s.length()-1-j]){
                        isPelin = false;
                        break;
                    }
                }
                if(isPelin)
                    cnt++;
            }
            if(cnt == 1){
                ans = che[i];
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}