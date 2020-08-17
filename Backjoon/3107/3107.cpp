#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/3107
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    ll m = 0;
    string ans = "";
    for(int i = 0;i<s.length();){
        if(s[i] != ':'){
            m++;
            while(i<s.length() && s[i] != ':') i++;
        }
        else{
            i++;
        }
    }
    auto dc = s.find("::",0,2);
    if(dc != string::npos){
        ll left = 8 - m;
        string zeros = "";
        if(dc != 0) zeros += ':';
        while(left--){
            zeros += "0000";
            if(left != 0) zeros += ':';
        }
        if(dc != s.size()-2) zeros += ':';
        s.replace(dc,2,zeros);
    }
    string temp = "";
    for(int i = 0;i<s.length();i++){
        if(s[i] == ':'){
            if(temp.length() != 4){
                for(int j=0;j<4-temp.length();j++){
                    ans += '0';
                }
            }
            ans += temp;
            ans += ':';
            temp = "";
        }
        else{
            temp+=s[i];
        }
    }
    if(temp.length() != 4){
        for(int j=0;j<4-temp.length();j++){
            ans += '0';
        }
    }
    ans += temp;
    cout << ans;

    return 0;
}
