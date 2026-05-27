class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;

        while (l < r) {
            int width = r - l;

            if (height[l] < height[r]) {
                ans = max(ans, height[l] * width);
                ++l;
            } else {
                ans = max(ans, height[r] * width);
                --r;
            }
        }

        return ans;
    }
};