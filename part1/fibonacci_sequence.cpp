#include <iostream>
using namespace std;
void fib(int x)
{
    cout << "0 1 ";
    int i = 2;
    int firstnum = i -1;
    int secondnum = i -2;
    while(i < x)
    {
        int curr = firstnum + secondnum;
        cout << curr<< " ";
        secondnum = firstnum;
        firstnum = curr;
        i++;
    }
}
int main(){
    int x;
    cout << "Enter the number: ";
    cin >> x;
    x == 0 ? (void)(cout << "0" <<endl) : (x == 1) ? (void)(cout << "0 1" <<endl) : fib(x); 
}
