class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window
        int left = 0;
        int right = 0;
        int longestSubstring = 0;
        unordered_set<int> seen;
        while(right<s.size()){
            while(seen.count(s[right])){
               seen.erase(s[left]);
               left++;
            }
            seen.insert(s[right]);
            longestSubstring = max(longestSubstring , right-left+1);
            right++;
        }
        return longestSubstring;
    }
};