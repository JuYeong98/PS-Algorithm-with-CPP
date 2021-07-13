        #include <string>
        #include<math.h>
        #include <iostream>
        using namespace std;

        int solution(string dartResult) 
        {
            int answer = 0;
            string reward = "";
            int count = 0;
            int star_count = 0;
            int first = 0;
            string str = "";
            for (int i = 0; i < dartResult.length(); i++)
            {
               
                int a = 0;
                if (dartResult[i] >= 48 && dartResult[i] <= 57)
                {
                if(dartResult[i-1]!='1'&&dartResult[i+1]!='0')
                {
                    str = dartResult.substr(i, 1);
                    a = stoi(str);
                    count++;
                    if (dartResult[i + 1] == 'S' || dartResult[i + 1] == 'D' || dartResult[i + 1] == 'T')
                    {
                        if (dartResult[i + 1] == 'S')
                        {
                            if (dartResult[i + 2] != '#' && dartResult[i + 2] != '*')
                            {
                                answer += a;
                            }
                            else if (dartResult[i + 2] == '#')
                            {
                                answer -= a;
                            }
                            else if (dartResult[i + 2] == '*')
                            {
                                star_count++;
                                if (count <= 2)
                                {
                                    answer += a;
                                    answer *= 2;
                                }
                                else//count =3 즉 마지막
                                {
                                    if (star_count <= 2)
                                    {
                                        answer += a;
                                        answer *= 2;
                                        answer -= first;
                                    }
                                    else
                                    {
                                        answer += a;
                                        answer *= 2;
                                        answer =answer-(2*first);
                                    }

                                }
                            }
                            if (count == 1)
                                first = answer;
                        }
                        else if (dartResult[i + 1] == 'D')
                        {
                            a = a * a;
                            if (dartResult[i + 2] != '#' && dartResult[i + 2] != '*')
                            {
                                answer += a;
                            }
                            else if (dartResult[i + 2] == '#')
                            {
                                answer -= a;
                            }
                            else if (dartResult[i + 2] == '*')
                            {
                                if (count <= 2)
                                {
                                    answer += a;
                                    answer *= 2;
                                }
                                else//count =3 즉 마지막
                                {
                                    answer += a;
                                    answer *= 2;
                                    answer -= first;
                                }
                            }
                            if (count == 1)
                                first = answer;
                        }
                        else
                        {
                            a = a * a * a;
                            if (dartResult[i + 2] != '#' && dartResult[i + 2] != '*')
                            {
                                answer += a;
                            }
                            else if (dartResult[i + 2] == '#')
                            {
                                answer -= a;
                            }
                            else if (dartResult[i + 2] == '*')
                            {
                                if (count <= 2)
                                {
                                    answer += a;
                                    answer *= 2;
                                }
                                else//count =3 즉 마지막
                                {
                                    answer += a;
                                    answer *= 2;
                                    answer -= first;
                                }
                            }
                            if (count == 1)
                                first = answer;
                        }
                    }
                }
                else if (dartResult[i] == '1' && dartResult[i + 1] == '0')
                    {
                        
                        a = 10;
                        count++;
                        if (dartResult[i + 2] == 'S' || dartResult[i + 2] == 'D' || dartResult[i + 2] == 'T')
                        {
                            if (dartResult[i + 2] == 'S')
                            {
                                if (dartResult[i + 3] != '#' && dartResult[i + 3] != '*')
                                {
                                    answer += a;
                                }
                                else if (dartResult[i + 3] == '#')
                                {
                                    answer -= a;
                                }
                                else if (dartResult[i + 3] == '*')
                                {
                                    if (count <= 2)
                                    {
                                        answer += a;
                                        answer *= 2;
                                    }
                                    else//count =3 즉 마지막
                                    {
                                        answer += a;
                                        answer *= 2;
                                        answer -= first;
                                    }
                                }
                                if (count == 1)
                                    first = answer;
                            }
                            else if (dartResult[i + 2] == 'D')
                            {
                                a = 100;
                                if (dartResult[i + 3] != '#' && dartResult[i + 3] != '*')
                                {
                                    answer += a;
                                }
                                else if (dartResult[i + 3] == '#')
                                {
                                    answer -= a;
                                }
                                else if (dartResult[i + 3] == '*')
                                {
                                    if (count <= 2)
                                    {
                                        answer += a;
                                        answer *= 2;
                                    }
                                    else//count =3 즉 마지막
                                    {
                                        answer += a;
                                        answer *= 2;
                                        answer -= first;
                                    }
                                }
                                if (count == 1)
                                    first = answer;
                            }
                            else
                            {
                                answer += 1000;
                                if (dartResult[i + 3] != '#' && dartResult[i + 3] != '*')
                                {
                                    answer += a;
                                }
                                else if (dartResult[i + 3] == '#')
                                {
                                    answer -= a;
                                }
                                else if (dartResult[i + 3] == '*')
                                {
                                    if (count <= 2)
                                    {
                                        answer += a;
                                        answer *= 2;
                                    }
                                    else//count =3 즉 마지막
                                    {
                                        answer += a;
                                        answer *= 2;
                                        answer -= first;
                                    }
                                }
                                if (count == 1)
                                    first = answer;
                            }
                        }
                
                }
                    else if (dartResult[i] = '0' && dartResult[i - 1] == '1')
                    {
                    continue;
                        
                    }
                   
                }
            }
            return answer;
        }