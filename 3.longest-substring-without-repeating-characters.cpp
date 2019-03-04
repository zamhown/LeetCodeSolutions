/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (26.08%)
 * Total Accepted:    739.9K
 * Total Submissions: 2.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    static int max(int a, int b){
        if(a<b)
            return b;
        else
            return a;
    }
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int re = 0, max = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            for(int j=start; j<i; j++){
                if(s[j]==s[i]){
                    start = j+1;
                    re = Solution::max(j-start+1, i-j-1);
                    break;
                }
            }
            re++;
            max = Solution::max(max,re);
        }
        return max;
    }
};
