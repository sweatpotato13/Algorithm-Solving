#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer(s.size(),0);
    int idx = 0;
    for(int i = 0;i<s.length();i++){
        if(s[i] == ' '){
            answer[i] = s[i];
            idx = 0;
            continue;
        }
        if(idx % 2 == 0){
            if(s[i] >= 'a' && s[i] <= 'z')
                answer[i] = (s[i]-32);
            else answer [i] = s[i];
        }
        else{
            if(s[i] >= 'A' && s[i] <= 'Z')
                answer[i] = (s[i]+32);
            else answer [i] = s[i];
        }
        idx++;
    }
    return answer;
}
