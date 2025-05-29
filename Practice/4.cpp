#include <iostream>
#include <string>
using namespace std;
//Online Order Processing System 
struct Order  
{
	string quintityName;
	int quantity;
	double price;	
};
class Customer
{
	
	//accesbility
	private:
	string name;
	int customerID;
	Order * order_list;
	int ordercount;
	
		public:
			//constucter
			Customer()
			{
				name = "";
				customerID = 0;
				ordercount = 0;
				order_list = NULL;

			}
				//getters
				string getName()
				{
					return name;
				}
				int getcustomerID()
				{
					return customerID;
				}
	   			 int getOrderCount()
				{
      			return ordercount;
    			}
				
					//setters
					void setname(string Name)
					{
						name = Name;
					}
					void setcustomerID(int custID)
					{
						customerID = custID;
					}
			    	void setOrderCount(int ordCount)
					 {
        			ordercount = ordCount;
   					 }
					    // Destructor to avoid memory leaks
					    ~Customer() {
					        delete[] order_list;
					    }
			
							//functions
							void inputOrders()
							{			
								cout << "Plese Enter Name :";
								cin >> name ;
								cout << "Please Enter your ID";
								cin >> customerID;
								cout << "Please Enter Your Order of count:";
								cin >> ordercount;
							//obj for stuct 
        						order_list = new Order[ordercount];
					       cout << "== Please Enter Order Details ===" << endl;
        					for (int i = 0; i < ordercount; i++) {
           							cout << "\nOrder #" << i + 1 << endl;
            						cout << "Enter item name: ";
            						cin >> order_list[i].quintityName;
            						cout << "Enter quantity: ";
								    cin >> order_list[i].quantity;
								    cout << "Enter price: ";
									cin >> order_list[i].price;
       							 }
							}
							    void display()
							   {
							   	cout << "Name is "<< name << endl;
							   	cout << "Cusmoter ID" << customerID << endl:
								cout << "order count is " << ordercount << endl;
							   }


};


int main()
{
		
		
		cout << "?? Success! This code compiled and is running flawlessly. Time to celebrate! ??\n";
			
			Customer C1;	
			C1.inputOrders();
		return 0;
}
