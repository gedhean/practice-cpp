#include <iostream>
using namespace std;

/*
	Implementation of an Integer Array Data Structure
*/

static const int RESIZE_FACTOR = 8;
static const int MIN_CAPACITY = 16;

class Array
{
	int _size, _capacity;
	int *_arr;

  public:
	Array(int capacity);
	// Return the number of elements
	int size() { return _size; };
	// Return the capacity the Array can store
	int capacity() { return _capacity; };
	void push(int value);
	void insert(int index, int value);
	void set(int value, int index); // Update an value
	int get(int index);
	bool isEmpty() { return _size == 0; };
	void debug();

  private:
	void increseSize();
};
// Initialize the specifying the capacity
Array::Array(int capacity)
{
	_size = 0; // Should be zero by default
	if (capacity > 0)
	{
		try
		{
			_capacity =  capacity < MIN_CAPACITY ? MIN_CAPACITY : capacity;
			_arr = new int[_capacity];
		}
		catch (const std::exception &e)
		{
			std::cerr << "bad_alloc at constructor " << e.what() << '\n';
		}
	}
	else
	{
		cout << "Capacity cannot be less then 1: " << capacity << endl;
		exit(1);
	}
}

void Array::push(int value)
{
	if (_size == _capacity)
	{
		increseSize();
		_arr[_size] = value;
		_size++;
		cout << "Needed to alloc more memory" << endl;
	}
	else
	{
		_arr[_size] = value;
		_size++;
	}
}

void Array::insert(int index, int value)
{
	if (index >= 0 && index < _size)
	{
		if (_size == _capacity)
		{
			increseSize();
		}

		for (int i = _size; i >= index; i--)
		{
			_arr[i] = _arr[i-1];
		}
		
		_arr[index] = value;
		_size++;
	}
	else
	{
		cout << "Couldn't INSERT element" << endl;
	}
}
// Do not change the size of Array. Just update a value
void Array::set(int value, int index)
{
	if (index >= 0 && index < _size)
	{
		_arr[index] = value;
	}
	else
	{
		cout << "Trying to SET an unsettled index!" << endl;
		//exit(1);
	}
}

int Array::get(int index)
{
	if (index >= 0 && index < _size)
	{
		return _arr[index];
	}
	else
	{
		cout << "Trying to ACCESS an unsettled index!" << endl;
		exit(1);
	}
}

void Array::increseSize()
{
	try
	{
		_capacity = _capacity + MIN_CAPACITY;
		int *arr_aux = new int[_capacity];
		// Copy all elements from _arr to the new resized array
		for (int i = 0; i < _size; i++)
		{
			arr_aux[i] = _arr[i];
		}

		delete[] _arr;
		_arr = arr_aux;
	}
	catch (const std::exception &e)
	{
		std::cerr << "erro trying resize " << e.what() << '\n';
		exit(1);
	}
}

void Array::debug()
{
	cout << "Size: " << _size << " Capacity: " << _capacity << endl;

	for (int i = 0; i < _size; ++i)
	{
		std::cout << "[" << i << "]" << _arr[i] << endl;
	}
}

int main()
{
	int n;

	cout << "Type the array length: ";
	cin >> n;

	Array arr(n);

	for (int i = 0; i < 20; i++)
	{
		arr.push(i);
	}

	arr.insert(10, 1000);

	// arr.set(10, 0);
	// arr.set(11, 1);
	// arr.set(12, arr.size()-1);

	arr.debug();

	return 0;
}
