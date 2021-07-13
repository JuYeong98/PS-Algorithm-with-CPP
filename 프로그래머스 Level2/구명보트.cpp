    #include <string>
    #include <vector>
    #include <algorithm>
    #include <iostream>
    using namespace std;

    int solution(vector<int> people, int limit) {
        int answer = 0;
        int count = people.size() - 1;
        sort(people.begin(), people.end(),greater<>());
        int sum = 0;
        for (int i = 0; i <= count; )
        {
            if (people[i] <= limit / 2)
            {
                if ((count + 1 - i) % 2 == 0) //���� ������ ¦��
                {
                    answer += (count + 1 - i) / 2;
                    return answer;
                }
                else
                {
                    answer += ((count + 1 - i) / 2) + 1;
                    return answer;
                }
            }
            else {//ó�� ���Ұ� limit �� 1/2 �� �ƴҶ�
                if (people[i] + people[count] > limit&&i!=count)
                {
                    answer++;
                    i++;
                }
                else {
                    i++; count--; answer++;
                
                }
            }
        }
        return answer;
    }