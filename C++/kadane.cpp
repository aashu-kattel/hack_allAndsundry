#include<bits/stdc++.h> // Include necessary C++ libraries.

using namespace std;

int main() {

    int n;
    cin >> n; // Read an integer 'n' from the user.

    int a[n]; // Declare an array 'a' of size 'n' to store integers.
    for(int i = 0; i < n; i++) {
        cin >> a[i]; // Read 'n' integers and store them in the array 'a'.
    }

    int currentSum = 0; // Initialize a variable 'currentSum' to store the current sum of elements.
    int maxSum = INT_MIN; // Initialize a variable 'maxSum' to store the maximum sum, initially set to the minimum integer value.

    for(int i = 0; i < n; i++) {
        currentSum += a[i]; // Add the current element of the array to 'currentSum'.

        if(currentSum < 0) {
            currentSum = 0; // If 'currentSum' becomes negative, reset it to 0.
        }

        maxSum = max(maxSum, currentSum); // Update 'maxSum' with the maximum of the current 'maxSum' and 'currentSum'.
    }

    cout << maxSum << endl; // Print the maximum sum.

    return 0;
}
