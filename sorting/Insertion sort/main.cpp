#include<iostream>
using namespace std;

void insertionSortASC(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void insertionSortDESC(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] < key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
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
	insertionSortASC(arr, 5);
	cout << "Sorted array in ascending order: ";
	printArray(arr, 5);
	insertionSortDESC(arr, 5);
	cout << "Sorted array in descending order: ";
	printArray(arr, 5);
	return 0;
}