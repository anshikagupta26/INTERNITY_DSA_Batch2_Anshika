// 1. Find length of an array

#include<iostream>
using namespace std;

int main(){

    int arr[]={1,2,5,7,3,8,9};

    int arrayLength = sizeof(arr)/sizeof(arr[0]);
    cout<<"Length of array is "<<arrayLength<<endl;
    return 0;
} 

// 2. Reverse the array

#include<iostream>
using namespace std;

int main(){
    int n,l=0,r;
    cin>>n;
    r=n-1;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    //reversing the array
    while(l<h){
        int temp=arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        l++;
        r--;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
} 


// 3. Find the maximum and minimum element in an array

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int max=0, min, arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i]; 
    }

    for(int i=0; i<n; i++){
        if(max<arr[i]){
            max=arr[i];
        }
        if(min>arr[i]){
            min=arr[i];
        }
    }
	cout<<"Maximum Element in Array :"<<max<<endl<<"Minimum Element in Array :"<<min<<endl;
	return 0;
} 


// 4. Find the "Kth" max and min element of an array

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, k, max, min;
    cin>>n;
    cin>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i]; 
    }
    sort(arr, arr + n);
    max = arr[n-k];
    min = arr[k-1];

    cout<<k<<"th maximum element in the Array :"<<max<<endl<<k<<"th minimum element in the Array :"<<min<<endl;
	return 0;
}


// 5. Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo

#include<iostream>
using namespace std;

void sort_array(int arr[], int n){
	int i, cnt0=0, cnt1=0; cnt2=0;
	for (i = 0; i < n; i++) {
        switch (arr[i]) {
        case 0:
            cnt0++;
            break;
        case 1:
            cnt1++;
            break;
        case 2:
            cnt2++;
            break;
        }
    }
    i = 0;
    while (cnt0 > 0) {
        arr[i++] = 0;
        cnt0--;
    }
    while (cnt1 > 0) {
        arr[i++] = 1;
        cnt1--;
    }
    while (cnt2 > 0) {
        arr[i++] = 2;
        cnt2--;
    }
    for(int j=0; j<n; j++){
    	cout<<arr[j]<<" ";
	}
}
int main(){
	int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(int);
    sort_array(arr, n);
    return 0;
}



// 6. Move all the negative elements to one side of the array

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n], count = 0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        if(arr[i]<0){
            int temp = arr[i];
            arr[i] = arr[count];
            arr[count] = temp;
            count++; 
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
     return 0;
}




// 7. Find the Union and Intersection of the two sorted arrays.

#include<iostream>
using namespace std;

int printIntersection(int arr1[], int arr2[], int m, int n) { 
  int i = 0, j = 0; 
  while (i < m && j < n){ 
    if (arr1[i] < arr2[j]) 
       i++; 
    else if (arr2[j] < arr1[i]) 
       j++; 
    else{ 
       cout << arr2[j] << " "; 
       i++; 
       j++; 
    } 
  } 
} 

int printUnion(int arr1[], int arr2[], int m, int n){ 
  int i = 0, j = 0; 
  while (i < m && j < n){ 
    if (arr1[i] < arr2[j]) 
       cout << arr1[i++] << " "; 

    else if (arr2[j] < arr1[i]) 
       cout << arr2[j++] << " "; 

    else{ 
       cout << arr2[j++] << " "; 
       i++; 
    } 
  } 

  while(i < m) 
     cout << arr1[i++] << " "; 

  while(j < n) 
    cout << arr2[j++] << " "; 
} 

int main(){
    int m;
    cin>>m;
    int arr1[m];
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }
    int n;
    cin>>n;
    int arr2[n];
    int count = 0;

    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }

    cout<<"Union elements in The Array :";
    printUnion(arr1, arr2, m, n);
    cout<<"Intersected elements in The Array :";
    printIntersection(arr1, arr2, m, n);

    return 0;
} 




// 8. Given an array of digits check if the array is palindrome or not.

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],l=0,h=n-1;
    int count = 0;
    bool flag=0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    while(l<h){
        if(arr[l]==arr[h]){
            flag=1;
            l++;
            h--;
        }
        else
            flag=0;
            break;
    }
    if(flag==1)
    cout<<"It is the Pallindrome Array";
    else
    cout<<"It is Not the Pallindrome Array";

    return 0;
} 
