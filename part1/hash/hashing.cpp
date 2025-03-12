//hashing using unordered_map

#include <iostream>
#include <unordered_map>
using namespace std;

int main(void)
{
    cout << "Enter the length of array : ";
    int len;
    cin >> len;
    cout << "Enter the elements : "; 
    int arr[len];
    for(int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int,int> map;
    for(int i =0 ; i < len;i++)
    {
        map[arr[i]]++;
    }
    for(auto x:map)
    {
        cout << x.first <<" " << x.second << endl;
    }
}
