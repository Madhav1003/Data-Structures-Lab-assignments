struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* search(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}
int findMax(Node* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->data;
}
int findMin(Node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->data;
}
int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));


