#include <iostream>
using namespace std;
int main()

{
	
	int n = 5;
	
		//outer loop for repart
		for(int i = 1; i <= n; i++)
		{
			//print space 
			  for (int j = 1; j <= n - i; j++)	
			{
				cout << " "; 
			}
			//cout << " * ";
				
				//print spaces and starts 
				for (int k = 1; k <= 2 * i - 1; k++)
				{
					if (k == 1 || k == 2 * i - 1 || i == n)
					{
						cout << "*";
					}
					else 
					{
						cout << " ";
					}
				}
				
				cout << endl;
		}
	
	return 0;
}

