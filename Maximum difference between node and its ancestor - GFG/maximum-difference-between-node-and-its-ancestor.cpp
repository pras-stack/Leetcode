//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


int maxDiff(Node *root);

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


int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ;
        getline(cin, s);
        Node* root = buildTree(s);
        
        cout<<maxDiff(root)<<endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

/* Recursive function to calculate maximum ancestor-node
   difference in  binary tree. It updates value at 'res'
   to store the result.  The returned value of this function
   is minimum value in subtree rooted with 't' */
int maxDiffUtil(Node* t, int* res)
{
    /* Returning Maximum int value if node is not
       there (one child case)  */
    if (t == NULL)
        return INT_MAX;
 
    /* If leaf node then just return node's value  */
    if (t->left == NULL && t->right == NULL)
        return t->data;
 
    /* Recursively calling left and right subtree
       for minimum value  */
    int val = min(maxDiffUtil(t->left, res),
                  maxDiffUtil(t->right, res));
 
    /* Updating res if (node value - minimum value
       from subtree) is bigger than res  */
    *res = max(*res, t->data - val);
 
    /* Returning minimum value got so far */
    return min(val, t->data);
}


//Function to return the maximum difference between any node and its ancestor.
int maxDiff(Node* root)
{
    // Initialising result with minimum int value
    int res = INT_MIN;
 
    maxDiffUtil(root, &res);
 
    return res;
}
