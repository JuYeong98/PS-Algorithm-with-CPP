    #include <string>
    #include <vector>
    #include <algorithm>
    #include <bitset>
    #include <iostream>
    using namespace std;

    vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
        vector<string> answer;
        vector<int> a1;
        vector<int> a2;
        for (int i = 0; i < n; i++)
        {
            answer.push_back("");
            for (int j = 0; j < n; j++)
            {
                answer[i].append(" ");
            }
        }
        for (int i = 0; i < arr1.size(); i++)
        {
            int count = 0;
            while (arr1[i] > 0||arr2[i]>0)//각각 2진수로 변환된 수를 각 벡터에 넣어준다.
            {
                
                int n = arr1[i] % 2;
                int n2 = arr2[i] % 2;
            
                arr1[i] /= 2;
                arr2[i] /= 2; 
                if (n == 1 || n2 == 1)
                {
                    answer[i][count] = '#';
                }
                count++;
            }
            
            reverse(answer[i].begin(), answer[i].end());
        }
 

        return answer;
    }