#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

void indent(int spaces);
template <class type> void printVector(vector<type> a);
vector<int> mergeSort(vector<int> a, int dpth);
vector<int> merge(vector<int> left, vector<int> right);
int main(int argc, char *argv[]) {
	int myInt[] = {2, 1, 45, 3, 8765, 21, 89, 32};
	cout << "{2, 1, 45, 3, 8765, 21, 89, 32}" << endl;
	vector<int> input(myInt, myInt + sizeof(myInt) / sizeof(int));
	mergeSort(input, 0);
	return 0;
}

vector<int> mergeSort(vector<int> a, int dpth) {
	if (a.size() > 2) {
		int middle = floor(a.size() / 2);
		vector<int> left; 
		vector<int> right;
		vector<int> result;

		for (int i = 0; i < middle; i++) {
			left.push_back(a[i]);
		}
		for (int j = middle; j < a.size(); j++) {
			right.push_back(a[j]);
		}
		//Debuggery, not actual part of algorithm
		/*
		indent(dpth); 
		cout << "Sizes (left, right): " << left.size() << ", " << right.size() << endl;
		indent(dpth); 
		cout << "Left: ";
		printVector<int>(left);
		indent(dpth);
		cout << "Right: ";
		printVector<int>(right);
		*/
		//Part of algorithm
		mergeSort(left, dpth + 1);
		mergeSort(right, dpth + 1);
		merge(left, right);
	}
	return a; 
}
vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> result;
	if (left.size() <= 3){
		for (int i = 1; i < left.size(); ++i) {
			int key = left[i];
			int j = i - 1;
			while (j > -1 && left[j] > key) {
				left[j + 1] = left[j];
				j = j - 1;
			}
			left[j+1] = key;
		}
	}
	else {
		for (int i = 0; i < left.size(); ++i) {
			
		}
	}
	
	//cout << "Result: "; printVector<int>(result);
	return result;
}

void indent(int spaces) {
	for (int i = 0; i < spaces; i++) {
		cout << "    "; 
	}
}

template <class type> void printVector(vector<type> a) {
	for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i) {
		if (i == a.end() - 1) {
			cout << *i << endl;
		}
		else {
			cout << *i << ", ";
		}
	}
}


