#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//��ģ ���� ���ؼ� ū������ �����ϱ�, ex ) 6, 10 �� �ִٸ� 610�� 106�ϰ� ��� ū�� ��
// 610�� ��ũ�Ƿ� 6, 10������ �����ϰ� �ȴ�.
bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    //string���� �ٲ��� ���Ϳ� ����ִ´�.
    for (auto num : numbers)
        temp.push_back(to_string(num));
    //���Ҷ� ������������ �����Ѵ�.
    sort(temp.begin(), temp.end(), cmp);
    //ó�� ���ڰ� 0�̶�� 0�� ��ȯ
    if (temp.at(0) == "0")        return "0";
    //ó������ ������ ���ڿ� ��ġ�� ����
    for (auto num : temp)
        answer += num;
    return answer;
}