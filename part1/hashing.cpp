//normal unoptimized hashing
#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the array size :";
    cin >> n;
    int arr[13];
    cout << "Enter the values: ";
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int hash[13] = {0};
    for(int i = 0 ; i < n;i++)
    {
        hash[arr[i]]++;
    }
    int size;
    cout << "Enter the query size : ";
    cin >> size;
    int q[13];
    cout << "Enter query elements : ";
    for(int i = 0; i < size;i++)
    {
        cin >> q[i];

    }
    for(int i = 0; i < size;i++)
    {
        cout << hash[q[i]] << " ";
    }

}
