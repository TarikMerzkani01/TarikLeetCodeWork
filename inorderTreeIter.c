/**
 * Definition for a binary tree node.

 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct TreeNode {
    int val;
    `struct TreeNode *left;
    struct TreeNode *right;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL) return NULL;  
    // returns Empty array
    // From here, tree is non-empty
    // Create stack to emulate recursion
    int mycurSize = 0;
    int myplace[100] = {128};   //and with 128 to see if empty
    
    // stack stuff
    struct TreeNode* theStack[100] = {NULL};
    int top = -1;

    struct TreeNode* theptr;
    theptr = root;
    // push operation
    // we push the root node
    // Push operation looks like:

    // Pop operation looks like:
    // mynode = theStack[top];
    // theStack[top--] = NULL;
    
    //We only add to myplace and returnSize when current is NULL (no left)

    // we can now start the while loop knowing that
    // stack always starts non-empty
    //
    // end condition: theStack will never be empty until all nodes are processed?
    // untrue, returning to the root node will cause stack to be temp empty
    // which renders the entire right subtree untraversable

    // Thus, the information state of theptr is also considered
    while (theptr != NULL || theStack[0] != NULL) {
        if (theptr != NULL) { //traverse left until NULL
            theStack[++top] = theptr;
            theptr = theptr->left;
        }            
        else {
            //pop item, add popped item then make ptr = poppeditem.right
            //pop item
            struct TreeNode* mynode = theStack[top];
            theStack[top--] = NULL;
            //add item
            myplace[mycurSize++] = mynode->val;    // place int at idx

            //traverse right
            theptr = mynode->right;
        }
    }
    int* result = malloc((mycurSize)*4);
    for(int i = 0; i < mycurSize; i++) {
        result[i] = myplace[i];
    }
    *returnSize = mycurSize;
    return result;
}

