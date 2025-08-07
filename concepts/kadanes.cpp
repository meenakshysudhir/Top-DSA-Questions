#include <bits/stdc++.h>
using namespace std;

int Kadanes(vector<int>& arr){
    int res = arr[0];
    int maxEnding = arr[0];
    for(int i = 1;i < arr.size();i++){
        maxEnding = max(arr[i],arr[i] + maxEnding);
        res = max(res,maxEnding);
    }
    return res;
}
int main(void){
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    int res = Kadanes(arr);
    cout << res << endl;

}