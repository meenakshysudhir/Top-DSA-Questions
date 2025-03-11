#include <iostream>
#include <vector>
using namespace std;



struct Hash{
    vector<vector<int>> table;
    int BUCKET;
    Hash (int n){
        this->BUCKET = n;
        table.resize(BUCKET);
    }
}
int main(void){
    int n;
    cout <<"Enter the number of buckets : ";
    cin >> n;
    Hash h(n);

    
    
}