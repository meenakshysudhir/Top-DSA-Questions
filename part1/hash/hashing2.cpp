// hashing of characters

#include <iostream>
using namespace std;

int main()
{
    string s;
    cout << "Enter the string : ";
    cin >> s;
    int hash[26] = {0},len = s.length();
    for(int i = 0;i < len;i++)
    {
        hash[(int)(s[i] - 'a')]++;
    }
    cout << "Enter the query string : ";
    string q;
    cin >> q;
    int qlen = q.length();
    for(int i = 0; i < qlen;i++)
    {
        cout << hash[(int)(q[i] - 'a')] << endl;
    }
}
