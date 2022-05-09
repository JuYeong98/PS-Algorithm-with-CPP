#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_able(vector<vector<int>> key , vector<vector<int>> lock){
    return false;
}

void show(vector<vector<int>> key){
    for(int i=0;i<key.size();i++){
        for(int j=0;j<key[0].size();j++){
            cout<<key[i][j]<<" ";
        }
        cout<<endl;
    }
}
vector<vector<int>> down(vector<vector<int>> key){
    int size = key.size();
    vector < vector <int> > temp(size,vector <int>(size,0));
    for(int i=0;i<key.size()-1;i++){
        for(int j=0;j<key[0].size();j++){
            temp[i+1][j] = key[i][j];
        }
    }
    return temp;
}

vector<vector<int>> up(vector<vector<int>> key){
    int size = key.size();
    vector < vector <int> > temp(size,vector <int>(size,0));
    for(int i=1;i<key.size();i++){
        for(int j=0;j<key[0].size();j++){
            temp[i-1][j] = key[i][j];
        }
    }
    return temp;
}

vector<vector<int>> right(vector<vector<int>> key){
    int size = key.size();
    vector < vector <int> > temp(size,vector <int>(size,0));
    for(int i=0;i<key.size();i++){
        for(int j=0;j<key[0].size()-1;j++){
            temp[i][j+1] = key[i][j];
        }
    }
    return temp;
}

vector<vector<int>> left(vector<vector<int>> key){
    int size = key.size();
    vector < vector <int> > temp(size,vector <int>(size,0));
    for(int i=0;i<key.size();i++){
        for(int j=1;j<key[0].size();j++){
            temp[i][j-1] = key[i][j];
        }
    }
    return temp;

}

vector<vector<int>> rotate(vector<vector<int>> key , int lock_size, int c){
    int size = key.size();
    vector < vector <int> > temp(size,vector <int>(size,0));
    vector < vector <int> > temp_lock(lock_size,vector <int>(lock_size,0));
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            {temp_lock[i][j] = key[size - j -1][i];
             temp[i][j] = key[size-j-1][i];
            }
    if(c==1)
        return temp_lock;
    else
        return temp;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    vector < vector <int> > temp_key(lock.size(),vector <int>(lock.size(),0));
    for(int i=0;i<4;i++){
        if(is_able(key, lock)){
            continue;
        }
        else{
            temp_key= rotate(key ,lock.size(), 1);
            key = rotate(key ,lock.size(),2 );
            show(temp_key);
            cout<<endl;
            //key = right(key);
            //show(key);
            //cout<<endl;
        }
    }
    return answer;
}

int main(void){
    vector<vector<int>> key = {{0,0,0},{1,0,0},{0,1,1}};
    vector<vector<int>> lock = {{1,1,1,1},{1,1,0,1},{1,0,1,1},{1,1,1,1}};
    solution(key,lock);
}