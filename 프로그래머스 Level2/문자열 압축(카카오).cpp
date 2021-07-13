#include <string>
#include <vector>
#include <iostream>
using namespace std;
int short_string(string s, int n)//s�� ������ ���ڿ� ���纻 , n�� ������� ��������
{
    vector<string> vec;
    string a = "";
    int r = s.size() % n; //������
    for (int i = 0; i < s.size()/n; i++)//s = "aa bb cc ab c" n=2
    {
        a = "";
        for (int j = 0; j < n; j++)
            a.append(s.substr((i * n) + j,1));
        vec.push_back(a);// vec�� n���� ���� ���ڿ����� ����Ʈ
    }
    int count = 1;
    string answer = "";
    for (int i = 0; i < vec.size(); ){
        if (i != vec.size() - 1) {
            while (vec[i] == vec[i + count]) {//�ڿ��Ŷ� ������ ī��Ʈ ����
                count++;
                if (i + count == vec.size())
                    break;
            }
            if (count != 1)
            {
                answer.append(to_string(count)); //count�� ���ڷ� ��ȯ�ؼ� append
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
    int len = s.size();  //���ڿ� ������ �ִ� ���ڿ��� ���ݱ���
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