#include <iostream>
using namespace std;

void merge(int A[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int B[ub + 1];  // Temporary array to store merged elements

    while (i <= mid && j <= ub) {
        if (A[i] <= A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {  // Copy remaining elements from the first half
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= ub) {  // Copy remaining elements from the second half
        B[k] = A[j];
        j++;
        k++;
    }
    for (int p = lb; p <= ub; p++) {  // Copy sorted elements back into original array
        A[p] = B[p];
    }
}

void MergeSort(int A[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        MergeSort(A, lb, mid);
        MergeSort(A, mid + 1, ub);
        merge(A, lb, mid, ub);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int A[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    MergeSort(A, 0, n - 1);  // Correct arguments for MergeSort

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

