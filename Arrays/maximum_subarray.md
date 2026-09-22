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

## divide and conquer

class Solution {
public:
    int helper(vector<int>& nums, int left, int right) {
        if(left==right){
            return nums[left];
        }

        int mid = left + (right - left)/2;
        int leftAnswer = helper(nums, left, mid);
        int rightAnswer = helper(nums, mid+1, right);

        int bestleftcross = nums[mid];
        int runningsum = nums[mid];
        for(int i=mid-1;i>=left;i--){
            runningsum+=nums[i];
            bestleftcross = max(bestleftcross, runningsum);
        }

        int bestrightcross = nums[mid+1];
        runningsum = nums[mid+1];
        for(int i=mid+2;i<=right;i++){
            runningsum+=nums[i];
            bestrightcross = max(bestrightcross, runningsum);
        }

        int crossAnswer = bestleftcross + bestrightcross;

        return max(leftAnswer, max(rightAnswer, crossAnswer));
    }


    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};

