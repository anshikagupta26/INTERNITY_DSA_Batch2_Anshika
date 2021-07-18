//Q1. Implement quick sort

#include<iostream>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
       int pi = partition(arr, low, high);
 		quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}


//Q2. Implement Merge sort

#include<iostream>
using namespace std;

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];     //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   mergeSort(arr, 0, n-1);     //(n-1) for last index
   cout << "Array after Sorting: ";
   display(arr, n);
}


//Q3. Count Inversions of an array

#include <iostream>
using namespace std;
 
int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;
 
    return inv_count;
}
 
int main()
{
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " Number of inversions are "
         << getInvCount(arr, n);
    return 0;
}


//Q4. find the intersection of two linked list

#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
void push(Node*& headRef, int data)
{
    // create a new linked list node from the heap
    Node* newNode = new Node;
 
    newNode->data = data;
    newNode->next = headRef;
    headRef = newNode;
}
 
Node* findIntersection(Node* first, Node* second)
{
    unordered_set<Node*> nodes;
    while (first)
    {
        nodes.insert(first);
        first = first->next;
    }

    while (second)
    {
        if (nodes.find(second) != nodes.end()) {
            return second;
        }
        second = second->next;
    }
    return nullptr;
}
 
int main()
{
    Node* first = nullptr;
    for (int i = 5; i > 0; i--) {
        push(first, i);
    }
    Node* second = nullptr;
    for (int i = 3; i > 0; i--) {
        push(second, i);
    }
    second->next->next->next = first->next->next->next;
 
    Node* addr = findIntersection(first, second);
    if (addr) {
        cout << "The intersection point is " << addr->data << endl;
    }
    else {
        cout << "The lists do not intersect." << endl;
    }
    return 0;
}


