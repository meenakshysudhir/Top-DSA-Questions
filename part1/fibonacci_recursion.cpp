//using recursion to calculate the fibonacci of nth number
#include<iostream>
using namespace std;

int fibonacci(int x){
    if(x <= 1){
        return x;
    }
    return fibonacci(x-1) + fibonacci(x-2);
}
int main(){
    cout << "Fibonaaci(10) : " << fibonacci(10) << endl;
    return 0;
}
