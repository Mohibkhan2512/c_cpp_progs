#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <cstdio>
#include <queue>
using namespace std;

struct sNode {
    int data;
    sNode* left;
    sNode* right;
    sNode(int curData) {
        data = curData;
        left = NULL;
        right = NULL;
    }
};

sNode* createTree(int arr[], int nSize) {
    sNode* root = new sNode(arr[0]);
    int Idx = 1;

    queue<sNode*> q;

    q.push(root);

    while (!q.empty()) {
        sNode* cNode = q.front();
        q.pop();

        if(Idx < nSize) {
            if (arr[Idx] == 0) {
                cNode->left = NULL;
                Idx++; 
            } else {
                cNode->left = new sNode(arr[Idx]);
                q.push(cNode->left);
                Idx++;
            }
        }
        if(Idx < nSize) {
            if (arr[Idx] == 0) {
                cNode->right = NULL;
                Idx++; 
            } else {
                cNode->right = new sNode(arr[Idx]);
                q.push(cNode->right);
                Idx++;
            }
        }
    }

    return root;
}

void printBST(sNode* root) {
    queue<sNode*> q;
    q.push(root);

    while (!q.empty()) {
        sNode* cNode = q.front();
        cout << cNode->data << " ";
        q.pop();

        if (cNode->left) {
            q.push(cNode->left);
        }

        if (cNode->right) {
            q.push(cNode->right);
        }
    }
}

sNode* findGreatestLMC(sNode* node) {
    while (node->right) {
        node = node->right;
    }
    return node;
}

sNode* updatedTree(sNode* curRoot) {
    if (curRoot->left == NULL) {
        return curRoot->right;
    }
    if (curRoot->right == NULL) {
        return curRoot->left;
    }

    sNode* rightChild = curRoot->right;
    sNode* leftChild = curRoot->left;
    sNode* greatestLeftMostChild = findGreatestLMC(leftChild);

    cout << "leftChild :>> " << leftChild->data << "\n";
    cout << "greatestLeftMostChild :>> " << greatestLeftMostChild->data << "\n";

    greatestLeftMostChild->right = rightChild;

    return leftChild;
}


sNode* deleteNodeFromBST(sNode* root, int valueToBeDeleted) {
    sNode* rootCopy = root;

    if (root->data == valueToBeDeleted) {
        root->left = updatedTree(root->right);
        return root;
    }
    
    while (root) {
        if (valueToBeDeleted < root->data) {
            if (root->left != NULL && root->left->data == valueToBeDeleted) {
                root->left = updatedTree(root->left);
                break;
            }
            else {
                root = root->left;
            }
        }
        else if (valueToBeDeleted > root->data) {
            if (root->right != NULL && root->right->data == valueToBeDeleted) {
                root->right = updatedTree(root->right);
                break;
            }
            else {
                root = root->right;
            }
        }
    }

    return rootCopy;
}


int main() {
    int arr[] = {9,8,12,5, 0,10,13,3,7,0,0,0,0,2,4,6,8};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);

    cout << "BST before deletion :>> " ;
    printBST(root);
    printf("\n");

    int valueToBeDeleted = 5;

    sNode* updatedTreeRoot = deleteNodeFromBST(root, valueToBeDeleted);

    cout << "BST after deletion :>> " ;

    printBST(updatedTreeRoot);

    printf("\n");
}