//Q5. find the length of the linked list
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};
void push(Node** head_ref, int new_data)
{
    Node* new_node =new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int getCount(Node* head)
{
    int count = 0;
    Node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
int main()
{
    Node* head = NULL;
 
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    cout<<"count of nodes is "<< getCount(head);
    return 0;
}


//Q6. check whether the given linked list is palindrome or not.

#include<iostream>
using namespace std;
 
class Node {
public:
        int data;
        Node(int d){
            data = d;
        }
        Node *ptr;
};
bool isPalin(Node* head){
        Node* slow= head;
        stack <int> s;
        while(slow != NULL){
                s.push(slow->data);
                slow = slow->ptr;
        }
        while(head != NULL ){
             int i=s.top();
             s.pop();
            if(head -> data != i){
                return false;
            }
           head=head->ptr;
        }
 
return true;
}
 
int main(){
    Node one =  Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(2);
    Node five = Node(1);
 
    five.ptr = NULL;
    one.ptr = &two;
    two.ptr = &three;
    three.ptr = &four;
    four.ptr = &five;
    Node* temp = &one;

    int result = isPalin(&one);
   
    if(result == 1)
            cout<<"isPalindrome is true\n";
    else
        cout<<"isPalindrome is true\n";
 
return 0;
}


//Q7. Sort a linkedlist.

#include<iostream>
using namespace std;
 
class Node {
public:
        int data;
        Node(int d){
            data = d;
        }
        Node *ptr;
};
bool isPalin(Node* head){
        Node* slow= head;
        stack <int> s;
        while(slow != NULL){
                s.push(slow->data);
                slow = slow->ptr;
        }
        while(head != NULL ){
             int i=s.top();
             s.pop();
            if(head -> data != i){
                return false;
            }
 
           head=head->ptr;
        }
 
return true;
}
 
// Driver Code
int main(){
    Node one =  Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(2);
    Node five = Node(1);
 
    five.ptr = NULL;
    one.ptr = &two;
    two.ptr = &three;
    three.ptr = &four;
    four.ptr = &five;
    Node* temp = &one;
    int result = isPalin(&one);
   
    if(result == 1)
            cout<<"isPalindrome is true\n";
    else
        cout<<"isPalindrome is true\n";
 
return 0;
}


//8. Reverse a linkedlist.

#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
 
struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }
    void reverse()
    {
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
 
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
int main()
{
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
 
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverse();
 
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}


//Q9. Delete a specific node from a given linked list.

#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void deleteNode(Node **head_ref, int position)
{
    if (*head_ref == NULL)
        return;
    Node* temp = *head_ref;
    if (position == 0)
    {
        *head_ref = temp->next;
        free(temp);            
        return;
    }
    for(int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
     Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
void printList( Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    Node* head = NULL;
 
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);
 
    cout << "Created Linked List: ";
    printList(head);
    deleteNode(&head, 4);
    cout << "\nLinked List after Deletion at position 4: ";
    printList(head);
    return 0;
}


//Q10. Insert a specific node from a given linked list.

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void insertAfter(Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout<<"the given previous node cannot be NULL";
        return;
    }
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void append(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
 
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

int main()
{
    Node* head = NULL;
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);
     
    cout<<"Created Linked list is: ";
    printList(head);
     
    return 0;
}


//Q11. Delete a node whose pointer to that node is given only. 

#include <assert.h>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node* head)
{
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void deleteNode(Node* node_ptr)
{
	if (node_ptr->next == NULL)
    {
        free(node_ptr);
        return;
    }
    Node* temp = node_ptr->next;
    node_ptr->data = temp->data;
    node_ptr->next = temp->next;
    free(temp);
}

int main()
{
	Node* head = NULL;
	push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
 
    cout << "Before deleting \n";
    printList(head);
    deleteNode(head);
 
    cout << "\nAfter deleting \n";
    printList(head);
    return 0;
}


//Q12. Reverse a linked list in the group of k
//1->2->3->4->5->6->7 k = 3
//3->2->1->6->5->4->7

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};
 
/* Reverses the linked list in groups
of size k and returns the pointer
to the new head node. */
Node* reverse(Node* head, int k)
{
    if (!head)
        return NULL;
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
 
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
 
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse(next, k);
 
    /* prev is new head of the input list */
    return prev;
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
/* Driver code*/
int main()
{
    Node* head = NULL;
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    cout << "Given linked list \n";
    printList(head);
    head = reverse(head, 3);
 
    cout << "\nReversed Linked list \n";
    printList(head);
 
    return (0);
}


//Q13. given a linked list arrange it in the below fashion
//L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 …

#include<iostream>
using namespaace std;
struct Node {
    int data;
    struct Node* next;
};

Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void reverselist(Node** head)
{
    // Initialize prev and current pointers
    Node *prev = NULL, *curr = *head, *next;
 
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
 
    *head = prev;
}

void printlist(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        if (head->next)
            cout << "-> ";
        head = head->next;
    }
    cout << endl;
}

void rearrange(Node** head)
{
	Node *slow = *head, *fast = slow->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* head1 = *head;
    Node* head2 = slow->next;
    slow->next = NULL;
    reverselist(&head2);
    *head = newNode(0); 
    Node* curr = *head;
    while (head1 || head2) {
        if (head1) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        if (head2) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
    *head = (*head)->next;
}

int main()
{
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
 
    printlist(head);
    rearrange(&head);
    printlist(head);
    return 0;
}


//Q14. merge two sorted linked list

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void MoveNode(Node** destRef, Node** sourceRef);

Node* SortedMerge(Node* a, Node* b)
{
	Node dummy;
	Node* tail = &dummy;
	dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);
 
        tail = tail->next;
    }
    return(dummy.next);
}
void MoveNode(Node** destRef, Node** sourceRef)
{
    Node* newNode = *sourceRef;
    assert(newNode != NULL);
    *sourceRef = newNode->next;
    newNode->next = *destRef;
    *destRef = newNode;
}


//Q15. merge linkedlist alternatively
//l1->l11->l12->l13->l14
//l2->l21->l22->l23->l24
//result --> l11->l21->l12->l22->l13->l23->l14->l24

#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};

void push(Node ** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void merge(Node *p, Node **q)
{
    Node *p_curr = p, *q_curr = *q;
    Node *p_next, *q_next;
 
    // While therre are avialable positions in p
    while (p_curr != NULL && q_curr != NULL)
    {
        // Save next pointers
        p_next = p_curr->next;
        q_next = q_curr->next;
 
        // Make q_curr as next of p_curr
        q_curr->next = p_next; // Change next pointer of q_curr
        p_curr->next = q_curr; // Change next pointer of p_curr
 
        // Update current pointers for next iteration
        p_curr = p_next;
        q_curr = q_next;
    }
 
    *q = q_curr; // Update head pointer of second list
}

int main()
{
    Node *p = NULL, *q = NULL;
    push(&p, 3);
    push(&p, 2);
    push(&p, 1);
    cout<<"First Linked List:\n";
    printList(p);
 
    push(&q, 8);
    push(&q, 7);
    push(&q, 6);
    push(&q, 5);
    push(&q, 4);
    cout<<"Second Linked List:\n";
    printList(q);
 
    merge(p, &q);
 
    cout<<"Modified First Linked List:\n";
    printList(p);
 
    cout<<"Modified Second Linked List:\n";
    printList(q);
 
    return 0;
}
