/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (24.35%)
 * Total Accepted:    331.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n){
            int temp = m; m = n; n = temp;
            vector<int> vtemp = nums1; nums1 = nums2; nums2 = vtemp;
        }

        int imin = 0, imax = m;
        
        while(imin <= imax){
            int i = (imin + imax) / 2;
            int j = (m + n + 1) / 2 - i;

            /* 
             * With "+ 1", left side will have one more number than right side.
             * So when m + n is odd, we return max left number;
             * Without "+ 1", right side will have one more number than left side.
             * So when m + n is odd, we return min right number.
             */

            if(i > 0 && nums1[i - 1] > nums2[j]){
                imax = i - 1;
            }
            else if(i < m && nums1[i] < nums2[j - 1]){
                imin = i + 1;
            }
            else{
                int max_left;
                if(i == 0) max_left = nums2[j - 1];
                else if(j == 0) max_left = nums1[i - 1];
                else max_left = max(nums1[i - 1], nums2[j - 1]);

                if((m + n) % 2 == 1)
                    return max_left;
                
                int min_right;
                if(i == m) min_right = nums2[j];
                else if(j == n) min_right = nums1[i];
                else min_right = min(nums1[i], nums2[j]);
                
                return (max_left + min_right) / 2.0;
            }
        }
    }
};
