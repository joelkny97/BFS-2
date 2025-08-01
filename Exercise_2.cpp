// Time Complexity: O(N) where N is the number of nodes in the tree
// Space Complexity: O(N) for the queue used in BFS
// Were you able to solve the problem on Leetcode?: Yes
// Did you face any challenges while solving the problem? No

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {

        if(root == nullptr) {
            return false;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        bool x_found = false, y_found = false;


        // BFS traversal
        // we will check if x and y are at the same level
        while(!q.empty()) {

            // get the size of the current level
            // and iterate through each node at that level
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // if current node has both left and right children
                // and they are x and y, then they are siblings, not cousins
                // so we return false
                if(curr->left != nullptr && curr->right != nullptr) {
                    if((curr->left->val == x && curr->right->val == y) || (curr->right->val == x && curr->left->val == y)) return false;
                }
                
                // if we find x or y, we set the respective flag to true
                if(curr->val == x) {
                    x_found = true;
                }

                if(curr->val == y) {
                    y_found = true;
                }
                // push the left and right children to the queue
                // so that we can process them in the next level
                if(curr->left != nullptr) {
                    q.push(curr->left);
                }

                if(curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
            // if we found both x and y at the same level, they are cousins
            // if we found one of them, but not the other, they are not cousins
            // if we didn't find either of them, we continue to the next level
            if(x_found && y_found) return true;
            if(x_found || y_found) return false;
        }
        // if we reach here, it means we did find both x and y at the same level
        return true;
    }
};
