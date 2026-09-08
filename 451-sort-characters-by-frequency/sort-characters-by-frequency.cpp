class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> v;
        map<char, int> mpp;

        // Count frequency of each character
        for (char c : s) {
            mpp[c]++;
        }

        // Store (character, frequency)
        for (const auto& [key, value] : mpp) {
            v.push_back({key, value});
        }

        // Sort by frequency in ascending order
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        string o = "";

        // Traverse from highest frequency to lowest
        for (int i = v.size() - 1; i >= 0; i--) {
            for (int j = 0; j < v[i].second; j++) {
                o += v[i].first;
            }
        }

        return o;
    }
};