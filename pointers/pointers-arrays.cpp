#include <iostream>
using namespace std;

int main() {
	char c[] = {'j', 'e', 'd', 'i'};
	char* p = c;	// p points to c[0]
	char* q = &c[0];// q points to c[0]
	
	cout << "The output should be ddd" << endl;
	cout << c[2] << p[2] << q[2] << endl;

	return 0;
}
