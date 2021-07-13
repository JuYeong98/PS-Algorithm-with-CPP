#include <string>
#include <vector>
#include <iostream>
using namespace std;
int short_string(string s, int n)//s는 압축할 문자열 복사본 , n은 몇개단위로 압축할지
{
    vector<string> vec;
    string a = "";
    int r = s.size() % n; //나머지
    for (int i = 0; i < s.size()/n; i++)//s = "aa bb cc ab c" n=2
    {
        a = "";
        for (int j = 0; j < n; j++)
            a.append(s.substr((i * n) + j,1));
        vec.push_back(a);// vec는 n개씩 나눈 문자열들의 리스트
    }
    int count = 1;
    string answer = "";
    for (int i = 0; i < vec.size(); ){
        if (i != vec.size() - 1) {
            while (vec[i] == vec[i + count]) {//뒤에거랑 맞으면 카운트 증가
                count++;
                if (i + count == vec.size())
                    break;
            }
            if (count != 1)
            {
                answer.append(to_string(count)); //count를 숫자로 변환해서 append
            }
            answer.append(vec[i]); //vec[i] append
            i += count;
            count = 1;
        }
        else if (i == vec.size() - 1) {
            answer.append(vec[i]);
            i++;
        }
    }
    cout << answer << endl;
    return answer.size()+r;
}
int solution(string s) {
    int answer = 0;
    int len = s.size();  //문자열 압축은 최대 문자열의 절반까지
    int min = len;
    for (int i = 1; i <= len / 2; i++)
    {
        int k = short_string(s, i);
        if (min > k)
            min = k;
    }
    return min;
}
int main(void)
{
    string a = "abcabcabcabcdededededede";
    cout << a.size()<<endl;
    solution("abcabcdede");
}