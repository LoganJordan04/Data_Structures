/*
Logan Jordan - 10/31/24
bst.c: Binary search tree implementation using recursion
*/

#include "bst.h"

/*
initBSTree: initialize BST members
param1: tree
pre: tree is not null
post: sz is 0
post: root is null
*/
void initBSTree(struct BSTree *tree) {
    assert(tree != NULL);

	tree->sz  = 0;
	tree->root = NULL;
}

/*
isEmptyBSTree: function to determine if  a binary search tree is empty
param: tree - the BST
return: return 1 if the tree is empty, otherwise return 0
pre: tree is not null
post: no changes to the BST
*/
int isEmptyBSTree(struct BSTree *tree) {
    assert(tree != NULL);

    if (tree->root == NULL) {
        return 1;
    }
    return 0;
}

/*
sizeBSTree: function to determine the size of a binary search tree
param: tree - the BST
return: return the size of the tree
pre: tree is not null
post: no changes to the BST
*/
int sizeBSTree(struct BSTree *tree) {
    assert(tree != NULL);

    return tree->sz;
}

/*
freeBSTree: function to clear the nodes of a binary search tree
param: tree a binary search tree
pre: tree not null
post: tree is freed
function calls _freeNodes to free the nodes
*/
void freeBSTree(struct BSTree *tree) {
    assert(tree != NULL);

	_freeNodes(tree->root);
	tree->root = NULL;
	free(tree);
	tree = 0;
	printf("tree freed \n");
}

/*
_freeBST: recursive helper function to free the nodes of a binary search tree
param: node - the root node of the tree to be freed
pre: none
post: node and all descendants are freed
called by freeBSTree()
*/
void _freeNodes(struct Node *node) {
	if(node == NULL) {
        return;
	}

    _freeNodes(node->left);
    _freeNodes(node->right);
    free(node);
}

/*
leftMostValue: recursive helper function to find the left most child of a node
param: curr - the current node
return: the value of the left most child of curr
pre: none
post: no changes to the tree
used in certain delete cases
*/
TYPE _leftMostValue(struct Node *curr) {
   if(curr->left == NULL) {
        return curr->val;
   }
   return _leftMostValue(curr->left);
}

/*
addBSTree: function to add a value to the binary search tree
param1: tree - the binary search tree
param2: val	- the value to be added to the tree
pre: tree is not null
post: sz is incremented
post: tree contains one new node
_addNode handles the actual add
 */
void addBSTree(struct BSTree *tree, TYPE val) {
    assert(tree != NULL);

    tree->root = _addNode(tree->root, val);
    tree->sz++;
}

/*
_addNode: recursive function to add a value to a BST
param1: curr - the current node
param2: val	- the value to be added to the tree
pre: none
return: curr - the root of a BST with a new leaf added
post: memory is allocated for a new node
post: new node contains specified value
post new node left and right pointers are NULL
post: a new node is added the tree
*/
struct Node *_addNode(struct Node *curr, TYPE val) {
    if (curr == NULL) {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (val < curr->val) {
        curr->left = _addNode(curr->left, val);
    } else {
        curr->right = _addNode(curr->right, val);
    }

    return curr;
}

/*
containsBSTree: function to determine if the binary search tree contains an element
param1: tree the BST
param2: val	- the value to search for in the tree
return : return 1 if the tree contains the value, otherwise return 0
pre: tree is not null
post: no changes to the BST
calls _contains
 */
int containsBSTree(struct BSTree *tree, TYPE val) {
    assert(tree != NULL);

	return _containsNode(tree->root, val);
}

/*
_containsNode: recursive function checks for the value in a binary search tree
param1: curr - the current node
param2: val	- the value to be removed from the tree
ret: return 1 if found, otherwise return 0
pre: none
post: no changes to the BST
*/
int _containsNode(struct Node *curr, TYPE val) {
    if (curr == NULL) {
        return 0;
    }

    if (val == curr->val) {
        return 1;
    } else if (val < curr->val) {
        return _containsNode(curr->left, val);
    } else {
        return _containsNode(curr->right, val);
    }
}

/*
removeBSTree: function to remove a value from the BST
param1: tree - the BST
param2: val	- the value to be removed from the tree
pre: tree is not null
pre: val is in the tree
post: sz is decremented
post: link is removed from the BST
calls _removeNode
*/
void removeNodeFromTree(struct BSTree *tree, TYPE val) {
	assert(tree != NULL);
	assert(containsBSTree(tree, val));

    tree->root = _removeNode(tree->root, val);
    tree->sz--;
}

/*
_removeNode: recursive helper function which removes a node from a BST
param1: curr - the current node
param1: val - the value to be removed from the tree
pre: none
post: link containing the value is freed
post: node containing val is removed from the tree and subtrees are updated
*/
struct Node *_removeNode(struct Node *curr, TYPE val) {
	if (curr == NULL) {
	    return NULL;
	}

    if (val < curr->val) {
        curr->left = _removeNode(curr->left, val);
    } else if (val > curr->val) {
        curr->right = _removeNode(curr->right, val);
    } else {
        /* Node with one subtree or is a leaf */
        if (curr->left == NULL) {
            struct Node *temp = curr->right;
            free(curr);
            return temp;
        } else if (curr->right == NULL) {
            struct Node *temp = curr->right;
            free(curr);
            return temp;
        }

        /* Node has two subtrees. Get the inorder successor */
        TYPE tempVal = _leftMostValue(curr->right);
        curr->val = tempVal;
        curr->right = _removeNode(curr->right, tempVal);
    }

	return curr;
}

/*
inorderTraversal: inorder traversal of tree left-node-right
param: curr - the current node
pre: none
post: in-order traversal s printed
*/
void inorderTraversal(struct Node *curr) {
    if (curr == NULL) {
        return;
    }
    inorderTraversal(curr->left);
    printf("%.1f ", curr->val);
    inorderTraversal(curr->right);
}

/*
preorderTraversal: inorder traversal of tree node-left-right
param: curr - the current node
pre: none
post: pre-order traversal s printed
*/
void preorderTraversal(struct Node *curr) {
    if (curr == NULL) {
        return;
    }
    printf("%.1f ", curr->val);
    preorderTraversal(curr->left);
    preorderTraversal(curr->right);
}

/*
postorderTraversal: post-order traversal of tree left-right-node
param: curr - the current node
pre: none
post: post-order traversal s printed
*/
void postorderTraversal(struct Node *curr) {
    if (curr == NULL) {
        return;
    }
    postorderTraversal(curr->left);
    postorderTraversal(curr->right);
    printf("%.1f ", curr->val);
}
