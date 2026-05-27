class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> res;

        for (int i = 0; i < n - 3; ++i) {

            if (i && nums[i] == nums[i - 1]) continue;

            long long t1 = (long long)target - nums[i];

            for (int j = i + 1; j < n - 2; ++j) {

                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long t2 = t1 - nums[j];

                int l = j + 1, r = n - 1;

                while (l < r) {

                    long long sum = nums[l] + nums[r];

                    if (sum < t2) ++l;
                    else if (sum > t2) --r;
                    else {

                        res.push_back({nums[i], nums[j], nums[l], nums[r]});

                        int a = nums[l], b = nums[r];

                        while (l < r && nums[l] == a) ++l;
                        while (l < r && nums[r] == b) --r;
                    }
                }
            }
        }

        return res;
    }
};