class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) {
            return 0;
        }
        int maxLen = 0;
        
        for (int i = 1; i < n - 1; i++) {
            // Identify a peak
            if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) {
                int left = i - 1;
                int right = i + 1;
                
                // Expand down the left slope
                while (left > 0 && arr[left] > arr[left - 1]) {
                    left--;
                }
                // Expand down the right slope
                while (right < n - 1 && arr[right + 1] < arr[right]) {
                    right++;
                }

                maxLen = max(maxLen, right - left + 1);
                
                // Fast-forward i to the end of the right slope
                i = right;
            }
        }
        return maxLen;
    }
};