#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0;
    int y = 0;
    for(int i = 0;i<s.length();i++){
        char k = s[i];
        if(k == 'p' || k == 'P') p++;
        else if(k == 'y' || k == 'Y') y++;
    }
    if(p != y)
        answer = false;

    return answer;
}
