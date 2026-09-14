https://leetcode.com/problems/majority-element/

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>nums.size()/2){
                return nums[i];
            }
        }
        return 0;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(count==0){
                candidate=nums[i];
                count++;
            }
            else if(nums[i]==candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};

