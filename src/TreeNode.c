#include "TreeNode.h"

#include <stdlib.h>
#include <stdio.h>



struct TreeNode {
    int data;
    struct TreeNode* parent;    // Pointer to parent node
    struct TreeNode** children; // Array of pointers to children
    int numChildren;            // Current number of children
    int maxChildren;            // Maximum number of children (aryness)
};

struct TreeNode* createNode(int data, int maxChildren) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->numChildren = 0;
    newNode->maxChildren = maxChildren;
    newNode->children = (struct TreeNode**)malloc(maxChildren * sizeof(struct TreeNode*));
    for (int i = 0; i < maxChildren; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int data, int maxChildren, int currentHeight, int maxHeight) {
    if (currentHeight >= maxHeight) {
        return NULL; // Stop if maximum height is reached
    }

    if (root == NULL) {
        return createNode(data, maxChildren);
    }

    if (root->numChildren < root->maxChildren) {
        root->children[root->numChildren] = createNode(data, maxChildren);
        root->numChildren++;
    } else {
        // Recursively insert into a child node
        insertNode(root->children[root->numChildren - 1], data, maxChildren, currentHeight + 1, maxHeight);
    }
    return root;
}


struct TreeNode* growTree(struct TreeNode* root, int data, int maxChildren, int maxHeight) {
    return insertNode(root, data, maxChildren, 0, maxHeight);
}


void printTree(struct TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }
    // Print the current node
    printf("%*s%d\n", level * 4, "", root->data); // Indentation for visualization

    // Recurse for each child
    for (int i = 0; i < root->numChildren; i++) {
        printTree(root->children[i], level + 1);
    }
}



