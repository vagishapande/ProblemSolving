class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currentcount =0;
        int maxcount = 0;
            for(int num : nums){
            if(num == 1){
                currentcount++;
                maxcount = max(maxcount,currentcount);
            }
            else{
                    currentcount = 0;
                }

          }
        
        return maxcount;
    }
};