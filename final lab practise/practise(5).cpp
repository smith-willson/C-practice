#include <iostream>
#include <cstring>
using namespace std;
class utility
{
protected:
    char name[30];
    int productID;
    double price;
    float discount;
    double finalprice;

public:
    utility()
    {
        strcpy(name, "");
        productID = 0;
        price = 0;
        discount = 0.0;
        finalprice = 0;
    }

    void product()
    {
        cout << "----------- Al tamuriya Mart ---------------" << endl;

        cout << "Enter the Product Name: ";
        cin.getline(name, 30);
        cout << "Enter Product ID: ";
        cin >> productID;
        cout << "enter the price of the product: ";
        cin >> price;

        calculatediscount();
    }

    double calculatediscount()
    {
        discount = price * (0.1);
        finalprice = price - discount;

        return finalprice;
    }

    void display()
    {
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << name << endl;
        cout << "Price: " << price << " $" << endl;
        cout << "Discount: " << discount << " $" << endl;
        cout << "Discounted price:" << finalprice << " $" << endl;
    }
};

class food : public utility
{
protected:
    char dateofexpiry[30];

public:
    food()
    {
        strcpy(dateofexpiry, " ");
    }

    void product()
    {
        utility::product();

        cin.ignore();

        cout << "Enter the expiry Date of the product: ";
        cin.getline(dateofexpiry, 30);
    }

    void display()
    {
        utility::display();
        cout << "The Date of Expiry: " << dateofexpiry << endl;
    }
};
int main()
{
    food item;

    item.product();

    cout << "Product Details:\n";
    item.display();
    return 0;
}