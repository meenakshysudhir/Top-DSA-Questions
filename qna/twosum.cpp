#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map <int,int> m;
    
            for(int i = 0;i < nums.size();i++){
                m[nums[i]] = i;
            }
            vector<int> solution;
            int flag  = false;
            for(int i = 0; i < nums.size();i++){
                int diff = target - nums[i];
                auto got = m.find(diff);
                if(got != m.end() && i!= got->second ){
                    solution.push_back(i);
                    solution.push_back(got->second);
                    return solution;
                }
                else{
                    continue;
                }
            }
        }
    };
    