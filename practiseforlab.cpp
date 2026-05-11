#include<iostream>
using namespace std;
class book {
    private:
        string title;
        int pages;


    public:    
        book(string t = " ", int p){
            title = t;
            pages = p;
        }

        string gettitle(){
            return title;
        }

        int getpages(){
            return pages;
        }

        void settitle(string t){
            title = t;
        }

        void setpages(int p){
            pages = p;
        }

        void displayBook(){
            cout<<" Title: "<< title << endl;
            cout<<" Pages: "<< pages << endl;
        }
};

class Librarian {
    private:
    string name;

    public:
        Librarian(string n){
            name = n;
        }

        string getname(){ return name;}
        void setname(string n){
            name = n;
        }

        void displayLibrarian(){
            cout<<"Librarian Name: "<<name<<endl;
        }
};

class Library {
    private:
        book Books[5];
        Librarian* librarian;
        int bookCount;

    public:
        Library(Librarian* lib) : librarian(lib), bookCount(0),
            Books{book("Placeholder",1), book("Placeholder",1),
              book("Placeholder",1), book("Placeholder",1),
              book("Placeholder",1)} {

              } 
              
            void addbook(book b) {
                if (bookCount >= 5){
                    cout<<"Library is Fucken Full bro!"<<endl;
                    return;
                }

                Books[bookCount] = b;
                bookCount++;
                cout<<"Book Added successfully"<< endl;
            }  

    void displayLibrary() {
        cout << "\n===== LIBRARY SYSTEM =====" << endl;
        librarian->displayLibrarian();
        cout << "\nBooks in Library (" << bookCount << "):" << endl;
        for (int i = 0; i < bookCount; i++) {
            cout << "Book " << i + 1 << ":" << endl;
            Books[i].displayBook();
        }
        cout << "==========================" << endl;
    }
};

int main(){
    Librarian lib("Mr. Ahmed");


    Library myLibrary(&lib);
}