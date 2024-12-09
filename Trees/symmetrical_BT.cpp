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
            cNode->left = new sNode(arr[Idx]);
            q.push(cNode->left);
            Idx++;
        }
        if(Idx < nSize) {
            cNode->right = new sNode(arr[Idx]);
            q.push(cNode->right);
            Idx++;
        }
    }

    return root;
}

bool symmetricalBT(sNode* node) {
    sNode* lRoot = node->left;
    sNode* rRoot = node->right;

    queue<sNode*> q;

    q.push(lRoot);
    q.push(rRoot);

    while (!q.empty()) {
        sNode* LRoot = q.front();
        sNode* lChildNode_LRoot = LRoot->left;
        sNode* rChildNode_LRoot = LRoot->right;
        q.pop();
        sNode* RRoot = q.front();
        sNode* lChildNodeOf_RRoot = RRoot->left;
        sNode* rChildNodeOf_RRoot= RRoot->right;
        q.pop();

        if (lChildNode_LRoot != NULL && rChildNodeOf_RRoot != NULL) {
            if (lChildNode_LRoot->data == rChildNodeOf_RRoot->data) {
                q.push(lChildNode_LRoot);
                q.push(rChildNodeOf_RRoot);
            }    
            else {
                return false;
            }
        }
        else if (lChildNode_LRoot == NULL && rChildNodeOf_RRoot != NULL || rChildNodeOf_RRoot == NULL && lChildNode_LRoot != NULL) {
            return false;
        }

        if (rChildNode_LRoot != NULL && lChildNodeOf_RRoot != NULL) {
            if (rChildNode_LRoot->data == lChildNodeOf_RRoot->data) {
                q.push(rChildNode_LRoot);
                q.push(lChildNodeOf_RRoot);
            }
            else {
                return false;
            }
        }
        else if (rChildNode_LRoot == NULL && lChildNodeOf_RRoot != NULL || lChildNodeOf_RRoot == NULL && rChildNode_LRoot != NULL) {
            return false;
        }
    }

    return true;
}

int main() {
    int arr[] = {1,2,2,4,3,3,4};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);
    bool isSymmetric = symmetricalBT(root);

    cout << "Given BT is symmetric :>> " << isSymmetric;

    printf("\n");
}