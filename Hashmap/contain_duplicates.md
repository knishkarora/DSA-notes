https://leetcode.com/problems/contains-duplicate/description/

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                return true;
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])!=st.end()){
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
    }
};