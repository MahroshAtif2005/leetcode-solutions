class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window
       unordered_set<char> seen;
       int left = 0;
       int right = 0;
       
       int maxWindow = 0;
       while(right<s.size()){
         while(seen.count(s[right])){
           seen.erase(s[left]);
           left++;
         }  
        seen.insert(s[right]);
        maxWindow = max(maxWindow,right-left+1);
        right++;
       }
       return maxWindow;
    }
};