#include <iostream>
using namespace std;

/*
	Implementation of an Integer Array Data Structure
*/

class Array
{
	int _size, _capacity;
	int* _arr;
public:
	Array (int capacity);
 	// Return the number of elements 	
	int size() { return _size; };
	// Return the current max number of elements that the Array can store
	int capacity() { return _capacity; };
	void set(int index, int value);
	int get(int index);
	void print();
};
// Initialize the specifying the capacity
Array::Array (int capacity) {
	_size = 0;
	_capacity = capacity;
	if (_capacity >= 0) {
		_arr = new int [_capacity];
	}
	else {
		cout << "Capacity cannot be less then 1: " << _capacity << endl;
		exit(1);
	}
}

void Array::set (int index, int value) {
	if (index >= 0 && index < _capacity) {
		_arr[index] = value;
	} 
	else {
		cout << "Trying to set an invalid index! Exiting..." << endl;
		exit(1);
	}
}

int Array::get (int index) {
	if (index >= 0 && index < _capacity) {
		return _arr[index];
	}
	else {
		cout << "Trying to access an invalid index! Exiting..." << endl;
		exit(1);
	}
}

void Array::print () {
	for (int i = 0; i < _capacity; ++i)
	{
		cout << "[" << i << "]" << _arr[i] << endl;
	}
}

int main()
{	
	int n;

	cout << "Type the array length: ";
	cin >>  n;
	
	Array arr(n); 		
	
	arr.set(0, 10);
	arr.set(1, 11);
	arr.set(5, 200);

	arr.print();

	cout << "Last item: " << arr.get(arr.capacity() - 1) << endl;
	cout << "Size: " << arr.size() << " Capacity: " << arr.capacity() << endl;

	return 0;
}
