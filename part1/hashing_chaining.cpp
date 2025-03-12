#include <iostream>
#include <vector>
#include <algorithm> // Required for find()

using namespace std;



struct Hash{
    vector<vector<int>> table;
    int BUCKET;
    Hash(int n){
        this->BUCKET = n;
        table.resize(BUCKET);
    }

    void insertval(int val){
        int ind = val % BUCKET;
        table[ind].push_back(val);
    }
    
    void deleteItem(int key){
        int ind = key % BUCKET;
        auto i = find(table[ind].begin(),table[ind].end(),key);
        if(i != table[ind].end()){
            table[ind].erase(i);
        }
    }
    
    void display(){
        for(int i = 0; i < BUCKET;i++)
        {
            cout << i;
            for(int x: table[i]){
                cout << " --> " <<x;
            }
            cout << endl;
        }
    }
    
};
int main(void){
    int n;
    cout <<"Enter the number of buckets : ";
    cin >> n;
    Hash h(n);
    
    vector <int> a = {15,11,27,8,12};
    
    for(int key:a){
        h.insertval(key);
    }
    h.deleteItem(12);
    
    h.display();
    
    
}