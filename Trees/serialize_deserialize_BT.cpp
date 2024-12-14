#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <cstdio>
#include <queue>
#include <sstream>
#include <string>
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

void printTree(sNode* root) {
    queue<sNode*> q;
    q.push(root);

    while (!q.empty()) {
        int qSize = q.size();

        for (int i = 0; i < qSize; i++) {
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

}

sNode* deSerializeBT(string serializedStr) {
    string str;

    stringstream s(serializedStr);
    getline(s, str, ',');

    sNode* root = new sNode(stoi(str));
    queue<sNode*> q;
    q.push(root);

    while (!q.empty()) {
        sNode* cNode = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#") {
            cNode->left = NULL;
        }
        else {
            cNode->left = new sNode(stoi(str));
            q.push(cNode->left);
        }

        getline(s, str, ',');
        if (str == "#") {
            cNode->right = NULL;
        }
        else {
            cNode->right = new sNode(stoi(str));
            q.push(cNode->right);
        }
    }

    return root;
}

string serializeBT(sNode* root) {
    string serializedStr = "";

    queue<sNode*> q;
    q.push(root);

    while (!q.empty()) {
        sNode* cNode = q.front();
        q.pop();

        if (cNode) {
            serializedStr.append(to_string(cNode->data) + ",");
        }
        else {
            serializedStr.append("#,");
        }

        if (cNode) {
            q.push(cNode->left);
            q.push(cNode->right);
        }
    }

    return serializedStr;
}


int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);

    string serializedStr = serializeBT(root);
    cout << "Serialized str for current BT :>> " << serializedStr << "\n";

    sNode* newRoot = deSerializeBT(serializedStr);

    cout << "New tree :>> ";

    printTree(newRoot);

    printf("\n");
}