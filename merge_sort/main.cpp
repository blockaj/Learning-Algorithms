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
		indent(dpth); 
		cout << "Sizes (left, right): " << left.size() << ", " << right.size() << endl;
		indent(dpth); 
		cout << "Left: ";
		printVector<int>(left);
		indent(dpth);
		cout << "Right: ";
		printVector<int>(right);

		//Part of algorithm
		mergeSort(left, dpth + 1);
		mergeSort(right, dpth + 1);
		merge(left, right);
	}
	return a; 
}
vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> result;
	while (left.size() > 0 || right.size() > 0) {
		if (left.size() > 0 && right.size() > 0) {
			//[[2, 1],]
			if (left[0] <= right[0] ) {
				result.push_back(left[0]);
				left.erase(left.begin());
			}
			else {
				result.push_back(right[0]);
				right.erase(right.begin());
			}

		}
		else if (left.size() > 0) {
			result.push_back(left[0]);
			left.erase(left.begin());
		} 
		else if (right.size() > 0) {
			result.push_back(right[0]);
			right.erase(right.begin());
		}
	}
	cout << "Result: "; printVector<int>(result);
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


