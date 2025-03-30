
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(void){
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    unordered_map<string,vector<string>> map;
    string key;
    for(const auto& s : strs){
        vector<int> v(26,0) ;
        for(const auto c : s){
            v[c - 'a']++;
        }
        key = to_string(v[0]);
        for(int i = 1; i < 26;i++){
            key += ',' + to_string(v[i]);
        }
        map[key].push_back(s);
    }
    vector<vector<string>> res;
    for(const auto &key :map){
        res.push_back(key.second);
    }
    //for(auto i : res){
    //    cout << i << " ";
   // }
}
