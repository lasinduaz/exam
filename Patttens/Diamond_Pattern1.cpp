#include <iostream>
using namespace std;
int main(){
		
		int n = 0;
		cout << "Please Enter number:";
		cin >> n;
		
		//this for upper part of patten
		for (int i = 1; i <= n; i++) 
		{
    		// Print spaces
    		for (int space = 1; space <= n - i; space++) 
			{
        	cout << " ";
   			}
    		// Print stars
    		for (int j = 1; j <= 2*i - 1; j++)
			{
        	cout << "*";
    		}
    	
    		
    		// Move to next line
    		cout << endl;
    		}
    		
    		// this for lower part of patten
   // Lower half
    for (int i = n - 1; i >= 1; i--) {
        // Print spaces
        for (int space = 1; space <= n - i; space++) {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
	}
