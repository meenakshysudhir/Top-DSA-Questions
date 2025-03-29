#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
int main(void){
    vector<int> a= {1,2,3,5};
    unordered_set<int> set;
    for(int i:a){
        set.insert(i);
    }
    if(a.size() > set.size()){
        cout << "Duplicate entries";
        
    }
    else{
        cout << "No duplicate entries";
    }
}