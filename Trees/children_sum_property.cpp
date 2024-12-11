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

void convertTreeToChildrenSumProperty(sNode* root) {
    queue<sNode*> q;

    q.push(root);

    vector<sNode*> ans;

    while (!q.empty()) {
        int qSize = q.size();
        int curChildrenSum = 0;
        for (int  i = 0; i < qSize; i++) {
            sNode* cNode = q.front();
            q.pop();
            ans.push_back(cNode);

            if (cNode->left) {
                curChildrenSum += cNode->left->data;
            }
            if (cNode->right) {
                curChildrenSum += cNode->right->data;
            }
            if (curChildrenSum < cNode->data && cNode->left && cNode->right) {
                cNode->left->data = cNode->data;
                cNode->right->data = cNode->data;
                q.push(cNode->left);
                q.push(cNode->right);
            }
            else if (curChildrenSum >= cNode->data && cNode->left && cNode->right) {
                cNode->left->data = curChildrenSum;
                cNode->right->data = curChildrenSum;
                q.push(cNode->left);
                q.push(cNode->right);
            }   
        }
    }

    for (int i = ans.size()-1; i > 0; i-=2) {
        // since left child = 2*i and right child = 2*i+1 if parent = i
        ans[(i/2)-1]->data = ans[i]->data + ans[i-1]->data; 
    }
    printf("Updated BT for child sum property :>> ");
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i]->data << " ";
    }
}


int main() {
    int arr[] = {50, 7, 2, 3, 5, 1, 30};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);

    convertTreeToChildrenSumProperty(root);

    printf("\n");
} 