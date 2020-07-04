vector<int> Solution::preorderTraversal(TreeNode* root) {
    stack<TreeNode*>s;
    vector<int>ans;
    if (root == NULL) {
        return ans;
    }
    while (root) {
        ans.push_back(root->val);
        s.push(root);
        root = root->left;
    }
    while (!s.empty()) {
        TreeNode* f = s.top();
        s.pop();
        f = f->right;
        while (f) {
            ans.push_back(f->val);
            s.push(f);
            f = f->left;
        }
    }
    return ans;
}