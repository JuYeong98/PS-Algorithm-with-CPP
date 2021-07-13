#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    //�ʿ��� ���ڼ���ŭ �ݺ��ϱ�
    for (int j = 0, index = -1; j < number.length() - k; j++) {
        char max = 0;
        //�տ��� ���ܾ� �Ǵ� ���� �߿� ���� ū�� üũ
        for (int i = index + 1; i <= k + j; i++) {
            if (max < number[i]) {
                index = i;
                max = number[i];
            }
        }
        //���� ū���� ���信 �߰�
        answer += max;
    }
    return answer;
}
string solution2(string number, int k) //"1924" ,2 
{
    for (int i = 0; i < number.size() - k; ++i)//0���� ������ -k ���� 0~2
    {
        auto iter = std::max_element(number.begin() + i, number.begin() + i + k + 1);//0~3���� ���� ū��  1~3 ���� ū�� 
        if (iter != number.begin() + i) { //���� ū �� ���� + i �� �ƴϸ� 
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
    if (number.size() == 1) { //����� �ϳ��϶�
        answer = number;
    }
    bool b = false;
    do {
        for (int i = 0; i < number.size() - 1; i++) // size =10
        {
            if (k == 0)// ����� �� �̻� ���ٸ�
                break;
            if (number[i] < number[i + 1])//�ڿ� ���ڰ� �� ũ�ٸ� 
            {
                number.erase(i, 1);
                i = -1;
                k--; //�������ϱ� �ϳ� ����
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