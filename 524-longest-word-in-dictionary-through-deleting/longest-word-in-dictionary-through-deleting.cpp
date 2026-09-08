class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](string a, string b) {
            if (a.size() != b.size()) {
                return a.size() > b.size();
            }

            return a < b;
        });

        for (string &word : dictionary) {
            int wordLength = word.size();
            int leftInput = 0; 
            int leftWord = 0;
            while (leftInput < s.size()) {
                if (s[leftInput] == word[leftWord]) {
                    leftWord++;
                }
                if (leftWord == wordLength) {
                    return word;
                }
                leftInput++;
            }
        }

        return "";
    }
};