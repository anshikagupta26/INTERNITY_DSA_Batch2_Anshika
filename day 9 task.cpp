//Q1. Nearest Greater to left

#include<iostream>
#include <set>
using namespace std;

void printPrevGreater(int arr[], int n)
{
    set<int> s;
    for (int i = 0; i < n; i++) {
    	auto it = s.lower_bound(arr[i]);
        if (it == s.end()) // If no greater found
            cout << "-1"
                 << " ";
        else
            cout << *it << " ";
        s.insert(arr[i]);
    }
}

int main()
{
    int arr[] = { 10, 5, 11, 10, 20, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printPrevGreater(arr, n);
    return 0;
}


//Q2. Nearest smaller to left

#include<iostream>
using namespace std;

void printPrevSmaller(int arr[], int n)
{
	cout << "_, ";
	for (int i=1; i<n; i++)
    {
    	int j;
        for (j=i-1; j>=0; j--)
        {
            if (arr[j] < arr[i])
            {
                cout << arr[j] << ", ";
                break;
            }
        }
        if (j == -1)
           cout << "_, " ;
    }
}

int main()
{
    int arr[] = {1, 3, 0, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printPrevSmaller(arr, n);
    return 0;
}


//Q3. Nearest smaller to right

#include<iostream>
using namespace std;

void printNextSmaller(int arr[], int n)
{
	int i, j, next;
	for (int i=0; i<n; i++)
    {
    	next = -1;
        for (j=i+1; j<n; j++)
        {
            if (arr[j] < arr[i])
            {
                next = arr[i];
                break;
            }
        }
        cout << arr[i] << " -- "
             << next << endl;
    }
}

int main()
{
    int arr[] = {1, 3, 0, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNextSmaller(arr, n);
    return 0;
}


//Q4. Stock span problem. 

#include<iostream>
using namespace std;

void calculateSpan(int price[], int n, int S[])
{
	S[0] = 1;
	for (int i = 1; i < n; i++)
	{
       S[i] = 1;
    for (int j = i - 1; (j >= 0) &&
                (price[i] >= price[j]); j--)
            S[i]++;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int price[] = { 10, 4, 5, 90, 120, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    int S[n];
    calculateSpan(price, n, S);
    printArray(S, n);
 
    return 0;
}   


//Q5.Maximum area of histogram

#include<iostream>
using namespace std;

int max(int x, int y, int z)
{  return max(max(x, y), z); }

int minVal(int *hist, int i, int j)
{
    if (i == -1) return j;
    if (j == -1) return i;
    return (hist[i] < hist[j])? i : j;
}

int getMid(int s, int e)
{   return s + (e -s)/2; }

int RMQUtil(int *hist, int *st, int ss, int se, int qs, int qe, int index)
{
	if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return -1;
    int mid = getMid(ss, se);
    return minVal(hist, RMQUtil(hist, st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(hist, st, mid+1, se, qs, qe, 2*index+2));
}

int RMQ(int *hist, int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout << "Invalid Input";
        return -1;
    }
  
    return RMQUtil(hist, st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int hist[], int ss, int se, int *st, int si)
{
	if (ss == se)
       return (st[si] = ss);
    int mid = getMid(ss, se);
    st[si] =  minVal(hist, constructSTUtil(hist, ss, mid, st, si*2+1),
                     constructSTUtil(hist, mid+1, se, st, si*2+2));
    return st[si];
}

int *constructST(int hist[], int n)
{
	int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *st = new int[max_size];
    constructSTUtil(hist, 0, n-1, st, 0);
    return st;
}

int getMaxAreaRec(int *hist, int *st, int n, int l, int r)
{
    // Base cases
    if (l > r)  return INT_MIN;
    if (l == r)  return hist[l];
    int m = RMQ(hist, st, n, l, r);
    return max(getMaxAreaRec(hist, st, n, l, m-1),
               getMaxAreaRec(hist, st, n, m+1, r),
               (r-l+1)*(hist[m]) );
}

int getMaxArea(int hist[], int n)
{
    // Build segment tree from given array. This takes
    // O(n) time
    int *st = constructST(hist, n);
  
    // Use recursive utility function to find the
    // maximum area
    return getMaxAreaRec(hist, st, n, 0, n-1);
}

int main()
{
    int hist[] =  {6, 1, 5, 4, 5, 2, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}


//Q6. Rain water trapping

#include<iostream>
using namespace std;

int findWater(int arr[], int n)
{
    int result = 0;
    int left_max = 0, right_max = 0;
    int lo = 0, hi = n - 1;
 
    while (lo <= hi) {
        if (arr[lo] < arr[hi]) {
            if (arr[lo] > left_max)
                left_max = arr[lo];
            else
                result += left_max - arr[lo];
            lo++;
        }
        else {
            if (arr[hi] > right_max)
                right_max = arr[hi];
            else
                result += right_max - arr[hi];
            hi--;
        }
    }
 
    return result;
}
 
int main()
{
    int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum water that can be accumulated is "
         << findWater(arr, n);
}


//Q7.max area of rectangle in binary matrix

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n),right(n);
        
        stack<int> mystack;
        for(int i=0;i<n;++i)    //Fill left
        {
            if(mystack.empty())
            {    left[i] = 0;   mystack.push(i);    }
            else
            {
                while(!mystack.empty() and heights[mystack.top()]>=heights[i])
                    mystack.pop();
                left[i] = mystack.empty()?0:mystack.top()+1;
                mystack.push(i);
            }
        }
        while(!mystack.empty()) //Clear stack
            mystack.pop();
        
        for(int i=n-1;i>=0;--i) //Fill right
        {
            if(mystack.empty())
            {   right[i] = n-1; mystack.push(i);    }
            else
            {
                while(!mystack.empty() and heights[mystack.top()]>=heights[i])
                    mystack.pop();
                right[i] = mystack.empty()?n-1:mystack.top()-1;
                mystack.push(i);
            }
        }
        int mx_area = 0;    //Stores max_area
        for(int i=0;i<n;++i)
            mx_area = max(mx_area,heights[i]*(right[i]-left[i]+1));
        return mx_area;
    }
};


//Q8.Implementation of min stack

#include<iostream>
using namespace std;

struct MyStack
{
    stack<int> s;
    int minEle;
    void getMin()
    {
        if (s.empty())
            cout << "Stack is empty\n";
        else
            cout <<"Minimum Element in the stack is: "
                 << minEle << "\n";
    }
    void peek()
    {
        if (s.empty())
        {
            cout << "Stack is empty ";
            return;
        }
 
        int t = s.top();
 
        cout << "Top Most Element is: ";
        (t < minEle)? cout << minEle: cout << t;
    }
    void pop()
    {
        if (s.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top Most Element Removed: ";
        int t = s.top();
        s.pop();
        if (t < minEle)
        {
            cout << minEle << "\n";
            minEle = 2*minEle - t;
        }
 
        else
            cout << t << "\n";
    }
    void push(int x)
    {
        if (s.empty())
        {
            minEle = x;
            s.push(x);
            cout <<  "Number Inserted: " << x << "\n";
            return;
        }
 
        if (x < minEle)
        {
            s.push(2*x - minEle);
            minEle = x;
        }
        else
           s.push(x);
 
        cout <<  "Number Inserted: " << x << "\n";
    }
};
 
// Driver Code
int main()
{
    MyStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();
 
    return 0;
}


//Q9.The celebrity problem 

#include <bits/stdc++.h>
#include <list>
using namespace std;
  
#define N 8
  
bool MATRIX[N][N] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};
  
bool knows(int a, int b)
{
    return MATRIX[a][b];
}
int findCelebrity(int n)
{
    int indegree[n]={0},outdegree[n]={0};
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int x = knows(i,j);
            outdegree[i]+=x;
            indegree[j]+=x;
        }
    }
    for(int i=0; i<n; i++)
    if(indegree[i] == n-1 && outdegree[i] == 0)
        return i;
     
    return -1;
}

int main()
{
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" :
               cout << "Celebrity ID " << id;
    return 0;
}


//Q10.Longest valid parentesis

#include<iostream>
using namespace std;

int findMaxLen(string str)
{
    int n = str.length();
    stack<int> stk;
    stk.push(-1);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
    	if (str[i] == '(')
            stk.push(i);
        else
        {
        	if (!stk.empty())
            {
                stk.pop();
            }
            if (!stk.empty())
                result = max(result, i - stk.top());
             else
                stk.push(i);
        }
    }
 
    return result;
}

int main()
{
    string str = "((()()";
   
    // Function call
    cout << findMaxLen(str) << endl;
 
    str = "()(()))))";
   
    // Function call
    cout << findMaxLen(str) << endl;
 
    return 0;
}


//Q11.minimum number of deletion required to balance the parantesis

#include<iostream>
using namespace std;

int countMinReversals(string expr)
{
    int len = expr.length();
    if (len%2)
       return -1;
    stack<char> s;
    for (int i=0; i<len; i++)
    {
        if (expr[i]=='}' && !s.empty())
        {
            if (s.top()=='{')
                s.pop();
            else
                s.push(expr[i]);
        }
        else
            s.push(expr[i]);
    }
    int red_len = s.size();
    int n = 0;
    while (!s.empty() && s.top() == '{')
    {
        s.pop();
        n++;
    }
    return (red_len/2 + n%2);
}

int main()
{
   string expr = "}}{{";
   cout << countMinReversals(expr);
   return 0;
}


//Q12.Stack using queue

#include<iostream>
using namespace std;

class Stack {
    queue<int> q1, q2;
    int curr_size;
  
public:
    Stack()
    {
        curr_size = 0;
    }
  
    void push(int x)
    {
        curr_size++;
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
  
    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
        curr_size--;
    }
  
    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }
  
    int size()
    {
        return curr_size;
    }
};
  
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
  
    cout << "current size: " << s.size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
  
    cout << "current size: " << s.size()
         << endl;
    return 0;
}


