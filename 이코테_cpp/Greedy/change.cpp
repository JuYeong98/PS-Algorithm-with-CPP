#include <iostream>
#include <vector>
int main(void)
{
    int money = 1260; 
    vector<int> moneys;
    moneys.append(500);
    moneys.append(100);
    moneys.append(50);
    moneys.append(10);

    int num_of_changes =0
    for(int i=0;i<moneys.size();i++){
        int changes_num = money/moneys[i];
        num_of_changes+=changes_num;
        money -= moneys[i] * changes_num;
    }
    cout<<"num of changes is "<<num_of_changes<<endl;
}