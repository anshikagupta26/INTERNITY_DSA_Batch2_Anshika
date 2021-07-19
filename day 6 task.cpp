//Q1. Detect cycle in a linked list

#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

bool detectLoop(struct Node* h)
{
    unordered_set<Node*> s;
    while (h != NULL) {
    	if (s.find(h) != s.end())
            return true;
        s.insert(h);
        h = h->next;
    }
    return false;
}

int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
 
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
 
    return 0;
}


//Q2. Return the start of the cycle.

#include<iostream>
using namespace std;

struct Node {
    int key;
    struct Node* next;
};
 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}

void printList(Node* head)
{
    while (head != NULL) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}

Node* detectAndRemoveLoop(Node* head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
 
    Node *slow = head, *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow != fast)
        return NULL;
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
 
    return slow;
}

int main()
{
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
    
    head->next->next->next->next->next = head->next->next;
 
    Node* res = detectAndRemoveLoop(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->key;
 
    return 0;
}


//Q3. Implement Radix Sort

#include<iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    radixsort(arr, n);
    print(arr, n);
    return 0;
}


//Q4.Implement Doubly Linked List along with delete operation delete the particular node

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
};

void deleteNode(Node** head_ref, Node* del)
{
    if (*head_ref == NULL || del == NULL)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
    return;
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(Node* node)
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
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);
 
    cout << "Original Linked list ";
    printList(head);
    deleteNode(&head, head);
    deleteNode(&head, head->next);
    cout << "\nModified Linked list ";
    printList(head);
 
    return 0;
}


//Q5. sort doubly linked list

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next, *prev;
};
 
Node *split(Node *head);
Node *merge(Node *first, Node *second)
{
	if (!first)
        return second;
    if (!second)
        return first;
    if (first->data < second->data)
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head,second);
}

void insert(Node **head, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(Node *head)
{
    Node *temp = head;
    cout<<"Forward Traversal using next poitner\n";
    while (head)
    {
        cout << head->data << " ";
        temp = head;
        head = head->next;
    }
    cout  << "\nBackward Traversal using prev pointer\n";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

Node *split(Node *head)
{
    Node *fast = head,*slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = NULL;
    return temp;
}

int main(void)
{
    Node *head = NULL;
    insert(&head, 5);
    insert(&head, 20);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 30);
    insert(&head, 10);
    head = mergeSort(head);
    cout << "Linked List after sorting\n";
    print(head);
    return 0;
}


//Q6.Implement circular linked list

#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

struct Node *addToEmpty(struct Node *last, int data)
{
	if (last != NULL)
      return last;
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    last = temp;
    last -> next = last;
 
    return last;
}
 
struct Node *addBegin(struct Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
 
    struct Node *temp =
            (struct Node *)malloc(sizeof(struct Node));
 
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
 
    return last;
}
 
struct Node *addEnd(struct Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
     
    struct Node *temp =
        (struct Node *)malloc(sizeof(struct Node));
 
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
 
    return last;
}
 
struct Node *addAfter(struct Node *last, int data, int item)
{
    if (last == NULL)
        return NULL;
 
    struct Node *temp, *p;
    p = last -> next;
    do
    {
        if (p ->data == item)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp -> data = data;
            temp -> next = p -> next;
            p -> next = temp;
 
            if (p == last)
                last = temp;
            return last;
        }
        p = p -> next;
    }  while(p != last -> next);
 
    cout << item << " not present in the list." << endl;
    return last;
 
}
 
void traverse(struct Node *last)
{
    struct Node *p;
    if (last == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    
    p = last -> next;
    
	do
    {
        cout << p -> data << " ";
        p = p -> next;
 
    }
    while(p != last->next);
 
}

int main()
{
    struct Node *last = NULL;
 
    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    last = addAfter(last, 10, 8);
 
    traverse(last);
 
    return 0;
}
