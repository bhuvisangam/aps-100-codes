#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
void leftTraverse(Node* root,vector<int>& a)
{
    if((root==NULL)|| (root->left==NULL && root->right==NULL))
    {
        return;
    }
    a.push_back(root->data);
    if(root->left)
    leftTraverse(root->left,a);
    else
    leftTraverse(root->right,a);
}
void leafTraverse(Node* root,vector<int>& a)
{
   if(root==NULL)
    {
        return;
    }
    if (root->left==NULL && root->right==NULL)
    {
        a.push_back(root->data);
        return;
    }
    leafTraverse(root->left,a);
    leafTraverse(root->right,a);
}
void rightTraverse(Node* root,vector<int>& a)
{
    if((root==NULL)|| (root->left==NULL && root->right==NULL))
    {
        return;
    }
    if(root->right)
    rightTraverse(root->right,a);
    else
    rightTraverse(root->left,a);
    a.push_back(root->data);
}
    vector <int> boundary(Node *root)
    {
        vector<int>a;
        if(root==NULL)
        return a;
        a.push_back(root->data);
        //traverse left
        leftTraverse(root->left,a);
        leafTraverse(root->left,a);
        leafTraverse(root->right,a);
        rightTraverse(root->right,a);
        return a;
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
