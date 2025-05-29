#include <iostream>
#include <string>
using namespace std;
struct Book
{
    string title;
    string author;
    int year;
    float price;
};
class User
{
private:
    string name;
    int userID;
    Book *borrowBooks;
    int barrowCount;

public:
    User()
    {
        borrowBooks = 0;
    }

    void setName(string N)
    {
        name = N;
    }
    string getName()
    {
        return name;
    }

    // function
    void getInput()
    {
        borrowBooks = new Book[barrowCount];
        cout << "==== Please Enter User Details ====" << endl;
        cout << "Title :";
        cout << "Enter user name:";
        cin >> name;
        cout << "Enter user ID:";
        cin >> userID;
        cout << "Enter number of books borrowed:";
        cin >> barrowCount;
        cout << "==== Please Enter User Details ====" << endl;

        for (int i = 0; i < barrowCount; i++)
        {
            Book book;
            cout << "Enter details for book " << i + 1 << " :" << endl;
            cout << "Title :";
            cin >> book.title;
            cout << "Author :";
            cin >> book.author;
            cout << "Year :";
            cin >> book.year;
            cout << "Price :";
            cin >> book.price;
            borrowBooks[i] = book;
        }
    }
    float getTotalBorrowedBooks()
    {
        float total = 0;
        for (int i = 0; i < barrowCount; i++)
        {
            total += borrowBooks[i].price;
        }
        return total;
    }
    void displayUserDetails()
    {
        Book book;
        cout << "--- User Borrowing Summary ---" << endl;
        cout << "User" << userID << " : " << name << endl;
        cout << barrowCount << endl;

        cout << "Barrwoed Book" << endl;
        borrowBooks = new Book[barrowCount]; // before the loop
        for (int i = 0; i < barrowCount; i++)
        {
            cout << "Enter details for book " << i + 1 << " :" << endl;
            cin >> borrowBooks[i].title;
            cin >> borrowBooks[i].author;
            cin >> borrowBooks[i].year;
            cin >> borrowBooks[i].price;
        }
    }
};
int main()
{

    User U1;
    U1.getInput();
    cout << "Total cost of borrowed books: " << U1.getTotalBorrowedBooks() << endl;
    U1.displayUserDetails();

    return 0;
}