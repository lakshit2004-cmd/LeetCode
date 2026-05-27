class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        mp.reserve(nums.size());
        mp.max_load_factor(0.7);
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++){
            int complement= target- nums[i];
            auto it = mp.find(complement);
        if (it != mp.end()){
 return{it->second,i};
 }
 mp[nums[i]]=i;
       }
   return{};
    }
};