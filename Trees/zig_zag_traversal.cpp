#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <cstdio>
#include <queue>
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

void zigZagTraversal(sNode* node, int& maxSum){
    vector<vector<int> > result;
    queue<sNode*> q;
    q.push(node);

    bool travelDir = 0; // 0 -> L to R and 1 -> R to L

    while (!q.empty()) {
        int qSize = q.size();
        vector<int> row(qSize);

        for (int i = 0; i < qSize; i++) {
            sNode* cNode = q.front();
            q.pop();

            if (cNode->left) {
                q.push(cNode->left);
            }
            if (cNode->right) {
                q.push(cNode->right);
            }

            int eleIdx = travelDir == 0 ? i : (qSize - i - 1);
            row[eleIdx] = cNode->data;
        }
        travelDir = !travelDir;
        result.push_back(row);
    }

    cout << "Zig-Zag of BT :>> \n";
    for (auto it : result){
        for(auto i : it){
            cout << i << " ";
        }
        cout << "\n";
    }

}

int main() {
    int arr[] = {1,2,3,4,5, 6, 7, 8, 9};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);
    static int maxSum;

    zigZagTraversal(root, maxSum);

    printf("\n");
}