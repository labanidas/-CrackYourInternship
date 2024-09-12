#include <iostream>
using namespace std;

// A utility function to get maximum
// value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int ex){
    int output[n];
    int count[10] = {0};
    
    for(int i=0; i<n; i++){
        count[(arr[i] / ex) % 10]++;
    }
    
    for(int i=1; i<10; i++){
        count[i] += count[i-1];
    }
    
    for(int i= n-1; i>=0; i--){
        output[count[(arr[i]/ex)%10] - 1] = arr[i];
        count[(arr[i]/ ex) % 10]--;
    }
    
    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}

void radixsort(int arr[], int n){
    int m = getMax(arr, n);
    
    for(int ex = 1; m/ex > 0; ex *= 10){
        countSort(arr, n, ex);
    }
}

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver Code
int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    radixsort(arr, n);
    print(arr, n);
    return 0;
}
