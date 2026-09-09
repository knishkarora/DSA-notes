class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> unique(nums.size());
        int index = 0;
        for(int i=0;i<nums.size();i++){
            bool found=false;
            for(int j=0;j<index;j++){
                if(nums[i]==unique[j]){
                    found=true;
                    break;
                }
            }
            if(found==false){
                unique[index]=nums[i];
                index++;
            }
        }
        nums = unique;
        return index;
    }
};