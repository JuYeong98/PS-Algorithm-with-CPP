    #include <iostream>
    #include <stdio.h>
    #include <string>
    #include <vector>
    #include <algorithm>
    using namespace std;

    int solution(vector<int> d, int budget) {
        int answer = 0;
        int sum = 0;
        for (int i = 0; i < d.size(); i++)
        {
            sum += d[i];
        }
        if (sum <= budget)
        {
            return d.size();
        }
        else//sum>budget
        {
            sort(d.begin(), d.end());
            int i = 0;
            sum = 0;
            while (sum <= budget)
            {
                sum += d[i];
                i++;
                answer++;
            }
            if (sum > budget)
                answer--;
            return answer;
        }
    
    }