//Q13.queue using stack

#include<iostream>
using namespace std;

struct Queue {
    stack<int> s1, s2;
 
    void enQueue(int x)
    {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int deQueue()
    {
        if (s1.empty()) {
            cout << "Q is Empty";
            exit(0);
        }
        int x = s1.top();
        s1.pop();
        return x;
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
 
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
 
    return 0;
}


//Q14.Implement two stacks in one array

#include<iostream>
using namespace std;

class twoStacks {
    int* arr;
    int size;
    int top1, top2;
 
public:
    twoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = n / 2 + 1;
        top2 = n / 2;
    }
    void push1(int x)
    {
        if (top1 > 0) {
            top1--;
            arr[top1] = x;
        }
        else {
            cout << "Stack Overflow"
                 << " By element :" << x << endl;
            return;
        }
    }
    void push2(int x)
    {
        if (top2 < size - 1) {
            top2++;
            arr[top2] = x;
        }
        else {
            cout << "Stack Overflow"
                 << " By element :" << x << endl;
            return;
        }
    }
    int pop1()
    {
        if (top1 <= size / 2) {
            int x = arr[top1];
            top1++;
            return x;
        }
        else {
            cout << "Stack UnderFlow";
            exit(1);
        }
    }
    int pop2()
    {
        if (top2 >= size / 2 + 1) {
            int x = arr[top2];
            top2--;
            return x;
        }
        else {
            cout << "Stack UnderFlow";
            exit(1);
        }
    }
};

int main()
{
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "
         << " : " << ts.pop1()
         << endl;
    ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ": " << ts.pop2()
         << endl;
    return 0;
}
