//Q1.Left view of a Tree

#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};
 
struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(
                        sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void leftViewUtil(struct Node *root,
                int level, int *max_level)
{
    // Base Case
    if (root == NULL) return;
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
      leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
     
}
 
void leftView(struct Node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}
 
int main()
{
    Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
 
    leftView(root);
 
    return 0;
}


//Q2.Right view of a Tree

#include<iostream>
using namespace std;
 
struct Node
{
    int data;
    struct Node *left, *right;
};
 
struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(
                          sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
void rightViewUtil(struct Node *root,
                   int level, int *max_level)
{
    if (root == NULL) return;
    if (*max_level < level)
    {
        cout << root->data << "\t";
        *max_level = level;
    }
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}
 
void rightView(struct Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}
 
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
 
    rightView(root);
 
    return 0;
}


//Q3.Top view of a Tree

#include<iostream>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int hd;
    int data;
};
 
Node* newNode(int key)
{
    Node* node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}
 
void topview(Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;
 
    q.push(root);
 
    cout << "The top view of the tree is : \n";
 
    while (q.size()) {
        hd = root->hd;
        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left) {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right) {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
 
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->second << " ";
    }
}
 
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary "
            "Tree\n";
    topview(root);
    return 0;
}


//Q4.Bottom view of a Tree

#include<iostream>
using namespace std;

struct Node
{
    int data;
    int hd;
    Node *left, *right;
 
    Node(int key)
    {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};
 
void bottomView(Node *root)
{
    if (root == NULL)
        return;
 
    int hd = 0;
 
    map<int, int> m;
 
    queue<Node *> q;
 
    root->hd = hd;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        hd = temp->hd;
 
        m[hd] = temp->data;
 
        if (temp->left != NULL)
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
 
        if (temp->right != NULL)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }
 
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";
}
 
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << "Bottom view of the given binary tree :\n"
    bottomView(root);
    return 0;
}


//Q5.Boundary traversal of a Tree

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
 
void printLeaves(struct node* root)
{
    if (root == NULL)
        return;
 
    printLeaves(root->left);
 
    if (!(root->left) && !(root->right))
        printf("%d ", root->data);
 
    printLeaves(root->right);
}
void printBoundaryLeft(struct node* root)
{
    if (root == NULL)
        return;
 
    if (root->left) {
        printf("%d ", root->data);
        printBoundaryLeft(root->left);
    }
    else if (root->right) {
        printf("%d ", root->data);
        printBoundaryLeft(root->right);
    }
}
 
void printBoundaryRight(struct node* root)
{
    if (root == NULL)
        return;
 
    if (root->right) {
        printBoundaryRight(root->right);
        printf("%d ", root->data);
    }
    else if (root->left) {
        printBoundaryRight(root->left);
        printf("%d ", root->data);
    }
}
 
void printBoundary(struct node* root)
{
    if (root == NULL)
        return;
 
    printf("%d ", root->data);
 
    printBoundaryLeft(root->left);
 
    printLeaves(root->left);
    printLeaves(root->right);
 
    printBoundaryRight(root->right);
}
 
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}
 
int main()
{
    struct node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
 
    printBoundary(root);
 
    return 0;
}


//Q6.Diagnoal traversal of a tree

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void diagonalPrintUtil(Node* root, int d,
                map<int, vector<int>> &diagonalPrint)
{
    if (!root)
        return;
    diagonalPrint[d].push_back(root->data);
    diagonalPrintUtil(root->left,d + 1, diagonalPrint);
    diagonalPrintUtil(root->right, d, diagonalPrint);
}
 
void diagonalPrint(Node* root)
{
    map<int, vector<int> > diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);
 
    cout << "Diagonal Traversal of binary tree : \n";
    for (auto it :diagonalPrint)
    {
        vector<int> v=it.second;
        for(auto it:v)
          cout<<it<<" ";
        cout<<endl;
    }
}
 
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
int main()
{
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    diagonalPrint(root);
 
    return 0;
}


//Q7.Convert binary tree to doubly linked list 

#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
};

node* bintree2listUtil(node* root)
{
	if (root == NULL)
        return root;
    if (root->left != NULL) {
        node* left = bintree2listUtil(root->left);
        for (; left->right != NULL; left = left->right);
        left->right = root;
        root->left = left;
    }
    
    if (root->right != NULL) {
    	node* right = bintree2listUtil(root->right);
    	for (; right->left != NULL; right = right->left);
    	right->left = root;
    	root->right = right;
    }
 
    return root;
}

node* bintree2list(node* root)
{
	if (root == NULL)
        return root;
    root = bintree2listUtil(root);
    while (root->left != NULL)
        root = root->left;
 
    return (root);
}

node* newNode(int data)
{
    node* new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

void printList(node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->right;
    }
}

int main()
{
    node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
    node* head = bintree2list(root);
    printList(head);
 
    return 0;
}


//Q8.Root to leaf path sum equal to a given number

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
};
 
bool hasPathSum(node* Node, int sum)
{
  bool ans = 0;
 
  int subSum = sum - Node->data;
  if ( subSum == 0 && Node->left == NULL && Node->right == NULL )
    return 1;
  if(Node->left)
    ans = ans || hasPathSum(Node->left, subSum);
  if(Node->right)
    ans = ans || hasPathSum(Node->right, subSum);
 
  return ans;
 
}
node* newnode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
     
    return(Node);
}
 
// Driver Code
int main()
{
 
    int sum = 1;
    node *root = newnode(1);
    root->left = newnode(0);
    root->right = newnode(1);
    root->left->left = newnode(1);
    root->left->right = newnode(0);
    root->right->left = newnode(0);
     
    if(hasPathSum(root, sum))
        cout << "There is a root-to-leaf path with sum " << sum;
    else
        cout << "There is no root-to-leaf path with sum " << sum;
     
    return 0;
}
