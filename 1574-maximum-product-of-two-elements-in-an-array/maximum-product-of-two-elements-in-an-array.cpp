class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int x = nums.size() - 2;
        int y = nums.size() - 1;

        int a = nums[x] - 1;
        int b = nums[y] - 1;

        return a * b;
    }
};