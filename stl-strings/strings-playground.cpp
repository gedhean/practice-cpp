#include <iostream>
#include <string>
using namespace std;
using std::string;

int main() {
	string name = "Gedhean";
	string lastName = "Alves Vieira";
	string fullName = name + " " + lastName;

	cout << fullName << endl;
	cout << fullName.size() << endl;

	return 0;
}
