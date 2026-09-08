class Solution {
public:
    vector<double>pre;
    vector<vector<double>>dp;
    double avg(int i,int j){
        return (pre[j+1]-pre[i])/(j-i+1);
    }
    double f(vector<int>&nums,int i,int k){
        int n = nums.size();
        if(dp[i][k] >= 0) return dp[i][k];
        if(k == 1) return dp[i][k] = avg(i,n-1);
        double ans = 0;
        for(int j=i;j<=n-k;j++){
            ans = max(ans,avg(i,j)+f(nums,j+1,k-1));
        }
        return dp[i][k] = ans;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        pre.resize(n+1);
        dp.resize(n+1,vector<double>(k+1,-1));
        for(int i=0;i<n;i++) pre[i+1] = pre[i] + nums[i];
        return f(nums,0,k);
    }
};