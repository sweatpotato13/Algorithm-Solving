#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/1759
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l,c;
    cin >> l >> c;
    vector<ll> idx(c);
    vector<char> v(c);
    for(int i = 0;i<c;i++){
        cin >> v[i];
    }
    for(int i = 0;i<l;i++){
        idx[i] = 1;
    }
    sort(all(idx));
    sort(all(v));
    vector<string> ans;
    do{
        ll consonant = 0;
        bool hasVowel = false;
        string temp = "";
        for(int i = 0;i<c;i++){
            if(idx[i]) {
                temp += v[i];
                if(v[i] == 'a' || v[i] == 'e' || v[i]=='i' || v[i]=='o' || v[i]=='u')
                    hasVowel = true;
                else consonant++;
            }
        }
        if(hasVowel && consonant >= 2) ans.push_back(temp);
    }while(next_permutation(all(idx)));
    sort(all(ans));
    for(auto k : ans){
        cout << k << "\n";
    }

    return 0;
}
