#include<iostream>
using namespace std;

void bubbleSortASC(int arr[], int size) {
	bool swapped = true;
	for(int i = 0; i < size-1 && swapped; i++) {
		swapped = false;
		for(int j = 0; j < size-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				swapped = true;	
			}
		}
		if (!swapped) {
			return;
		}
	}
}

void bubbleSortDESC(int arr[], int size) {
	bool swapped = true;
	for(int i = 0; i < size-1 && swapped; i++) {
		swapped = false;
		for(int j = 0; j < size-i-1; j++) {
			if(arr[j] < arr[j+1]) {
				swap(arr[j], arr[j+1]);
				swapped = true;	
			}
		}
		if (!swapped) {
			return;
		}
	}
}

void printArray(int arr[], int size) {
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int arr[5] = {4,1,3,9,5};
	cout << "Original array: ";
	printArray(arr, 5);
	bubbleSortASC(arr, 5);
	cout << "Sorted array in ascending order: ";
	printArray(arr, 5);
	bubbleSortDESC(arr, 5);
	cout << "Sorted array in descending order: ";
	printArray(arr, 5);
	return 0;
}