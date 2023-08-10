//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    

// Function to perform partition for QuickSelect algorithm
int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;

    // Traverse through the array and rearrange elements around pivot
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot element in its correct position
    swap(arr[i + 1], arr[r]);
    return i + 1; // Return index of pivot element
}

// Function to find the Kth smallest element using QuickSelect algorithm
int quickSelect(int arr[], int l, int r, int k) {
    if (l <= r) {
        int pivotIndex = partition(arr, l, r); // Partition the array
        int pos = pivotIndex - l + 1; // Position of pivot element

        if (pos == k) {
            return arr[pivotIndex]; // Found Kth smallest element
        } else if (pos > k) {
            return quickSelect(arr, l, pivotIndex - 1, k); // Search in left subarray
        } else {
            return quickSelect(arr, pivotIndex + 1, r, k - pos); // Search in right subarray
        }
    }
    return -1; // Return -1 if Kth smallest element doesn't exist
}

// Function to find the Kth smallest element in the array
int kthSmallest(int arr[], int l, int r, int k) {
    return quickSelect(arr, l, r, k);
}



};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends