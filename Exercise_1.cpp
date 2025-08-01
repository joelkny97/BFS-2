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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) {
            return result;
        }
        

        std::queue<TreeNode*> q;
        q.push(root);

        // BFS traversal
        // at each level, we will add the last node's value to the result
        // this will give us the rightmost view of the tree
        while(!q.empty()){
            // get the size of the current level
            int size = q.size();

            // iterate through the current level
            // and push the last node's value to the result
            for(int i = 0; i < size; i++){
                
                TreeNode* curr = q.front();
                q.pop();
                if(i == size - 1){
                    result.push_back(curr->val);
                }
                // push the left and right children to the queue
                // so that we can process them in the next level
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }

        return result;
    }
};
