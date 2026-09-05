class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a,      const std::vector<int>& b) {
            return a[0] < b[0];
        });
        int end=intervals[0][1];
        int start=intervals[0][0];
        vector<vector<int>> merge;

        for(int i=1;i<intervals.size();i++){
            if(end >= intervals[i][0]){
                end=max(end,intervals[i][1]);
            }else{
                vector<int>temp;
                temp.push_back(start);
                temp.push_back(end);
                merge.push_back(temp);
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }

        vector<int>temp;
        temp.push_back(start);
        temp.push_back(end);
        merge.push_back(temp);


        return merge;
    }
};