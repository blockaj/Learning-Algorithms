#include <iostream>

using namespace std;
int* insertionSort(int* a, int inputLength);

int main(int argc, char *argv[]) {
	cout << "Type in array length: ";
	int arrayLength;
	cin >> arrayLength;
	int inputArray[arrayLength];
	for (int i = 0; i < arrayLength; i++) {
		int input = rand() % arrayLength + 1;
		inputArray[i] = input;
	}
	int* orderedList = insertionSort(inputArray, arrayLength);
	for(int i = 0; i < arrayLength; i++) {
		cout << orderedList[i];
	}
	return 0;
}

int* insertionSort(int* a, int inputLength) {
	for(int j = 1; j < inputLength; j++) {
		int key = a[j];
		int i = j - 1;
		while(i > -1 && a[i] > key) {
			a[i + 1] = a[i];
			i = i - 1;
		}
		a[i + 1] = key;
	}
	return a;
}