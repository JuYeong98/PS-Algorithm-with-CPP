#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    //필요한 글자수만큼 반복하기
    for (int j = 0, index = -1; j < number.length() - k; j++) {
        char max = 0;
        //앞에서 남겨야 되는 숫자 중에 제일 큰수 체크
        for (int i = index + 1; i <= k + j; i++) {
            if (max < number[i]) {
                index = i;
                max = number[i];
            }
        }
        //제일 큰수를 정답에 추가
        answer += max;
    }
    return answer;
}
string solution2(string number, int k) //"1924" ,2 
{
    for (int i = 0; i < number.size() - k; ++i)//0부터 사이즈 -k 까지 0~2
    {
        auto iter = std::max_element(number.begin() + i, number.begin() + i + k + 1);//0~3까지 가장 큰거  1~3 가장 큰거 
        if (iter != number.begin() + i) { //가장 큰 게 시작 + i 가 아니면 
            k = k - std::distance(number.begin() + i, iter); 
            number.erase(number.begin() + i, iter);
        }
    }
    number.erase(number.end() - k, number.end());
    return number;
}
string solution3(string number, int k)  //1231234 3  4177252841 4
{
    string answer = "";
    if (number.size() == 1) { //사이즈가 하나일때
        answer = number;
    }
    bool b = false;
    do {
        for (int i = 0; i < number.size() - 1; i++) // size =10
        {
            if (k == 0)// 지울게 더 이상 없다면
                break;
            if (number[i] < number[i + 1])//뒤에 숫자가 더 크다면 
            {
                number.erase(i, 1);
                i = -1;
                k--; //지웠으니까 하나 감소
                b = true;
            }
        }
    } while (b == true && k > 0);

    while (k > 0)
    {
        number.erase(number.size() - 1);
        k--;
    }
    answer = number;
    return answer;
}