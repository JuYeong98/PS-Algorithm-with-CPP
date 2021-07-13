#include <string>
#include <vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> A;//  Enter 혹은 Change 혹은  Leave
    vector<string> B;// 아이디 부분
    vector<string> C;//닉네임 Leave를 제외하고는 값이 저장이 된다.
    int count = 0;
    string check="";
 
    for (int i = 0; i < record.size(); i++)
    {
        count = 0;
        istringstream ss(record[i]);  
        string stringBuffer;
        while (getline(ss, stringBuffer, ' ')) {// 공백을 기준으로 문자열을 잘라서 넣어준다.
            if (count == 0) {
                check = stringBuffer;
                A.push_back(stringBuffer); //Enter or Leave or Change
                count++;
                if (check == "Leave")//인덱스를 맞추기 위함
                    C.push_back("C");   
            }
            else if (count == 1) {
                B.push_back(stringBuffer);  //아이디를 넣어줌 
                count++;
            }
            else if (count == 2) {//Leave에 경우 여기까지 오지 못함
                C.push_back(stringBuffer);
            }
        }
    }
    vector<string> D; //아이디 중복을 피하기 위한 벡터 
    vector<string> E;
    for (int i = A.size() - 1; i >= 0; i--) { //각 아이디에서 change 나 enter가 마지막일때로 다 전부 맞춰준다
        if (std::find(D.begin(), D.end(), B[i]) - D.begin() == D.size()&&A[i] !="Leave") //D에 B[i](아이디가)없고 나간게 아니라면
        {
            D.push_back(B[i]);
            E.push_back(C[i]);
        }
    }
    for (int i = 0; i < D.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            if (B[j] == D[i]) //
            {
                C[j] = E[i];
            }
        }
    }
 
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] != "Change")
        {
            string a = C[i];
            if (A[i] == "Enter") {
                a.append("님이 들어왔습니다.");
                answer.push_back(a);
            }
            else if (A[i] == "Leave") {
                a.append("님이 나갔습니다.");
                answer.push_back(a);
            }
        }
    }
    return answer;
}

vector<string> solution2(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> A(record.size());
    string check = "";
    int count = 0;
    for (int i = 0; i < record.size(); i++)
    {
        count = 0;
        istringstream ss(record[i]);
        string stringBuffer;
        while (getline(ss, stringBuffer, ' ')) {// 공백을 기준으로 문자열을 잘라서 넣어준다.
            if (count == 0) {
                check = stringBuffer;
                A[i].push_back(stringBuffer);
                count++;
            }
            else if (count == 1) {
                A[i].push_back(stringBuffer);
                count++;
                if (check == "Leave")
                    A[i].push_back(" ");
            }
            else if (count == 2) {
                A[i].push_back(stringBuffer);
            }
        }
    }
    vector<string> D; //아이디 중복을 피하기 위한 벡터 
    vector<string> E;
    for (int i = A.size() - 1; i >= 0; i--) { //각 아이디에서 change 나 enter가 마지막일때로 다 전부 맞춰준다
        if (std::find(D.begin(), D.end(), A[i][1]) - D.begin() == D.size() && A[i][0] != "Leave") //D에 B[i](아이디가)없고 나간게 아니라면
        {
            D.push_back(A[i][1]);
            E.push_back(A[i][2]);
        }
    }
    for (int i = 0; i < D.size(); i++)
    {
        for (int j = 0; j < A.size(); i++)
        {
            if (D[i] == A[j][1])
                A[j][2] = E[i];
        }
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i][0] != "Change")
        {
            string a = A[i][2];
            if (A[i][0] == "Enter") {
                a.append("님이 들어왔습니다.");
                answer.push_back(a);
            }
            else if (A[i][0] == "Leave") {
                a.append("님이 나갔습니다.");
                answer.push_back(a);
            }
        }
    }
    return answer;
}

vector<string> solution3(vector<string> record)
{
    vector<string> answer;
    string command;
    string ID;
    string uid;
    map<string, string> m;

    for (string input : record)
    {
        stringstream ss(input);
        ss >> command;
        ss >> uid;
        if (command == "Enter" || command == "Change")
        {
            ss >> ID;
            m[uid] = ID;
        }
    }
    for (string input : record)
    {
        stringstream ss(input);
        ss >> command;
        ss >> uid;
        if (command == "Enter")
        {
            ID = (m.find(uid)->second);
            string temp = ID + "님이 들어왔습니다.";
            answer.push_back(temp);
        }
        else if (command == "Leave")
        {
            ID = (m.find(uid)->second);
            string temp = ID + "님이 나갔습니다.";
            answer.push_back(temp);
        }
    }
    return answer;
}