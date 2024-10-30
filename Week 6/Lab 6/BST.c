/*
Logan Jordan - 10/29/24
BST.c: Binary search tree implementation
*/

#include "BST.h"

/*
initBST: initialize BST members
param1: tree
pre: tree is not null
post: nodeCount is 0
post: root is null
*/
void initBST(struct BST *tree) {
    assert(tree != NULL);

    tree->root = NULL;
	tree->nodeCount  = 0;
}

/*
getLeftMostValue: iterative helper function to find the left most child of a node
param: curr the current node
pre: curr is not null
post: return the value of the left most child of curr
*/
TYPE getLeftMostValue(struct Node *curr) {
	assert(curr != NULL);

    while(curr->left != NULL) {
        curr = curr->left;
    }

    return curr->val;
}

/*
addBST: iterative function to add a value to a binary search tree
param1: tree - the binary search tree
param2: val	- the value to be added to the tree
pre: tree is not null
post: nodeCount is incremented
post: memory is dynamically allocated to a new node
post: new node has value specified by parameter
post: left and right pointers of new node are NULL
post: prev pointer points to new node
post: tree contains one new node - pointers have been updated
*/
void addBST(struct BST *tree, TYPE val) {
    printf("Adding %d \n", val);
    assert(tree != NULL);

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    struct Node *curr = tree->root;
    struct Node *prev = curr;

    while(curr != NULL) {
        prev = curr;
        if(val < curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if(curr == tree->root) {
        tree->root = newNode;
    } else if(val < prev->val) {
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }

    tree->nodeCount++;
}

/*
containsBST: iterative function to determine if the binary search tree contains an element
param1: tree the BST
param2: val	- the value to search for in the tree
return: return 1 if the tree contains the value, otherwise return 0
pre: tree is not null
post: no changes to the BST
*/
int containsBST(struct BST *tree, TYPE val) {
    assert(tree != NULL);

    struct Node *curr = tree->root;

    while(curr != NULL) {
        if (val == curr->val) {
            return 1;
        } else if (val < curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return 0;
}

/*
removeBST: iterative function to remove a value from the BST
param1: tree - the BST
param2: val	- the value to be removed from the tree
pre: tree is not null
pre: val is in the tree
post: nodeCount is decremented
post: node has been freed
post: link is removed from the BST - pointers updated
*/
void removeBST(struct BST *tree, TYPE val) {
	printf("Remove %d \n", val);
	assert(tree != NULL);
	assert(containsBST(tree, val));

    struct Node *curr = tree->root;
    struct Node *prev = NULL;

    while(curr->val != val) {
        prev = curr;
        if (val < curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if(curr->left == NULL && curr->right == NULL) {
        if(prev->left == curr) {
            prev->left = NULL;
        } else {
            prev->right = NULL;
        }
    } else if(curr->right == NULL) {
        if(prev->left == curr) {
            prev->left = curr->left;
        } else {
            prev->right = curr->left;
        }
    } else if(curr->left == NULL) {
        if(prev->right == curr) {
            prev->right = curr->right;
        } else {
            prev->left = curr->right;
        }
    } else {
        curr->val = getLeftMostValue(curr->right);
        prev = curr;
        curr = curr->right;
        while(curr->left != NULL) {
            prev = curr;
            curr = curr->left;
        }
        if(prev->left == curr) {
            prev->left = curr->right;
        } else {
            prev->right = curr->right;
        }
    }

    free(curr);
    curr = 0;
    tree->nodeCount--;
}

/*
freeBST: function to delete a BST
param: tree a binary search tree
pre: tree not null
post: tree is freed
post: all memory for the BST and nodes is freed, function calls _freeNodes
*/
void freeBST(struct BST *tree) {
    assert(tree != NULL);

	_freeNodes(tree->root);
	free(tree);
	tree = 0;
}

/*
_freeNodes: recursive function to free the nodes of a binary search tree
param: curr - the root node of the tree to be freed
pre: tree is not null
post: node and all descendants are deallocated
HINT: free the nodes using a post-order traversal
*/
void _freeNodes(struct Node *curr) {
	if(curr == NULL) {
        return;
	}
    _freeNodes(curr->left);
    _freeNodes(curr->right);
    free(curr);
    curr = 0;
}

/*
inorderTraversal: inorder traversal of tree left-node-right
param: curr - the current node
pre: curr is not null
post: in-order traversal is printed
*/
void inorderTraversal(struct Node *curr) {
    if(curr == NULL) {
        return;
    }
    inorderTraversal(curr->left);
    printf("%d ", curr->val);
    inorderTraversal(curr->right);
}
