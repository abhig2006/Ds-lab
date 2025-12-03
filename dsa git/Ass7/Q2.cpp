#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
  for (int i = 0; i < n / 2; i++) {
    int minIndex = i;
    int maxIndex = i;

    // Find min and max in the unsorted portion
    for (int j = i; j < n - i; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
      if (arr[j] > arr[maxIndex]) {
        maxIndex = j;
      }
    }

    // Swap minimum to the beginning
    swap(arr[i], arr[minIndex]);

    // If the maximum element was moved because minIndex == maxIndex
    if (maxIndex == i) {
      maxIndex = minIndex;
    }

    // Swap maximum to the end
    swap(arr[n - i - 1], arr[maxIndex]);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int arr[] = {64, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "\n--- Improved Selection Sort ---\n";

  cout << "\nOriginal Array: ";
  printArray(arr, n);

  improvedSelectionSort(arr, n);

  cout << "Sorted Array: ";
  printArray(arr, n);

  return 0;
}