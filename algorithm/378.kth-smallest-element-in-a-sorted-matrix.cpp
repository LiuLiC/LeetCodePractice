/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */
class Solution {
public:
    class matrixValue {
        public:
            int x, y, val;

            matrixValue(int x, int y, int val) : x(x), y(y), val(val) {}
    };

    struct comparitor{ 
        bool operator()(const matrixValue* a, const matrixValue* b){
            return a->val >= b->val;
        }
    };

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        priority_queue<matrixValue*, vector<matrixValue*>, comparitor> pq;

        for(int i = 0; i < n; i++){
            pq.push(new matrixValue(i, 0, matrix[i][0]));
        }

        for(int i = 0; i < k - 1; i++){
            matrixValue* node = pq.top();
            pq.pop();
            if(node->y == m - 1)
                continue;
            
            pq.push(new matrixValue(node->x, node->y + 1, matrix[node->x][node->y + 1]));
        }

        return pq.top()->val;
    }
};

