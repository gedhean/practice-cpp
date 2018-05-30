#include <iostream>
using namespace std;

//Sieve of Eratosthenes algorithms to find prime numbers

void printPrimes(int n) {
    bool prime[n+1];
    int i, divisor;
    
    for (i = 0; i <= n; i++) {
        prime[i] = true;
    }
    
    for (divisor = 2; divisor*divisor <= n ; divisor++) {
        if(prime[divisor]) {
            for (i = 2*divisor; i <= n; i += divisor) {
                prime[i] = false;
            }
        }
    }
    
    for (i = 2; i <= n; i++) {
        if (prime[i]) {
            cout << i << ", " << endl;
        }
    }
}

int main() {
	cout<<"Prime Numbers" << endl;
	
	printPrimes(1000000);
	
	return 0;
}

