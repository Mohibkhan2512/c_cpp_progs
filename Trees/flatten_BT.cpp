#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <cstdio>
#include <queue>
#include <stack>
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

void printBT(sNode* root) {
    queue<sNode*> q;
    q.push(root);

    while (!q.empty()) {
        sNode* cNode = q.front();
        q.pop();
        cout << cNode->data << " ";

        if (cNode->left) {
            q.push(cNode->left);
        }

        if (cNode->right) {
            q.push(cNode->right);
        }
    }
}

void flattenBT(sNode* node) {
    stack<sNode*> st;
    stack<sNode*> preOrdTraversal;
    st.push(node);

    while (!st.empty()) {
        sNode* cNode = st.top();
        st.pop();
        preOrdTraversal.push(cNode);

        // cout << "pushing node :>> " << cNode->data << " \n";

        if (cNode->right) {
            st.push(cNode->right);
        }

        if (cNode->left) {
            st.push(cNode->left);
        }
    }

    sNode* prev = preOrdTraversal.top();
    preOrdTraversal.pop();

    while (!preOrdTraversal.empty()) {
        sNode* cNode = preOrdTraversal.top();
        preOrdTraversal.pop();

        cNode->right = prev;
        cNode->left = NULL;

        prev = cNode;
    }
}


int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);

    flattenBT(root);

    printBT(root);

    printf("\n");
}