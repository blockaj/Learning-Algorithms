//The purpose of this small script is to understand the way
//basic algorithms (like insertion sort) slow down over time. 
//Insertion sort grows in quadratic time and can be expressed by cn^2

#include <iostream>

using namespace std;
int* insertionSort(int* a, int inputLength);

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
	int* orderedList = insertionSort(inputArray, arrayLength);

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

//We want to start at the second item in our array
//and then compare it to the first
int* insertionSort(int* a, int inputLength) {
	for(int j = 1; j < inputLength; j++) {
		int key = a[j];
		int i = j - 1;  //Get the previous item

		//While the previous item is greater than the current one
        //flip the items positions in the array
		while(i > -1 && a[i] > key) {
			a[i + 1] = a[i];
			i = i - 1;
		}
		a[i + 1] = key;  //If they're in the right order, move along
	}
	return a;
}