/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<vector<NestedInteger>::iterator> nodes;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if(nestedList.size() != 0){
            for(auto it = nestedList.end() - 1, ite = nestedList.begin();
            it >= ite; it--){
                nodes.push(it);
            }
        }
    }

    int next() {
        int val = nodes.top()->getInteger();
        nodes.pop();
        return val;
    }

    bool hasNext() {
        while(!nodes.empty()){
            auto cur = nodes.top();
            if(cur->isInteger())
                return true;

            nodes.pop();
            vector<NestedInteger>& v = cur->getList();
            if(v.size() == 0)
                continue;
            for(auto it = v.end() - 1; it >= v.begin(); it--){
                nodes.push(it);
            }
        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

