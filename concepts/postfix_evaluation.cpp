#include <bits/stdc++.h>
using namespace std;

vector<string> words;
void getEach(string input){
    stringstream ss(input);
    string word;
    while(ss >> word){
        words.push_back(word);
        cout << word  << " ";
    }

}
int evaluate(string input){
    getEach(input);
    stack<int> s;
    int a ,b;
    for(string i : words){
        if(i != "+" &&  i != "-" && i != "*" && i != "/"){
            cout << stoi(i) << endl;
            s.push(stoi(i));
        }
        else if(i == "+"){
            a = s.top();s.pop();
             b = s.top();s.pop();
            s.push(b+a);
        }
        else if( i== "-") {
             a = s.top();s.pop();
             b = s.top();s.pop();
            s.push(b-a);
        }
        else if(i == "*"){
            a = s.top();s.pop();
            b = s.top();s.pop();
            s.push(b*a);
        }
        else if(i == "/"){
            a = s.top();s.pop();
            b = s.top();s.pop();
            s.push(b/a);
        }
        else{
            cout << "Invalid Entry " << endl;
        }
    }
    return s.top();

}
int main(void){
    string input;
    cout << "Enter the postfix : ";
    getline(cin,input);
    int res = evaluate(input);
    cout << "result :" << res << endl;
}