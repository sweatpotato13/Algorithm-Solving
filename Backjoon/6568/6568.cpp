#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/6568
ll strToll(string s){
    ll res = 0;
    ll t = 128;
    for(auto k : s){
        if(k == '1') res += t;
        t /= 2;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1){
        ll pc = 0;
        ll eax = 0;
        vector<ll> c(32);
        for(int i = 0;i<32;i++){
            string s;
            cin >> s;
            if(cin.eof()) return 0;
            c[i] = strToll(s);
        }
        while(1){
            ll opcode = c[pc] / 32;
            ll val = c[pc] % 32;
            if(opcode == 7) break;
            pc = (pc+1)%32;
            if (opcode == 0){
                c[val] = eax;
            }
            if (opcode == 1){
                eax = c[val];
            }
            if (opcode == 2){
                if(eax == 0) pc = val;
            }
            if (opcode == 3){
                // DO NOTHING
            }
            if (opcode == 4){
                eax = (eax+255)%256;
            }
            if (opcode == 5){
                eax = (eax+1)%256;
            }
            if (opcode == 6){
                pc = val;
            }
        }
        for(int i = 7;i>=0;i--){
            cout << ((eax >> i) & 1);
        }
        cout << "\n";
    }

    return 0;
}
