    #include <string>
    #include <vector>
    #include <algorithm>
    #include <iostream>
    #include <cmath>
    using namespace std;
    
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
    using namespace std;

    int solution(int n) {
        int answer = 0;
        vector<int> v;

        while (n)
        {
            v.push_back(n % 3);
            n /= 3;
        }

        reverse(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++)
            answer += pow(3, i) * v[i];

        return answer;
    }
    int main(void)
    {
        cout <<solution(125);
    }
/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
    using namespace std;
    int base3(int n);
    int three_to(int n);
    int to_three(int n);


    int solution(int n) {
        int answer = 0;
        answer = to_three(n);
        cout << endl << answer;
        answer = three_to(answer);
        cout << endl << answer;
        answer = base3(answer);
        cout << endl << answer;

        return answer;
    }
    int base3(int n)
    {
        int sum = 0;
        int count = 0;
        while (n >= 1)
        {
            int a = n % 10;
            sum = sum + a * pow(3, count);
            cout << "  " << a * pow(3, count);
            count++;
            n /= 10;
        }
        return sum;
    }
    int to_three(int n)
    {
        int a = n;
        int b = n;
        int sum = 0;
        int count = 0;
        int pow_three = 1;
        while (a >= 1)
        {
            b = a;
            count = 0;
            pow_three = pow(3, count);
            while (b / pow_three >= 3)
            {
                pow_three = pow(3, count);
                count++;
                if (b / pow_three < 3)
                {
                    count--;
                }
            }
            cout << endl << pow_three << "  ";
            cout << endl << (b / pow_three) << endl;
            sum = sum + ((b / pow_three) * pow(10, count));

            cout << "***" << ((b / pow_three) * pow(10, count)) << endl;
            a = a - ((b / pow_three) * pow_three);
        }

        return sum;
    }
    int three_to(int n)
    {
        int sum = 0;
        int count = 0;
        int n2 = n;
        while (n2 >= 1)
        {
            n2 /= 10;
            count++;
            if (n2 < 1)
            {
                count--;
            }
        }
        while (n >= 1)
        {
            sum = sum + (n % 10) * pow(10, count);
            n /= 10;
            count--;
        }
        return sum;
    }
    int main(void)
    {

        cout << solution(66);
    }*/