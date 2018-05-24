#include <iostream>
#include <cstdlib> 
using namespace std;

int main() {
	char ch = 'G';		// first ch hold character 'G'
	char* chPt = &ch;	// holds the address of ch

	cout << "The output should be G L M" << endl;

	cout << *chPt << endl;	// outputs the character 'G'
	
	ch = 'L';		// ch new holds 'L'
	cout << *chPt << endl;  // outputs the character 'L'
	
	*chPt = 'M';		// ch now holds 'M'
	cout << ch << endl;	// outputs the character 'M'

	return 0;
}
