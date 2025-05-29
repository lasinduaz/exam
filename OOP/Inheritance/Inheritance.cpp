#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;
    void display() {
        cout << "Name is : " << name << endl;
        cout << "Age is  : " << age << endl;
    }
};

class Parent : public Student {
public:
    string parent_name;
    string phone_number;
    void display() {
        cout << "Parent Name is : " << parent_name << endl;
        cout << "Phone number is  : " << phone_number << endl;
    }
};

int main() {
    int n = 5; // height of the diamond

    // Top half
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j < n; ++j)
            cout << " ";
        for (int j = 1; j <= (2 * i - 1); ++j)
            cout << "*";
        cout << endl;
    }

    // Bottom half
    for (int i = n - 1; i >= 1; --i) {
        for (int j = n; j > i; --j)
            cout << " ";
        for (int j = 1; j <= (2 * i - 1); ++j)
            cout << "*";
        cout << endl;
    }

    Student s1;
    Parent p1;

    cout << "Enter student name: ";
    cin >> s1.name;
    cout << "Enter student age:  ";
    cin >> s1.age;
    cout << "=== === ==== === === === === === === === === == ===" << endl;
    cout << "Enter parent name: ";
    cin >> p1.parent_name;
    cout << "Enter parent phone number: ";
    cin >> p1.phone_number;

    cout << "        .-'`\\   \\ \\___     .---.      .--.  .-''-.  .--.  .--.  .--. \n";
    cout << "      .' __   |  | |  '.__//  __ \\    /  _ \\ | \\  ||  __||  __||  __| \n";
    cout << "     / .'  \\  |  | |    || | /  \\ |  |  / \\ ||  | || |__ | |__ | |__  \n";
    cout << "    (_/    | |  | |    || | |  | |  | |  | ||  | ||  __||  __||  __| \n";
    cout << "           | |  | |    || | \\__/ |  |  \\_/ ||  | || |__ | |   | |    \n";
    cout << "           |_|  |_|____||_|\\____/    \\___/  \\__\\_||____||_|   |_|    \n";
    cout << "                ( )_( )                                               \n";
    cout << "                 /   \\                                                \n";
    cout << "                / /^\\ \\                                               \n";
    cout << "               ( (   ) )                                              \n";
    cout << "                \\ \\_/ /                                               \n";
    cout << "                 `---`                                                \n";
    cout << "=== === ==== === === === === === === === === == ===" << endl;

    s1.display();
    cout << "=== === ==== === === === === === === === === == ===" << endl;
    p1.display();

    cout << R"(
             ____________________________________________________________________
           / \                                                                   \.
          |   |                                                                  |.
           \_ |                                                                  |.
              |                                                                  |.
              |                                                                  |.
              |     |¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|   |.
              |     |  \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ /  |   |.
              |     | --o---o---o---o---o---o---o---o---o---o---o---o---o---o-- |   |.
              |     |  / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \  |   |.
              |     | --o---o---o---o---o---o---o---o---o---o---o---o---o---o-- |   |.
              |     |  / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \  |   |.
              |     | --o---o---o---o---o---o---o---o---o---o---o---o---o---o-- |   |.
              |     |  / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \  |   |.
              |     | --o---o---o---o---o---o---o---o---o---o---o---o---o---o-- |   |.
              |     |  / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \  |   |.
              |     |__________________________________________________________|   |.
              |                                                                    |.
              |                            q o o p                                 |.
              |                             ( ^ )                                  |.
              |                            (  _  )                                 |.
              |                             |||||                                  |.
              |                           __|||||__                                |.
              |                         /~         ~\                              |.
              |                        |             |                             |.
              |                        |             |                             |.
              |                        |             |                             |.
              |                        |             |                             |.
              |                        |             |                             |.
              |                        |_____________|                             |.
              |                          |       |                                 |.
              |                          |       |                                 |.
              |                          |       |                                 |.
              |                         /         \                                |.
              |                        /           \                               |.
              |                       /             \                              |.
              |                      /               \                             |.
              |                                                                    |.
              |____________________________________________________________________|.
             /                                                                      \.
            |                                                                        |.
             \______________________________________________________________________/
    )";
    return 0;
}
