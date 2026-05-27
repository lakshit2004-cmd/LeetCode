class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        if(n == 0) return 0;

        int k = 1;
        int prev = nums[0];  // 🔥 cache value (faster than nums[k-1])

        for(int i = 1; i < n; ++i) {

            if(nums[i] != prev) {
                prev = nums[i];
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};