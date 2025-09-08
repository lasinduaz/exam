#include <iostream>
#include <string>
using namespace std;

struct workLog
{
    int hourse;
    int days;
};
class Employee
{
private:
    string name;
    int employeeID;
    workLog *weeklyLog;
    int daysWorked;

public:
       Employee()
    {
        name = "";
        employeeID = 0;
        daysWorked = 0;
        weeklyLog;
    }
   // Destructor to free allocated memory
    ~Employee()
    {
        delete[] weeklyLog;
    }
    // getters
    string getName()
    {
        return name;
    }
    int getemployeeID()
    {
        return employeeID;
    }
    int getdaysWorked()
    {
        return daysWorked;
    }
     
    //setters 
    void setName(string n){
        name = n;
    }
    void setemployeeID(int emp){
        employeeID = emp;
    }
    void setdaysWorked (int dayWorkd)
    {
        daysWorked = dayWorkd;
    }

		
		    //functions 
		    void getInputes (){
		
		        
		        cout << "Enter employee name: ";
		        cin.ignore(); // Needed if getline follows cin >>
		        getline(cin, name);
		
		        cout << "Enter employee ID: ";
		        cin >> employeeID;
		
		        cout << "Enter number of days worked: ";
		        cin >> daysWorked;
		
		        // Allocate memory for work log
		        weeklyLog = new workLog[daysWorked];
		        
		    }
		    
		    void display()
			{
		    	cout << "Name is " << name << endl;
				cout << "Employee ID is " << 	employeeID << endl;
				cout << "Days worked " << daysWorked << endl;
				
			}

};
int main()
{	
	Employee E1;
	E1.getInputes();
	E1.display();

    return 0;
}
