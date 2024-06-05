#include <bits/stdc++.h>
using namespace std;
static int i;
class inventory
{
    string product;
    string product_type;
    long long int Quantity;
    long double Purchase_price;
    long long int Purchase_itme;
    long long int sell_itme = 0;
    long double Sell_price;
    int product_key;
    long double p_l;
    // ------------------------------------- Friends-----------------
    friend void update(inventory &o);
    friend void update(inventory o[], string name, string type, int len);
    friend void Purchase(inventory o[], string name, string type, int len);
    friend void sell(inventory o[], string name, string type, int len);
    friend void al_show(inventory o[], int len);
    friend void sh(inventory o[], string t, string n, int l);

public:
    void store_product()
    {
        system("cls");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter Product Type : ";
        getline(cin, product_type);
        cout << "Enter Product Name: ";
        getline(cin, product);
        cout << "Enter Purchase Price: ";
        cin >> Purchase_price;
        cout << "Enter Purchase Quantity: ";
        cin >> Purchase_itme;
        cout << "Enter Sell Price: ";
        cin >> Sell_price;
        Quantity = Purchase_itme;
        product_key = i;
        Show_item();
    }
    void Show_item()
    {
        system("cls");
        cout << "Product KEY : " << product_key << endl;
        cout << "Product Type: " << product_type << endl;
        cout << "Product Name: " << product << endl;
        cout << "Product Available Quantity: " << Quantity << endl;
        cout << "Product Purchase Price: " << Purchase_price << endl;
        cout << "Product Sell price: " << Sell_price << endl;
        cout << "Total Purchase Quantity: " << Purchase_itme << endl;
        cout << "Total sell Quantity: " << sell_itme << endl;
        cout << "Total Profit/Loss by This product : " << p_l << " RS" << endl;
        cout << "Press Enter to continue...\n\n";
        getchar();
        getchar();
    }
};
// ----------------- update Product-----------------------------------
void update(inventory &o)
{
    system("cls");
    int a;
    o.Show_item();
    cout << "What you want to update: \n";
    while (true)
    {
        cout << "1. Quantity       \t|\t2. Sell Price  \n";
        cout << "3. Product Name   \t|\t4. Product Type\n";
        cout << "5. Purchase Price \t|\t0. Exit        \n";
        cin >> a;
        switch (a)
        {
        case 1:
            cout << "Enter Product Quantity: ";
            cin >> o.Quantity;
            break;

        case 2:
            cout << "Enter Product Sell Price: ";
            cin >> o.Sell_price;
            break;

        case 3:
            cout << "Enter Product Name : ";
            cin >> o.product;
            break;
        case 4:
            cout << "Enter Product Type: ";
            cin >> o.product_type;
            break;

        case 5:
            cout << "Enter Product Purchase Price: ";
            cin >> o.Purchase_price;
            break;

        case 0:
            cout << "Exiting..\n";
            return;
            break;
        default:
            break;
        }
    }
    cout << "The Product Not Found !\n";
    cout << "Press Enter to continue...\n\n";
    getchar();
    system("cls");
}
// --------------------2. Name------------------------------------
void update(inventory o[], string name, string type, int len)
{
    system("cls");
    for (int i = 0; i < len; i++)
    {
        if (o[i].product_type == type && o[i].product == name)
        {
            int a;
            cout << "What you want to update: \n";
            while (true)
            {
                system("cls");
                cout << "1. Quantity           \t|\t2. Sell Price  \n";
                cout << "3. Product Name       \t|\t4. Product Type\n";
                cout << "5. Purchase Price     \t|\t0. Exit        \n";
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "Enter Product Quantity: ";
                    cin >> o[i].Quantity;
                    break;

                case 2:
                    cout << "Enter Product Sell Price: ";
                    cin >> o[i].Sell_price;
                    break;

                case 3:
                    cout << "Enter Product Name: ";
                    cin >> o[i].product;
                    break;
                case 4:
                    cout << "Enter Product Type: ";
                    cin >> o[i].product_type;
                    break;

                case 5:
                    cout << "Enter Product Purchase Price: ";
                    cin >> o[i].Purchase_price;
                    break;
                case 0:
                    cout << "Exiting..\n";
                    return;
                    break;
                default:
                    break;
                }
            }
        }
    }
    cout << "The Product Not Found !\n";
    cout << "Press Enter to continue...\n\n";
    getchar();
    system("cls");
}
// ---------------- Purchase Availabe Product----------------------------
void Purchase(inventory o[], string name, string type, int len)
{
    system("cls");
    for (int i = 0; i < len; i++)
    {
        if (o[i].product_type == type && o[i].product == name)
        {
            int Purchase;
            cout << "Enter Purchase Quantity: ";
            cin >> Purchase;
            o[i].Purchase_itme += Purchase;
            cout << "Old Purchase Price is :" << o[i].Purchase_price << endl;
            cout << "Enter New Purchase Price: ";
            cin >> o[i].Purchase_price;
            o[i].Quantity += Purchase;
            system("cls");
            o[i].Show_item();
            return;
        }
    }
    cout << "The Product Not Found !\n";
    cout << "Press Enter to continue...\n\n";
    getchar();
    system("cls");
}
// --------------- Sell Product ----------------------------------
void sell(inventory o[], string name, string type, int len)
{
    system("cls");
    for (int i = 0; i < len; i++)
    {
        if (o[i].product_type == type && o[i].product == name)
        {
            int sel;
        l:
            cout << "Enter Sell Quantity: ";
            cin >> sel;
            long long int se_price;
            if (sel > o[i].Quantity)
            {
                cout << "The disparity between the quantity available for sale and the quantity demanded is considerable. It is imperative to rectify this imbalance by ensuring that the available quantity aligns with the demand.\n";
                goto l;
            }
            o[i].sell_itme += sel;
            o[i].Quantity -= sel;
            cout << "Enter Sell Price: ";
            cin >> se_price;
            o[i].p_l += se_price - o[i].Purchase_price;
            system("cls");
            o[i].Show_item();
            cout << "Original sell price: " << o[i].Sell_price << "\nCurrent sell Price is: " << se_price << "\nThe Total differance Between Original sel price: " << se_price - o[i].Sell_price << endl;

            return;
        }
    }
    cout << "The Product Not Found !\n";
    cout << "Press Enter to continue...\n\n";
    getchar();
    system("cls");
}
// ----------------------- Show all -----------------------------------
void al_show(inventory o[], int len)
{
    system("cls");
    long long t_stock = 0;
    long double t_sell_i = 0, t_purchase_i = 0, t_sell_p = 0, t_purchase_p = 0;
    cout << "1. k = Key \n2. T = Product Type\n3. N = Product Name \n4. S_P = Sell Price\n5. S_I = Sell Item \n6. P_P = Purchase Price \n7. P_i = Purchase Item \n8. Q = Quantity\n\n";
    cout << " K " << setw(8) << " | " << setw(15) << " T " << setw(15) << " | " << setw(10) << " N " << setw(10) << " | " << setw(10) << " S_P " << setw(10) << " | " << setw(10) << " S_I " << setw(10) << " | " << setw(10) << " P_P " << setw(10) << " | " << setw(10) << " P_i " << setw(10) << " | " << setw(10) << " Q \n\n";
    for (int i = 0; i < len; i++)
    {
        cout << o[i].product_key << setw(5) << " | " << setw(5) << o[i].product_type << setw(5) << " | " << setw(5) << o[i].product << setw(5) << " | " << setw(5) << o[i].Sell_price << setw(5) << " | " << setw(5) << o[i].sell_itme << setw(5) << " | " << setw(5) << o[i].Purchase_price << setw(5) << " | " << setw(5) << o[i].Purchase_itme << setw(5) << " | " << setw(5) << o[i].Quantity << "\n\n\n";
        t_stock += o[i].Quantity;
        t_sell_i += o[i].sell_itme;
        t_sell_p += o[i].Sell_price;
        t_purchase_i += o[i].Purchase_itme;
        t_purchase_p += o[i].Purchase_price;
    }
    cout << "===============================================================================================\n";
    cout << "The Total Stock is: " << t_stock << "\nThe Total Stock Purchase Price: " << t_purchase_p << " RS " << "\nTotal Stock Purchase item: " << t_purchase_i
         << "\nThe Total Stock Sell Price: " << t_sell_p << " RS " << "\nTotal Stock Sell item: " << t_sell_i;
    cout << "Press Enter to continue...\n\n";
    getchar();
    getchar();
}
// ------------------ show by name ---------------------------------------------
void sh(inventory o[], string t, string n, int l)
{
    for (int i = 0; i < l; i++)
    {
        if (o[i].product == n && o[i].product_type == t)
        {
            o[i].Show_item();
            return;
        }
    }
    cout << "The Product Not Found !\n";
    cout << "Press Enter to continue...\n\n";
    getchar();
    system("cls");
}
int main()
{
    inventory item[999];
    string firm;
    while (true)
    {
        cout << "=====================================================================================================================================================\n";
        cout << setw(80) << "Welcome to Inventory Management \n";
        cout << "=====================================================================================================================================================\n\n\n";
        cout << "Press Enter to continue...\n\n";
        getchar();
        system("cls");
        cout << "Enter Your Command:- \n\n";
        cout << "1. Purchase New Product         \t|\t 2. Show Product Detail         \n";
        cout << "3. Sell Availabe Product        \t|\t 4. Purchase Available Product  \n";
        cout << "5. Update product               \t|\t 6. Show All Stock Detail       \n";
        int a;
        cin >> a;
        if (a == 1)
        {
            system("cls");
            item[i].store_product();
            i++;
        }
        else if (a == 2)
        {
            cout << "1. key \t|\t 2. Name\n";
            cin >> a;
            if (a == 1)
            {
                cout << "Enter Product Key: ";
                int k;
                cin >> k;
                system("cls");
                item[k].Show_item();
            }
            else if (a == 2)
            {
                string name, type;
                cout << "Enter Product Name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, name);
                cout << "Enter Product type: ";
                getline(cin, type);
                system("cls");
                sh(item, type, name, i);
            }
        }
        else if (a == 5)
        {
            a;
            cout << "Update Product\n1. KEY \t|\t2. Name\n";
            cin >> a;
            if (a == 1)
            {
                int k;
                cout << "Enter Product Key: ";
                cin >> k;
                system("cls");
                update(item[k]);
            }
            else if (a == 2)
            {
                string name, type;
                cout << "Enter Product Name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, name);
                cout << "Enter Product type: ";
                getline(cin, type);
                system("cls");
                update(item, name, type, i);
            }
        }
        else if (a == 4)
        {
            string name, type;
            cout << "Enter Product Name: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, name);
            cout << "Enter Product type: ";
            getline(cin, type);
            system("cls");
            Purchase(item, name, type, i);
        }
        else if (a == 3)
        {
            string name, type;
            cout << "Enter Product Name: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, name);
            cout << "Enter Product type: ";
            getline(cin, type);
            system("cls");
            sell(item, name, type, i);
        }
        else if (a == 6)
        {
            al_show(item, i);
        }
    }
}
