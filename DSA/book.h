#include "node.h"

class book
{
private:
    node *head;

public:
    book()
    {
        head = NULL;
    }

    // Function to add a book to the list
    void addbook(string name, string authorname, string catgeory, int data)
    {
        node *N = new node(data, authorname, name, catgeory);
        if (head == NULL)
        {
            head = N;
        }
        else
        {
            node *temp = head;
            while (temp->getnext() != NULL)
            {
                temp = temp->getnext();
            }
            temp->setnext(N);
        }
    }

    // Function to delete a book from the list
    bool deletebook(string bookname)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return false;
        }
        else
        {
            node *temp = head;
            node *prev = head;
            temp = temp->getnext();
            while (temp != NULL)
            {
                if (temp->getbookname() == bookname)
                {
                    prev->setnext(temp->getnext());
                    return true;
                }
                else
                {
                    temp = temp->getnext();
                    prev = prev->getnext();
                }
            }
            return false;
        }
    }

    // Function to search for a book in the list
    bool searchBook(string book)
    {
        if (head == NULL)
        {
            return false;
        }
        else
        {
            node *temp = head;
            while (temp != NULL)
            {
                if (temp->getbookname() == book)
                {
                    return true;
                }
                temp = temp->getnext();
            }
            return false;
        }
    }

    // Function to reserve a book
    bool reservebook(string bookname, string name)
    {
        bool changed = false;
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->getbookname() == bookname && temp->getreservestatus() == false)
            {
                temp->setreservestatus(true);
                temp->setissuedto(name);
                changed = true;
            }
            temp = temp->getnext();
        }
        return changed;
    }

    // Function to display reserved books
    void reservedBooks()
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->getreservestatus())
                temp->display();
            temp = temp->getnext();
        }
    }

    // Function to display all books
    void displaybooks()
    {
        if (head == NULL)
        {
            cout << "There are no Books to display";
            cout << endl;
            return;
        }

        node *temp = head;
        while (temp != NULL)
        {
            temp->display();
            temp = temp->getnext();
        }
    }

    // Function to return a book
    bool ReturnBook(string bookname)
    {
        if (head == NULL)
        {
            return false;
        }
        else
        {
            node *temp = head;
            while (temp != NULL)
            {
                if (temp->getbookname() == bookname && temp->getreservestatus() == true)
                {
                    temp->setissuedto("\0");
                    temp->setreservestatus(false);
                    return true;
                }
                temp = temp->getnext();
            }
            return false;
        }
    }

    // Function to search books by category
    void searchByCategory()
    {
        if (head == NULL)
        {
            cout << "No Books in the List" << endl;
            return;
        }
        else
        {
            string category;
            cout << "Enter the category you want to search";
            getline(cin, category);
            node *temp = head;
            while (temp != NULL)
            {
                if (temp->getcategory() == category)
                {
                    temp->display();
                }
                temp = temp->getnext();
            }
        }
    }

    // Function to search books by author
    void searchByAuthor()
    {
        if (head == NULL)
        {
            cout << "Book list is empty" << endl;
            return;
        }
        else
        {
            string author;
            cout << "Enter the name of the author : ";
            getline(cin, author);
            node *temp = head;
            while (temp != NULL)
            {
                if (temp->getauthor() == author)
                {
                    temp->display();
                }
                temp = temp->getnext();
            }
        }
    }

    // Function to display available books
    void displayavailable()
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->getreservestatus() == false)
            {
                temp->display();
            }
            temp = temp->getnext();
        }
    }
};
