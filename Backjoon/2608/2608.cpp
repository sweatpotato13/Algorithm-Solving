#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/2608
string m[] = {"", "M", "MM", "MMM","MMMM"}; 
string c[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; 
string x[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}; 
string i[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; 
ll convert(string s) {
    map<char, ll> m = {{'I', 1}, {'V', 5},{'X', 10},{'L', 50},
    {'C', 100},{'D', 500},{'M', 1000}};
    
    ll total = 0;
    for(int i = 0; i < s.length(); i++){
        if(m[s[i+1]] <= m[s[i]])  total += m[s[i]]; 
        else  total -= m[s[i]];  
    }
    return total;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1,s2;
    cin >> s1 >> s2;
    ll t1 = convert(s1);
    ll t2 = convert(s2);
    cout << t1+t2 << "\n";
    string ans = "";
    ll temp = t1+t2;
    ans += m[temp/1000];
    temp %= 1000;
    ans += c[temp/100];
    temp %= 100;
    ans += x[temp/10];
    ans += i[temp%10];
    cout << ans;


    return 0;
}
