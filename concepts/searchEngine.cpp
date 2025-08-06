//Amazon question.You are given a vector of words, called repository and another input word for searching. You have to match the words,
// after every character input of the search word and the minimum size of the search word is 3 chars. for each entry after the size of 2 
// a vector of max 3 words matching from the repository should be matched for each character entry.Case insentsitive.More than 3 keywords,
// return in alphabetical order.
#include <bits/stdc++.h>
using namespace std;
    vector<vector<string>> getAns(vector<string>& repository,string& input){
        vector<vector<string>> res;
        int count = 0;
        for(string s : repository){
            transform(s.begin(),s.end(),s.begin(),::tolower);
        }
        sort(repository.begin(),repository.end());
        transform(input.begin(),input.end(),input.begin(),::tolower);
        for(int i  = 0; i < input.length();i++){
            if(i < 1) continue;
            string key = input.substr(0,i+1);
            // cout << key << endl;
            vector<string> keywords;
            count = 0;
            for(int j = 0; j < repository.size();j++){
            if(repository[j].rfind(key,0) != string:: npos && count < 3){
                keywords.push_back(repository[j]);
                count++;
            } 
            if(count == 3) {
                    // count = 0;
                    break;
                }   
            }
            res.push_back(keywords);
            
        }
        return res;
    }
// for(int i = 0; i < repository.size();i++){
//            if(repository[i].rfind(key,0) != string:: npos && keywords.size() < 4){
//             keywords.push_back(repository[i]);
//             count++;
//            } 
//            if(keywords.size() >=3) break;

int main(void){
    vector<string> repository = {"mobile","mouse","moneypot","monitor","mousepad"};
    string customerQuery = "mouse";
    vector<vector<string>> res = getAns(repository,customerQuery);
    for(auto row : res){
        for(string s : row){
            cout << s << " ";
        }
        cout << endl;
    }

}