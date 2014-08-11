#include <iostream>

using namespace std;

int* merge(int* a, int p, int q, int r);
int* mergeSort(int* a, int p, int r);
template <class type> type printArray(type* array);

int main(int argc, char *argv[]) {
	cout << "Type in array length: ";
	int arrayLength;
	cin >> arrayLength;
	int inputArray[arrayLength];

	//Fill input array with as many random numbers as array length
	for (int i = 0; i < arrayLength; i++) {
		int input = rand() % arrayLength + 1;
		inputArray[i] = input;
	}
	int* orderedList = mergeSort(inputArray, 1, arrayLength);

	//Loop through the new ordered list so we can print out each
	//of the items individually
	for(int i = 0; i < arrayLength; i++) {
		if (i != arrayLength - 1) {
			cout << orderedList[i] << ", ";
		}
		else {
			cout << orderedList[i] << endl;
		}
		
	}
	return 0;
}

int* merge(int* a, int p, int q, int r) {
	int m = q - p + 1;  //Length of subarray a[p..q]
	int n = r - q;  //Length of subarray a[q + 1..r]
	int L[m + 1];  //"Left" array = a[p..q]
	int R[n + 1];  //"Right" array = a[q + 1..r]

	//Copy a[p..q] to L
	for (int i = 1; i < m; i++) {
		L[i] = a[p + i - 1];
	}

	//Copy a[q + 1..r] to R
	for (int j = 1; j < n; j++) {
		R[j] = a[q + j];
	}
	L[m + 1] = NULL;
	L[n + 1] = NULL;

	int i = 1;
	int j = 1;

	for (int k = p; p < r; p++) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i = i + 1;
		}
		else if (a[k] == R[j]) {
			j = j + 1;
		}
	}
	return a;
}

int* mergeSort(int* a, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		cout << q << endl;
		mergeSort(a, p, q);
		mergeSort(a, q + 1, r);
		merge(a, p, q, r);
	}
	return a;
}

template <class type> type printArray(type* array) {
}