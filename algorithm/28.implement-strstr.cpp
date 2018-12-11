/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (30.46%)
 * Total Accepted:    346.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;

        bool is_different = false;
        int str_len = haystack.length(), needle_len = needle.length();

        for(int i = 0; i < str_len - needle_len + 1; i++) {
            int j = 0; 
            for(; j < needle_len; j++) {
                if(haystack[i + j] != needle[j])
                    break;
            }
            if(j == needle_len)
                return i;
        }

        return -1;
    }
};
