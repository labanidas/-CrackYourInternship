#include <bits/stdc++.h>
using namespace std;

void tugOfWarUtil(int arr[], int n, vector<bool>& curr_elements, int no_of_selected_elements, vector<bool>& sol, int sum, int curr_sum, int curr_position, int& min_diff) {
    // If we've selected half elements, calculate the difference
    if (no_of_selected_elements == n / 2) {
        int diff = abs((sum / 2) - curr_sum);
        if (diff < min_diff) {
            min_diff = diff;
            sol = curr_elements;
        }
        return;
    }

    // If we've reached the end of the array, return
    if (curr_position == n) {
        return;
    }

    // Include the current element in the first subset
    curr_elements[curr_position] = true;
    tugOfWarUtil(arr, n, curr_elements, no_of_selected_elements + 1, sol, sum, curr_sum + arr[curr_position], curr_position + 1, min_diff);

    // Exclude the current element from the first subset
    curr_elements[curr_position] = false;
    tugOfWarUtil(arr, n, curr_elements, no_of_selected_elements, sol, sum, curr_sum, curr_position + 1, min_diff);
}

void tugOfWar(int arr[], int n) {
    // Total sum of the array
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Boolean vectors to keep track of the current subset and the solution
    vector<bool> curr_elements(n, false);
    vector<bool> sol(n, false);

    // Variables to keep track of the current sum and minimum difference
    int min_diff = INT_MAX;
    int curr_sum = 0;

    // Util function to recursively find the subsets
    tugOfWarUtil(arr, n, curr_elements, 0, sol, sum, curr_sum, 0, min_diff);

    // Print the solution
    cout << "The first subset is: ";
    for (int i = 0; i < n; i++) {
        if (sol[i]) {
            cout << arr[i] << " ";
        }
    }
    cout << "\nThe second subset is: ";
    for (int i = 0; i < n; i++) {
        if (!sol[i]) {
            cout << arr[i] << " ";
        }
    }
    cout << "\nMinimum difference is: " << min_diff << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    tugOfWar(arr, n);

    return 0;
}
