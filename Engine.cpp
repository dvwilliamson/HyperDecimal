#include <iostream>
#include "hyperDecimal.h"

using namespace std;

int main(){
	bool inProg = true;
	do{
		unsigned l;
		cout << "\nEnter the number you wish to receive the factorial of: ";
		if((cin >> l) && (l!=0)){
			cout << "\n";
			hyperDecimal test;
			int t;
			t = clock();
			for(unsigned i = 1; i <= l; i++){
				test *= i;
			}
			cout << test << endl;
				t = clock() - t;
				cout<<"It took me " << t <<" clicks (" << ((float)t)/CLOCKS_PER_SEC <<" seconds).\n";
		} else {
			inProg = false;
		}
	} while (inProg);
	return 0;
}