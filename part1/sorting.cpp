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
    void bubble_sort(int arr[], int n)
{
    for(int i = 0; i < n-1;i++)
    {

        for(int j = 0; j < n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {

                swap(arr,j,j+1);
            }
        }
    }
    printArray(arr,n);
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
void insertion_sort(int arr[],int n){

    for(int i = 1; i < n;i++){
        int j = i-1;
        int key = arr[i];
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    printArray(arr, n);
}
int main(void)
{
    int arr[] = {13,46,24,52,20,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Enter 1 for selection sort\nEnter 2 for bubble sort\nEnter 3 for insertion sort\nEnter 4 for quick sort\nChoice : ";
    int ch;
    cin >> ch;
    switch(ch){
        case 1:
            selection_sort(arr,size);
            break;
        case 2:
            bubble_sort(arr,size);
        case 3:
            insertion_sort(arr,size);
    }
    
}
