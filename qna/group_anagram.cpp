
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(void){
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    unordered_map<string,vector<string>> m;
    string key;
    for(const auto& s : strs){
        vector<int> v(26,0) ;
        for(const auto c : s){
            v[c - 'a']++;
        }
        key = to_string(v[0]);
        for(int i = 1; i < 26;i++){
            key += "," + to_string(v[i]);
        }
        m[key].push_back(s);
    }
    vector<vector<string>> res;
    for(const auto &pair :m){
        res.push_back(pair.second);
    }
    for(const auto& group: res){
        for(const auto& word: group){
            cout << word << "  ";
        }
        cout << endl;
    }
}
