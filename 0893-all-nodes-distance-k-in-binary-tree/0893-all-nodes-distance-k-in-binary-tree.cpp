/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track ; //to keep track of parent node and child node
        queue<TreeNode*> queue1 ; //To mark all the parent and child nodes
        queue1.push(root);
        while(!queue1.empty()){
            TreeNode* curr = queue1.front();
            queue1.pop();
            if(curr->left)
            { 
                queue1.push(curr->left);
                parent_track[curr->left] = curr;
            } 
            if(curr->right){
                queue1.push(curr->right);
                parent_track[curr->right] = curr;
            }       
        }
        queue<TreeNode*> q ; // for BFS Traversal
        unordered_map<TreeNode*,bool> vis ; //To keep track of visited nodes ;
        vis[target] = true;
        q.push(target) ;
        int curr_level = 0; 
        while(!q.empty()){
            if(curr_level++ == k)
            break; 
            int curr_size = q.size();
            for(int i = 0;i<curr_size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && vis[curr->left]==false){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                 if(curr->right && vis[curr->right]==false){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(parent_track[curr] && vis[parent_track[curr]]==false){
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = true;
                }

            } 
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
      return ans;
    }
};