#include <string>
#include <vector>
using namespace std;
string solution(string new_id) {
    string answer = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] >= 65 && new_id[i] <= 90)
        {
            new_id[i] += 32;//대문자는 소문자 변환
        }
        if ((new_id[i] >= 97 && new_id[i] <= 122) || (new_id[i] >= 48 && new_id[i] <= 57) || new_id[i] == 45 || new_id[i] == 95 || new_id[i] == 46)
        {
            if ((answer.back() == '.'&&new_id[i]=='.')==0)//연속으로 .이 들
            {
                if((answer.size()==0&&new_id[i]=='.')==0)
                answer.push_back(new_id[i]);
            }
        }
    }
    while (answer.back() == '.')//4단계
        answer.pop_back();
    if (answer.size() == 0)//5단계
        answer.push_back('a');
    if (answer.size() > 15)
    {
        answer.resize(15);
    }
    while (answer.back() == '.')//6단계
        answer.pop_back();
    while(answer.size() <= 2)
    {
        answer.push_back(answer.back());
    }//7단계
    return answer;
}