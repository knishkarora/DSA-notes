https://leetcode.com/problems/maximum-subarray/description/


Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int bigsum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(sum + nums[i]<nums[i]) {
                sum=nums[i];
                
                
            }else{
                sum+=nums[i];
            }
            if(bigsum<sum){
                bigsum=sum;
            }
            

        }
        return bigsum;
    }
};

