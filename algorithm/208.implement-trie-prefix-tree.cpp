/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (36.15%)
 * Total Accepted:    157.7K
 * Total Submissions: 435.1K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */
class Trie {
public:
    class TrieNode {
        private:
            vector<TrieNode*> links;
            bool is_end;
        public:
            TrieNode() : is_end(false) {
                links = vector<TrieNode*>(26, NULL);
            }

            bool containKey(char c){
                return links[c - 'a'] != NULL;
            }

            TrieNode* get(char c){
                return links[c - 'a'];
            }

            void set(char c, TrieNode* node){
                links[c - 'a'] = node;
            }

            bool isEnd(){
                return is_end;
            }

            void setEnd(){
                is_end = true;
            }
    };

private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(!cur->containKey(c)){
                cur->set(c, new TrieNode());
            }
            cur = cur->get(c);
        }

        cur->setEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(!cur->containKey(c)){
                return false;
            }

            cur = cur->get(c);
        }

        if(cur->isEnd())
            return true;
        else
            return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i = 0; i < prefix.size(); i++){
            char c = prefix[i];
            if(!cur->containKey(c)){
                return false;
            }

            cur = cur->get(c);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
