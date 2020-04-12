#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
//https://www.acmicpc.net/problem/1620
bool is_digit(string str) {
    return atoi(str.c_str()) != 0 || str.compare("0") == 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    map<string, int> pokedex;
    map<int,string> pokedex_;
    for(int i = 0;i<n;i++){
        string s;
        cin >> s;
        pokedex[s] = i+1;
        pokedex_[i+1] = s;
    }
    for(int i = 0;i<m;i++){
        string s;
        cin >> s;
        if(is_digit(s)){
            int e = atoi(s.c_str());
            cout << pokedex_[e] << "\n";
        }
        else{
            cout << pokedex[s] << "\n";
        }
    }

    return 0;
}
