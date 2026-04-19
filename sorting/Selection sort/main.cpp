#include<iostream>
using namespace std;

void selectionSortASC(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}

void selectionSortDESC(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int maxIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] > arr[maxIndex]) {
				maxIndex = j;
			}
		}
		swap(arr[i], arr[maxIndex]);
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int arr[5] = { 4,1,3,9,5 };
	cout << "Original array: ";
	printArray(arr, 5);
	selectionSortASC(arr, 5);
	cout << "Sorted array in ascending order: ";
	printArray(arr, 5);
	selectionSortDESC(arr, 5);
	cout << "Sorted array in descending order: ";
	printArray(arr, 5);
	return 0;
}