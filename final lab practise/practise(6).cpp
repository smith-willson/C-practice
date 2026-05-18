#include <iostream>
#include <cstring>
using namespace std;
class library
{
protected:
    char title[50];
    char ISBN[30];
    char Author[20];

public:
    library()
    {
        strcpy(title, "");
        strcpy(ISBN, "");
        strcpy(Author, "");
    }

    void setinfo()
    {

        cout << "Enter the Title of book: ";
        cin.getline(title, 50);
        cout << "Enter the Author's Name: ";
        cin.getline(Author, 20);
        cout << "Enter the ISBN NUMBER: ";
        cin.getline(ISBN, 30);
    }

    void display()
    {
        cout << "TITLE: " << title << endl;
        cout << "Author: " << Author << endl;
        cout << "ISBN: " << ISBN << endl;
    }
};

class printedbook : public library
{
protected:
    int NOpages;

public:
    printedbook()
    {
        NOpages = 0;
    }

    void setinfo()
    {
        library::setinfo();

        cout << "Enter the NUmber of pages: ";
        cin >> NOpages;

        cin.ignore();
    }

    void display()
    {
        library::display();

        cout << "NO of PAGES: " << NOpages << endl;
    }
};

class Ebooks : public library
{
protected:
    double size;

public:
    Ebooks()
    {
        size = 0;
    }

    void setinfo()
    {
        library::setinfo();

        cout << "Enter the size of Book (MBs): ";
        cin >> size;

        cin.ignore();
    }

    void display()
    {
        library::display();

        cout << "SIZE: " << size << " MB" << endl;
    }
};

int main()
{
    cout << "<<<<<<<<<<Welcome to city library>>>>>>>>>>" << endl;
    
    Ebooks eb1;
    eb1.setinfo();

    printedbook pb1;
    pb1.setinfo();

    eb1.display();
    pb1.display();

    return 0;
}