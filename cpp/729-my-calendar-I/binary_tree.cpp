
class MyCalendar {
    class TreeNode {
    public:
        TreeNode(int start, int end): start(start), end(end), left(NULL), right(NULL) {}

        int start;
        int end;
        TreeNode* left;
        TreeNode* right;
    };

public:
    MyCalendar() {}

    bool book(int start, int end) {
        if (this->root == NULL) {
            this->root = new TreeNode(start, end);
            return true;
        }

        TreeNode* queryNode = this->root;
        while (queryNode != NULL) {
            if (end <= queryNode->start) {
                if (queryNode->left) {
                    queryNode = queryNode->left;
                } else {
                    queryNode->left = new TreeNode(start, end);
                    return true;
                }
            } else if (start >= queryNode->end) {
                if (queryNode->right) {
                    queryNode = queryNode->right;
                } else {
                    queryNode->right = new TreeNode(start, end);
                    return true;
                }
            } else {
                return false;
            }
        }
    }

    TreeNode* root = NULL;
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
