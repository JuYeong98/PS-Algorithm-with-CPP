#include <string>
#include <vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> A;//  Enter Ȥ�� Change Ȥ��  Leave
    vector<string> B;// ���̵� �κ�
    vector<string> C;//�г��� Leave�� �����ϰ�� ���� ������ �ȴ�.
    int count = 0;
    string check="";
 
    for (int i = 0; i < record.size(); i++)
    {
        count = 0;
        istringstream ss(record[i]);  
        string stringBuffer;
        while (getline(ss, stringBuffer, ' ')) {// ������ �������� ���ڿ��� �߶� �־��ش�.
            if (count == 0) {
                check = stringBuffer;
                A.push_back(stringBuffer); //Enter or Leave or Change
                count++;
                if (check == "Leave")//�ε����� ���߱� ����
                    C.push_back("C");   
            }
            else if (count == 1) {
                B.push_back(stringBuffer);  //���̵� �־��� 
                count++;
            }
            else if (count == 2) {//Leave�� ��� ������� ���� ����
                C.push_back(stringBuffer);
            }
        }
    }
    vector<string> D; //���̵� �ߺ��� ���ϱ� ���� ���� 
    vector<string> E;
    for (int i = A.size() - 1; i >= 0; i--) { //�� ���̵𿡼� change �� enter�� �������϶��� �� ���� �����ش�
        if (std::find(D.begin(), D.end(), B[i]) - D.begin() == D.size()&&A[i] !="Leave") //D�� B[i](���̵�)���� ������ �ƴ϶��
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
                a.append("���� ���Խ��ϴ�.");
                answer.push_back(a);
            }
            else if (A[i] == "Leave") {
                a.append("���� �������ϴ�.");
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
        while (getline(ss, stringBuffer, ' ')) {// ������ �������� ���ڿ��� �߶� �־��ش�.
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
    vector<string> D; //���̵� �ߺ��� ���ϱ� ���� ���� 
    vector<string> E;
    for (int i = A.size() - 1; i >= 0; i--) { //�� ���̵𿡼� change �� enter�� �������϶��� �� ���� �����ش�
        if (std::find(D.begin(), D.end(), A[i][1]) - D.begin() == D.size() && A[i][0] != "Leave") //D�� B[i](���̵�)���� ������ �ƴ϶��
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
                a.append("���� ���Խ��ϴ�.");
                answer.push_back(a);
            }
            else if (A[i][0] == "Leave") {
                a.append("���� �������ϴ�.");
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
            string temp = ID + "���� ���Խ��ϴ�.";
            answer.push_back(temp);
        }
        else if (command == "Leave")
        {
            ID = (m.find(uid)->second);
            string temp = ID + "���� �������ϴ�.";
            answer.push_back(temp);
        }
    }
    return answer;
}