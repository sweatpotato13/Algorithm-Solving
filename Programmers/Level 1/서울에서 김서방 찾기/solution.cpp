#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int idx = 0;
    for(int i = 0;i<seoul.size();i++){
        if(seoul[i] == "Kim"){
            idx = i;
            break;
        }
    }
    answer.append("김서방은 ");
    answer += to_string(idx);
    answer.append("에 있다");
    return answer;
}
