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
                if ((count + 1 - i) % 2 == 0) //남은 개수가 짝수
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
            else {//처음 원소가 limit 에 1/2 가 아닐때
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