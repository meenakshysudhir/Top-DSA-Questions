#include <iostream>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void printArray(int arr[],int len){
    for(int i = 0; i < len;i++)
    {
        cout << arr[i] <<  " ";
    }

}
void selection_sort(int arr[],int len)
{
    
    for(int i = 0;i < len;i++)
    {
        int min = i;
        for(int j = i+1; j < len;j++)
        {
            if(arr[min] > arr[j]){
                min = j; 
            }
        }
        if(min!= i) swap(arr,i,min);
    }
printArray(arr ,len);
}
int main(void)
{
    int arr[] = {13,46,24,52,20,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,size);
}
