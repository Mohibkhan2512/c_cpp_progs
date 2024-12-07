#include <iostream>
#include <cstddef>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
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

vector<int> printTreeDFS_PreOrder_itr(sNode* node) {
    vector<int> preOrderTraversal;

    if (node == NULL) {
        return preOrderTraversal;
    }

    stack<sNode*> st;
    st.push(node);

    while (!st.empty()) {
        sNode* cNode = st.top();
        st.pop();

        cout << cNode->data << " ";

        if (cNode->right) {
            st.push(cNode->right);
        }
        if (cNode->left) {
            st.push(cNode->left);
        }
    }

    return preOrderTraversal;
    
}

vector<int> printTreeDFS_InOrder_itr(sNode* node) {
    vector<int> inOrder;
    if (node == NULL) {
        return inOrder;
    }

    stack<sNode*> st;
    
    while (true) {
        if (node != NULL) {
            st.push(node);
            node = node->left;
        }
        else {
            if (st.empty()) {
                break;
            }
            node = st.top();
            cout << node->data << " ";
            st.pop();
            inOrder.push_back(node->data);
            node = node->right;
        }
    }
    return inOrder;
}

void printTreeDFS_PostOrder_itr(sNode* node) {
    if (node == NULL) {
        return;
    }
}

int main() {
    int arr[] = {1,2,3,4,5, 6, 7};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);

    cout << "Cur Tree DFS Pre Order :>> ";
    printTreeDFS_PreOrder_itr(root);
    printf("\n");

    cout << "Cur Tree DFS In Order :>> ";
    printTreeDFS_InOrder_itr(root);
    printf("\n");

    cout << "Cur Tree DFS Post Order:>> ";
    printTreeDFS_PostOrder_itr(root);
    printf("\n");
}