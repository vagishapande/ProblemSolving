class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if(m > n){
            return minDistance(word2, word1);
        }

        vector<int> dp(m + 1, 0);

        for(int i = 1; i <= n; i++){
            int prev = 0;

            for(int j = 1; j <= m; j++){
                int temp = dp[j];

                if(word1[i - 1] == word2[j - 1]){
                    dp[j] = 1 + prev;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }

                prev = temp;
            }
        }

        return n + m - 2 * dp[m];
    }
};