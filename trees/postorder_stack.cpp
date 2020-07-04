vector<int> Solution::postorderTraversal(TreeNode* root) {
    stack<TreeNode*>s;
    vector<int>ans;
    if (root == NULL) {
        return ans;
    }
    while (root) {
        s.push(root);
        root = root->left;
    }

    TreeNode* prev = NULL;
    while (!s.empty()) {
        TreeNode* f = s.top();
        if (!f->right or f->right == prev) {
            ans.push_back(f->val);
            prev = f;
            s.pop();
        }
        else {
            f = f->right;
            while (f) {
                s.push(f);
                f = f->left;
            }
        }
    }
    return ans;
}