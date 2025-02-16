//find pallindrome using recursion
#include <iostream>
using namespace std;

int palindrome(int n,string& s){
    if(n >= s.length()/2){
        return 1;
    }
    if(s[n] != s[s.length() - 1 - n]){
        return 0;
    }
    return palindrome(n+1  ,s);
}
int main()
{
    cout << "Enter the word : ";
    string s;
    cin >> s;
    int res = palindrome(0,s);
    (res == 0) ? cout << "Not a pallindrome" << endl : cout << "Word is pallindrom\n";
    return 0;
}
