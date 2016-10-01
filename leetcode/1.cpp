#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <stack>
#include <set>
#include <ctime>

typedef long long ll;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        ans.clear();
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}
