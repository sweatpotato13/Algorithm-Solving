#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/1918
int getOperationPriority(char ch){
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    else return 0;
} 
bool isCompare(char ch1, char ch2){
    return getOperationPriority(ch1) >= getOperationPriority(ch2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    stack<char> s;
    string p;
    string ans = "";
    cin >> p;
    for(int i = 0;i<p.length();i++){
        char ch = p[i];
        if(p[i] >= 'A' && p[i] <= 'Z'){
            ans += p[i];
        }
        else{
            if(s.empty()) s.push(p[i]);
            else{
                switch(ch){
                    case '(':
                        s.push(ch);
                        break;
                    case ')':
                        while (true) {
                            char e = s.top();
                            s.pop();
                            if (e == '(')
                                break;
                            ans += e;
                        }
                        break;
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                        while(!s.empty() && isCompare(s.top(),ch)){
                            ans += s.top();
                            s.pop();
                        }
                        s.push(ch);
                        break;
                }
            }
        }
    }
    while(!s.empty()){
        char e = s.top();
        ans += e;
        s.pop();
    }
    cout << ans << "\n";

	return 0;
}