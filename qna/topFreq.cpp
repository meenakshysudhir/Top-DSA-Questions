//given an int array nums and an int k, find the k most frequent elements

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void){

    vector<int> nums = {1,2,2,3,3,3};
    int k = 2;
    int len =  nums.size();
    vector<int> res(len,0);
    for(auto i:nums){
        res[i]++;
    }

    unordered_map<int ,int> freq;
    for(int i = 0; i < len;i++){
        freq[res[i]] = i;
    }
    for(const auto i: freq){
        cout << i.first <<" " << i.second << endl; 
    }

}
