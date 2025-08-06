// cpp program to match substring 
#include <bits/stdc++.h>
using namespace std;
bool startsWith(string str,string prefix){
    return str.rfind(prefix,0) == 0;
}
bool endsWith(string& str,string& suffix){
    if(suffix.size() > str.size()) return false;
    return str.compare(str.size()- suffix.size(),suffix.size(),suffix) == 0;
}
bool contains(string& str,string& substr){
    return str.find(substr) != string :: npos;
}

int main(void){
    string str = "hello_world this is krishna";
    string input;
    cin >> input;
    if(startsWith(str,input)){
        cout <<"Starts with" << endl;
    }
    if(endsWith(str,input)){
        cout << "Ends with " << endl;
    }
    if(contains(str,input)){
        cout << "Contains" << endl;
    }
    cout << "--DONE--" << endl;

}