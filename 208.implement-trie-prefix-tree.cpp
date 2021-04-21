/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
struct node {
    char value;
    forward_list<node*> childs;
    bool isword;
    node() {
        value = '/';
        this->isword = false;
    }
};

class Trie {
    node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new node;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        node* now = root;
        for (auto c : word) {
            bool flag = false;
            for (auto child : now->childs) {
                if (child->value == c) {
                    flag = true;
                    now = child;
                    break;
                }
            }
            if (!flag) {
                node* new_node = new node;
                new_node->value = c;
                now->childs.insert_after(now->childs.before_begin(), new_node);
                now = new_node;
            }
        }
        now->isword = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* now = root;
        bool res = false;
        for (auto c : word) {
            bool flag = false;
            for (auto child : now->childs) {
                if (child->value == c) {
                    flag = true;
                    now = child;
                    break;
                }
            }
            if (!flag) {
                return false;
            }
        }
        if (now->isword)
            return true;
        else
            return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* now = root;
        bool res = false;
        for (auto c : prefix) {
            bool flag = false;
            for (auto child : now->childs) {
                if (child->value == c) {
                    flag = true;
                    now = child;
                    break;
                }
            }
            if (!flag) {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

