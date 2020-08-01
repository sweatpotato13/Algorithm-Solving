#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0;i<s.length();i++){
        if(s[i] != ' '){
            char base = 'a';
            if(s[i] >= 'A' && s[i] <= 'Z'){
                base = 'A';
            }
            s[i] = base + (s[i] + n - base)%26;
        }
    }
    return s;
}
