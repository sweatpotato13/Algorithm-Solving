#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    if(s.length() % 2){
        answer = s.substr(s.length()/2,1);
    }
    else{
        answer = s.substr(s.length()/2-1,2);
    }
    return answer;
}