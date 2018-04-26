#include <iostream>
using namespace std;

int heap[100]; //Universal varilables
int end = -1, curr = -1; 


void swap(int a1, int a2);
void display();

void insert(int data) { //Function to insert elements into the heap.
	heap[::end + 1] = data; //Adding new number to the end.
	::end++;
	int curr = ::end; 
	while (heap[curr]>heap[(curr) / 2]) { //Loop to swap element and it's parent till it is larger than it's children.
		swap(curr, (curr) / 2);
		curr = (curr) / 2;
	}
};
void swap(int a1, int a2) { //Swaps data in indices a1 and a2.
	int temp = heap[a1];
	heap[a1] = heap[a2];
	heap[a2] = temp;
};

int bigger(int a) { //Returns the (index of) bigger of the children of given node.
	if (heap[2 * a + 1]>heap[2 * a + 2])
		return 2 * a + 1;
	else
		return 2 * a + 2;
};


void display() { //Print the array.
	int i;
	for (i = 0; i <= ::end; i++)
		cout << heap[i] << ", ";
};


void deletenum() { // Deletes the largest number (root) and reorients other nodes.
	int i;
		for (i = 0; i < ::end ; i++) { //Moving data one index back.
			heap[i] = heap[i + 1];
		};
		cout << "The end is: " << ::end << endl;
		heap[:: end] = 0; 
		::end--; //Specifying the new size of the heap.
};

int main() {
	int data, i, n;
	//take input
	cout << "What is the number of elements in the heap: ";
	cin >> n;
	
	for (i = 0; i<n; i++) {
		cin >> data;
		insert(data);
		display();
	}
	cout << "Here's the heap: ";
	display();

	cout << "\nDeleting,\n Here is the new heap: ";
	deletenum();
	display();

	

	return 0;
}

