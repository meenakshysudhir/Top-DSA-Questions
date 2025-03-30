#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums = {1,2,2,3,3,3};
int k = 2;
vector<int> res;

void sorting(){
    unordered_map<int,int> count;
    for(auto i: nums){
        count[i]++;
    }
    vector<pair<int,int>> arr;
    for(const auto& i: count){
        arr.push_back({i.second,i.first});
    }
    sort(arr.rbegin(),arr.rend());

    for(int i =0;i < k;i++){
        res.push_back(arr[i].second);
    }
    // return res;
    
}
int main(void){
   
    sorting();
    for(auto i:res){
        cout << i << endl;
    }
}