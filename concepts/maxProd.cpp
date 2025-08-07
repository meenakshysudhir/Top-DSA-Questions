#include <bits/stdc++.h>
using namespace std;

int maxProd(vector<int>& arr){
    int left = 1, right = 1, maxProduct = INT_MIN, n = arr.size();
    for(int i = 0;i < n;i++){
        if(left == 0) left = 1;
        if(right == 0) right = 1;
        
        left *= arr[i];
        right *= arr[n-i-1];
        maxProduct = max({left,maxProduct,right});
    }
    return maxProduct;
}
int main(void){
    vector<int> arr = { -2, 6, -3, -10, 0, 2 };
    int res = maxProd(arr);
    cout << "Max Product : " << res << endl;
}