#include <iostream>
#include "book.h"
#include "admin.h"
using namespace std;

int main()
{
    string username, password;
    book b;
    admin ad;
    ad.addadmin();
    int user;
    char use;

    // Adding some books to the library
    b.addbook("Harry potter", "ziyan ali", "fiction", 2001);
    b.addbook("C++ Programming", "DS Malik", "Programming", 2000);

    cout << "Enter user name: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);

    do
    {
        if (ad.Verify(username, password))
        {
            string username, pass;
            int user;

            cout << "Welcome to Admin Panel" << endl;
            cout << "Press 1 to add admin" << endl;
            cout << "Press 2 to remove admin" << endl;
            cout << "Press 3 to display all admins" << endl;
            cout << "Press 4 to access the library functionalities" << endl;

            cin >> user;

            if (user == 1)
            {
                ad.addadmin();
            }
            else if (user == 2)
            {
                cout << "Enter username of the admin: ";
                getline(cin, username);
                ad.removeadmin(username);
            }
            else if (user == 3)
            {
                ad.display();
            }
            else if (user == 4)
            {
                system("CLS");
                cout << "Welcome to Library Management System \n\n";
                cout << "To add a book press 1 \n";
                cout << "To remove a book press 2 \n";
                cout << "To reserve a book press 3 \n";
                cout << "To Search a book press 4 \n";
                cout << "To see all the reserved books press 5 \n";
                cout << "To display all books press 6 \n";
                cout << "To search by category Press 7 \n";
                cout << "To Search by author press 8 \n";
                cout << "To return a book press 9 \n\n";
                cout << "To display all available books enter 10\n";

                cin >> user;

                if (user == 1)
                {
                    cin.ignore();
                    string bookname;
                    string authorname;
                    string category;
                    int releaseyear;

                    cout << "Enter the book name: ";
                    getline(cin, bookname);
                    cout << "Enter the author name: ";
                    getline(cin, authorname);
                    cout << "Enter category of the book: ";
                    getline(cin, category);
                    cout << "Enter the release year for the book: ";
                    cin >> releaseyear;

                    b.addbook(bookname, authorname, category, releaseyear);
                }
                else if (user == 2)
                {
                    cin.ignore();
                    string bookname;

                    cout << "Enter the name of the book you want to delete: ";
                    getline(cin, bookname);

                    b.deletebook(bookname);
                }
                else if (user == 3)
                {
                    string name;
                    string bookname;
                    cin.ignore();

                    cout << "Enter the name of the book you want to reserve: ";
                    getline(cin, bookname);
                    cout << "Enter the name of the person issued to: ";
                    getline(cin, name);

                    if (b.reservebook(bookname, name))
                    {
                        cout << "Book was successfully reserved" << endl;
                    }
                    else
                    {
                        cout << "Book was not reserved" << endl;
                    }
                }
                else if (user == 4)
                {
                    cin.ignore();
                    string bookname;

                    cout << "Enter the name of the book you want to search: ";
                    cin >> bookname;

                    if (b.searchBook(bookname))
                    {
                        cout << "Book is in the library" << endl;
                    }
                    else
                    {
                        cout << "Book is not available in the library list" << endl;
                    }
                }
                else if (user == 5)
                {
                    cin.ignore();
                    b.reservedBooks();
                }
                else if (user == 6)
                {
                    cin.ignore();
                    b.displaybooks();
                }
                else if (user == 7)
                {
                    cin.ignore();
                    b.searchByCategory();
                }
                else if (user == 8)
                {
                    cin.ignore();
                    b.searchByAuthor();
                }
                else if (user == 9)
                {
                    cin.ignore();
                    string bookname;

                    cout << "Enter the Book name: ";
                    getline(cin, bookname);

                    if (b.ReturnBook(bookname))
                    {
                        cout << "Book Returned" << endl;
                    }
                    else
                    {
                        cout << "Book return not successful" << endl;
                    }
                }
                else if (user == 10)
                {
                    b.displayavailable();
                }
            }
        }
        else
        {
            cout << "Enter the Credentials for admin to log in to the library management system: " << endl;
            getline(cin, username);
            getline(cin, password);
        }

        cout << "Do you want to perform more operations? (Y/N): ";
        cin >> use;
    } while (use != 'N');

    return 0;
}
