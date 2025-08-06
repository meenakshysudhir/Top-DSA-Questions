#include <bits/stdc++.h>
using namespace std;

vector<string> getMoves(string& input){
    vector<string> moves;
    for(int i = 0;i < input.size();){
        if(input.substr(i,5) == "snake") {
            moves.push_back("snake");
            i+= 5;
        }
        else if(input.substr(i,5) == "water"){
            moves.push_back("water");
            i+= 5;
        }
        else if(input.substr(i,3) == "gun"){
            moves.push_back("gun");
            i+=3;
        }
        else{
            cout << "Invalid moves" << endl;
            break;
        }
    }
    return moves;
}
vector<int> getAns(string& input){

    vector<string> moves = getMoves(input);
    vector<int> rounds;
    for(int i =0;i < moves.size(); i+=2){
        string a = moves[i], b = moves[i+1];
        // cout << a << " " << b << " ";
        if((a == "snake" && b == "water")|| (a == "gun" && b == "snake") || (a == "water" && b == "gun")) rounds.push_back(i/2 + 1);

    }
    return rounds;
    
}
int main(void){
    cout << "Input : ";
    string input;
    cin >> input;
    vector<int> res = getAns(input);
    for(int i : res) cout << i << " ";
}