    #include <string>
    #include <vector>
    #include <iostream>
    using namespace std;

    string solution(vector<string> seoul) {
        string answer = "";
        int len = seoul.size();
        int position = 0;
        for (int i = 0; i < len; i++)
        {
            if (seoul[i] == "Kim")
            {
                position = i;
            }
        }
        answer.append("김서방은 ");
        answer.append(to_string(position));
        answer.append("에 있다");
        return answer;
    }
    int main(void)
    {

    }