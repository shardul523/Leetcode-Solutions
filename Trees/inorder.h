#include <vector>
#include <stack>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
    TreeNode (int x, TreeNode *l, TreeNode *r): val(x), 
    left(l), right(r) {};
};


class Solution {
    public:
    std::vector<int> inorderTraversal(TreeNode *root) {
        
        std::vector<int> inorder;
        
        if (!root) 
            return inorder;
        
        std::stack<TreeNode*> st;
        TreeNode* curr = root;

        while (!st.empty() || curr) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            inorder.emplace_back(curr->val);
            curr = curr->right;
        }

        return inorder;
    }
};


TreeNode* node1 = new TreeNode(3);
TreeNode* node2 = new TreeNode(2, node1, nullptr);
TreeNode* node3 = new TreeNode(1, nullptr, node2);


