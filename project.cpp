#include<iostream>
#include<conio.h>
#include<windows.h>
#include<unordered_map>
#include<stack>
#include<iomanip>
#include<fstream>
#include<vector>
#include<string>
#include <cstdlib>  // For system("cls")
#include <cstring>
#include <algorithm>
using namespace std;


const string RESET = "\033[0m";
const string BLACK = "\033[30m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string ORANGE = "\033[38;5;208m";
const string BOLDBLACK = "\033[1m\033[30m";
const string BOLDRED = "\033[1m\033[31m";
const string BOLDGREEN = "\033[1m\033[32m";
const string BOLDYELLOW = "\033[1m\033[33m";
const string BOLDBLUE = "\033[1m\033[34m";
const string BOLDMAGENTA = "\033[1m\033[35m";
const string BOLDCYAN = "\033[1m\033[36m";
const string DARKRED = "\033[38;2;139;0;0m";
const string BOLD = "\033[1m";
#define DELAY_MS 30 
class LoadingAnimation {
private:
    const int animationLength = 35;
    const char symbol = 219;
    const string color = YELLOW;
    const string resetColor = RESET;
    const int delay = DELAY_MS;

public:
    void start() {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\tLoading ";
        for (int i = 0; i < animationLength; i++) {
            cout << color << symbol << resetColor;
            Sleep(delay);
        }
    }
    void waitForKeyPress() {
        cout << "\n\t\t\t\t\tPress Enter to continue: ";
        // cin.ignore();
        cin.get();  // Wait for Enter key
    }
};

void Text_Animation(const string& a, const string& color = "RESET", int speed = 0) {
    string selectedColor = RESET;
    if (color == "BLACK") {
        selectedColor = BLACK;
    } else if (color == "RED") {
        selectedColor = RED;
    } else if (color == "GREEN") {
        selectedColor = GREEN;
    } else if (color == "YELLOW") {
        selectedColor = YELLOW;
    } else if (color == "BLUE") {
        selectedColor = BLUE;
    } else if (color == "MAGENTA") {
        selectedColor = MAGENTA;
    } else if (color == "CYAN") {
        selectedColor = CYAN;
    } else if (color == "BOLDBLACK") {
        selectedColor = BOLDBLACK;
    } else if (color == "BOLDRED") {
        selectedColor = BOLDRED;
    } else if (color == "BOLDGREEN") {
        selectedColor = BOLDGREEN;
    } else if (color == "BOLDYELLOW") {
        selectedColor = BOLDYELLOW;
    } else if (color == "BOLDBLUE") {
        selectedColor = BOLDBLUE;
    } else if (color == "BOLDMAGENTA") {
        selectedColor = BOLDMAGENTA;
    } else if (color == "BOLDCYAN") {
        selectedColor = BOLDCYAN;
    } else if (color == "ORANGE") {
        selectedColor = ORANGE;
    } else if (color == "DARKRED") {
        selectedColor = DARKRED;
    }
    for (char c : a) {
        cout << selectedColor << c;
        Sleep(speed);
    }
    cout << RESET;
}

double  total_salary=0;
double total_profit=0;
const int MAX_PRODUCTS = 30;
const int MAX_EMPLOYEES = 10;
#define DELAY_MS 60      

class Admin {
private:
    string username;
    string password;
    const string correctUsername1 = "abdullah"; 
    const string correctUsername2 = "zain";
    const string correctPassword = "1234"; 

public:
    void enterUsername() {
    
         Text_Animation("\n\t\t\t\t\tEnter Username : ", "YELLOW", 30);
        cin >> username;
        transform(username.begin(), username.end(), username.begin(), ::tolower);
    }


    void enterPassword() {
        password.clear();
        char ch;
        Text_Animation("\n\t\t\t\t\tEnter password : ", "YELLOW", 30);
        while ((ch = _getch()) != '\r') {
            if (ch == '\b') { // Handle backspace
                if (!password.empty()) {
                    cout << "\b \b"; // Erase the last asterisk
                    password.pop_back();
                }
            } else {
                password.push_back(ch);
                cout << '*';
            }
        }
        cout << endl;
    }

    bool verifyCredentials() const {
        return ((username == correctUsername1 || username == correctUsername2) && password == correctPassword);
    }

    void showNextScreen() const {
         Text_Animation("\n\t\t\t\t\tAccess granted. Welcome to the portal!\n\n", "YELLOW", 30);
    }
};


struct item
{
    int item_id; 
    string item_name;
    double sell_price;
    double cost_price;
    int quantity_items;
    item* next,*prev; 
    item(int id, string name, double sell, double cost, int quantity){
        item_id = id;
        item_name = name;
        sell_price = sell;
        cost_price = cost;
        quantity_items=quantity;
        next=prev=nullptr;
    }
};

class product{
    item*head;
    item*tail;

    public:
    product(){
        head=tail=nullptr;
        load_from_file();
        system("cls");

    }
    item* get_head() {
    return head; 
    }
    
    void additem(int id, string name, double sell, double cost, int quantity){
        item*newitem=new item(id,name,sell,cost,quantity);
        item*temp=head;      
        if(head==nullptr){
            head=newitem;
            tail=newitem;
            cout<<"The item is added!"<<endl;
            cout<<id<<" "<<name<<" "<<sell<<" "<<cost<<" "<<quantity<<endl;
             profit();
             save_to_file();
        }
        else{
            while (temp!=nullptr)
            {
                if(temp->item_id==id){
                    cout<<"The item already exists!"<<endl;
                    delete newitem;
                    return;
                }
                temp=temp->next;
            }
            temp=head;
            while(temp!=nullptr){
                if(temp->item_id>id){
                    newitem->next=temp;
                    newitem->prev=temp->prev;
                    if(temp->prev!=nullptr){
                        temp->prev->next=newitem;
                    }
                    else{
                        head=newitem;
                    }
                    temp->prev=newitem;
                    save_to_file();
                    return;
                }
                temp=temp->next;
            }
        
            tail->next=newitem;
            newitem->prev=tail;
            tail=newitem;

        
            cout<<"The item is added!"<<endl;
            cout<<id<<" "<<name<<" "<<sell<<" "<<cost<<" "<<quantity<<endl;
            profit();
            save_to_file();
            load_from_file();
    }
    }
        
    double profit(){
        total_profit=0;
        item*temp=head;
        while(temp!=nullptr){
            total_profit+=(temp->sell_price-temp->cost_price)*temp->quantity_items;

            temp=temp->next;
    }

    cout<<"Total profit (per year):"<<total_profit*365<<endl;
    } 
    
    void update_profit(int cost_price, int sell_price,int quantity_items) {
    int previous_profit = (cost_price - sell_price) *quantity_items;
    total_profit -= previous_profit;
        }


    void delete_item(int id){
        item* temp=head;
        if(head==nullptr){
            cout<<"Item List is empty"<<endl;
            return;
        }

           if (head->item_id == id) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // List becomes empty
        }

        delete temp;
        cout<<"This item has been Deleted! "<<temp->item_name<<endl;
        profit();
        save_to_file();
        return;
    }
        
    while (temp != nullptr) {
        if (temp->item_id ==id) {
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;  
                
            }
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev; 
            }
            if (temp == tail) {
                tail = temp->prev; 
            }
           delete temp;
           cout<<"This item has been Deleted! "<<temp->item_name<<endl;
            profit();
            save_to_file();
           return;
        }
        temp = temp->next;  
        }
    cout << "Item ID : " << id << " not found\n";
        
    }


    void update_product(int id, string name, double sell, double cost, int quantity){
        item* temp=head;
        while (temp!=nullptr){
            if(temp->item_id==id){
                total_profit-=((temp->cost_price-temp->sell_price)*temp->quantity_items);
                temp->item_name=name;
                temp->sell_price=sell;
                temp->cost_price=cost;
                temp->quantity_items=quantity;
                total_profit+=((temp->cost_price-temp->sell_price)*temp->quantity_items);
                cout<<"Product updated successfully"<<endl;
                save_to_file();
                load_from_file();
                return;
            }
            temp=temp->next;

        }
        cout << "Item with ID " << id << " not found.\n";
    }

    void update_product_quantity(int id, int quantity){

    }

    void display_item(){

        item*temp=head;
        if(head==nullptr){
            cout<<"Item List is empty"<<endl;
        }  
    cout << setw(50) << left << "Product Details" << endl;
    cout << setw(50) << setfill('=') << "" << endl;
    cout << setw(5) << left << "ID"
         << setw(15) << "Name"
         << setw(15) << "Selling Price"
         << setw(15) << "Cost Price"
         << setw(10) << "Quantity" << endl;
    cout << setw(50) << setfill('-') << "" << endl;

   
    while (temp != nullptr) {
        cout << setw(5) << left << temp->item_id
             << setw(15) << temp->item_name
             << setw(15) << temp->sell_price
             << setw(15) << temp->cost_price
             << setw(10) << temp->quantity_items << endl;
        temp = temp->next;
    }
}

    void display_item1(){

        item*temp=head;
        if(head==nullptr){
            cout<<"Item List is empty"<<endl;
        }  
    cout << setw(50) << left << "Product Details" << endl;
    cout << setw(50) << setfill('=') << "" << endl;
    cout << setw(5) << left << "ID"
         << setw(15) << "Name"
         << setw(15) << "Selling Price"
         << setw(10) << "Quantity" << endl;
    cout << setw(50) << setfill('-') << "" << endl;

   
    while (temp != nullptr) {
        cout << setw(5) << left << temp->item_id
             << setw(15) << temp->item_name
             << setw(15) << temp->sell_price
             << setw(10) << temp->quantity_items << endl;
        temp = temp->next;
    }
}



    void Delete_product(){
        item* temp=head;
        while (temp!=nullptr)
        {
            item* next=temp->next;
            delete temp;
            temp=next;
        }
        head=tail=nullptr;
        cout<<"All Products are Deleted!"<<endl;
    }

void save_to_file() {
    ofstream file("products.txt");
    if (!file.is_open()) {
        cout << "Error: Unable to open file for saving products.\n";
        return;
    }
    item* temp = head;
    while (temp != nullptr) {
        file << temp->item_id << " " 
             << temp->item_name << " " 
             << temp->sell_price << " " 
             << temp->cost_price << " " 
             << temp->quantity_items << "\n";
        temp = temp->next;
    }
    file.close();
    //cout << "Products saved successfully to 'products.txt'.\n";
}

void load_from_file() {
    ifstream file("products.txt");
    if (!file.is_open()) {
        cout << "Error: Unable to open file for loading products.\n";
        return;
    }
    int id, quantity;
    string name;
    double sell, cost;

    while (file >> id >> ws) {
        getline(file, name, ' ');
        file >> sell >> cost >> quantity;
        additem(id, name, sell, cost, quantity); // Reuse additem logic
    }
    file.close();
    //cout << "Products loaded successfully from 'products.txt'.\n";
}

};

struct employee{
    int Employee_id; 
    string Employee_name,Employee_designtion;
    double Employee_salary;
    employee* next,*prev; 
    employee(int id, string name, string designtion,double salary){
        Employee_id = id;
        Employee_name = name;
        Employee_designtion=designtion;
        Employee_salary=salary;
        next=prev=nullptr;
    }

};
class employee_detail{
    employee*head, *tail;

    public:
    employee_detail(){
        head=tail=nullptr;

    }


    void Add_Employee(int id, string name, string designtion,double salary){
        employee* new_employee = new employee(id, name, designtion, salary);
        if(head==nullptr){
            head=tail=new_employee;
            new_employee->next=new_employee->prev=nullptr;
            cout<<"The Employee is added!"<<endl;
            save_to_file();
            load_from_file();
        }
        else{
        employee* temp=head;
            while(temp!=nullptr){
                if(temp->Employee_id==id){
                    cout<<"Employee Already Exists!"<<endl;
                    delete new_employee;
                    return;       
                }
                temp=temp->next;
            }

        temp=head;
        while(temp!=nullptr){
            if(temp->Employee_id>id){
            new_employee->next = temp;
            new_employee->prev = temp->prev;

            if (temp->prev != nullptr) {
                temp->prev->next = new_employee;
            } else {
                head = new_employee;
                }
            
            temp->prev = new_employee;
            cout<<"The Employee is added!"<<endl;
            save_to_file();
            load_from_file();
            return;
        }
        temp=temp->next;
  }  
        tail->next=new_employee;
         new_employee->prev=tail;
        tail=new_employee;
        new_employee->next=nullptr;
        cout<<"The Employee is added!"<<endl;
        save_to_file();
    }
    }



   void update_Employee(int id, string name, string designtion,double salary){
        employee* temp=head;
        while (temp!=nullptr){
            if(temp->Employee_id==id){
                temp->Employee_name=name;
                temp->Employee_designtion=designtion;
                temp->Employee_salary=salary;
                cout<<"Employee with Id"<<id<<" has been updated!"<<endl;
                save_to_file();
                }

            temp=temp->next;

        }
        cout << "Employee with ID " << id << " not found.\n";
    }


    
void delete_Employee(int id){
        employee* temp=head;
        if(head==nullptr){
            cout<<"Item List is empty"<<endl;
            return;
        }
           if (head->Employee_id == id) {
                 head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
        }   else {
            tail = nullptr; 
        }

           } 
        delete temp;
        cout<<"This Employee has been Deleted! "<<temp->Employee_name<<endl;
        save_to_file();
        return;
   } 
    

void salary_calculate(){}

 void Employee_display(){
    employee* temp = head;
    if(head==nullptr){
        cout<<"No Employees in the List"<<endl;
        return;
    }
    while (temp!=nullptr)
    {
        cout<<temp->Employee_id<<" "<<temp->Employee_name<<" "<<temp->Employee_designtion<<" "<<temp->Employee_salary<<endl;
        temp=temp->next;
            }
     }


        void Delete_Employee(){
        employee* temp=head;
        while (temp!=nullptr)
        {
            employee* next=temp->next;
            delete temp;
            temp=next;
        }
        head=tail=nullptr;
        cout<<"All Employees are Deleted!"<<endl;
    }

    void save_to_file() {
    ofstream file("Employee.txt");
    if (!file.is_open()) {
        cout << "Error: Unable to open file for saving products.\n";
        return;
    }
    employee* temp = head;
    while (temp != nullptr) {
        file << temp->Employee_id << " " 
             << temp->Employee_name<< " " 
             << temp->Employee_designtion<< " " 
             << temp->Employee_salary<<"\n";
        temp = temp->next;
    }
    file.close();
   // cout << "Employee Detailed saved successfully to 'Employee.txt'.\n";
}


    void load_from_file() {
        ifstream file("employee.txt");
        if (!file.is_open()) {
            cout << "Error: Unable to open file for loading employees.\n";
            return;
        }
        int id;
        string name, designation;
        double salary;

        while (file >> id >> ws) {
            getline(file, name, ' ');
            getline(file, designation, ' ');
            file >> salary;
            Add_Employee(id, name, designation, salary); // Reuse Add_Employee logic
        }
        file.close();
     //   cout << "Employees loaded successfully from 'employees.txt'.\n";
    }


};

void manage_supermarket(product& p, employee_detail& e,Admin &password1 ) {
    int choice;
      while (true) {
            system("cls");
        password1.enterUsername();
        password1.enterPassword();
    if (password1.verifyCredentials()) {
        password1.showNextScreen();
        break;
    } else {
        system("cls");
        Text_Animation("\n\t\t\t\t\tIncorrect username or password. Access denied.\n", "RED", 30);
        system("cls");
        
        Text_Animation("\n\t\t\t\t\tPlease try again! Enter correct username and password.\n", "GREEN", 30);

    }
    }
    do {
        
        system("cls");
        Text_Animation("\n\t\t\t\t\t--- Supermarket Management System ---\n", "GREEN", 30);
        Text_Animation("\n\t\t\t\t\t1. Add Product\n", "GREEN", 20);
        Text_Animation("\n\t\t\t\t\t2. Display Products\n", "GREEN", 20);
        Text_Animation("\n\t\t\t\t\t3. Update Product\n", "GREEN", 20);
        Text_Animation("\n\t\t\t\t\t4. Delete Product\n", "GREEN", 20);
        Text_Animation("\n\t\t\t\t\t5. Show Product Profit\n", "GREEN", 20);
        Text_Animation("\n\t\t\t\t\t6. Add Employee\n", "GREEN", 20);
        Text_Animation("\n\t\t\t\t\t7. Display Employees\n", "GREEN", 20);
        Text_Animation("\n\t\t\t\t\t8. Update Employee\n", "GREEN", 20);
        Text_Animation("\n\t\t\t\t\t9. Delete Employee\n", "GREEN", 20);
        Text_Animation("\n\t\t\t\t\t10. Exit\n", "GREEN", 20);
        Text_Animation("\n\t\t\t\t\tEnter your choice: ", "GREEN", 20);
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            int id, quantity;
            string name;
            double cost, sell;
            Text_Animation("\n\t\t\t\t\tEnter product ID:\n", "GREEN", 20);
            cin >> id;
            Text_Animation("\n\t\t\t\t\tEnter product name:\n","GREEN",20);
            cin.ignore();
            getline(cin, name);
            Text_Animation("\n\t\t\t\t\tEnter cost price: \n", "GREEN",20);
            cin >> cost;
            Text_Animation("\n\t\t\t\t\tEnter selling price: \n", "GREEN",20);
            cin >> sell;
            Text_Animation("\n\t\t\t\t\tEnter quantity: \n", "GREEN",20);
            cin >> quantity;
            p.additem(id, name, sell, cost, quantity);
            cin.ignore();
            cin.get();
            
            break;
        }
        case 2:
            system("cls");
            p.display_item();
            cin.ignore();
            cin.get();
            break;
        case 3: {
            int id, quantity;
            string name;
            double cost, sell;Text_Animation("\n\t\t\t\t\tEnter product ID to update: ", "GREEN", 20);
            cin >> id;
            Text_Animation("\n\t\t\t\t\tEnter updated product name: ", "GREEN", 20);
            cin.ignore(); // Clear the input buffer
            getline(cin, name);
            Text_Animation("\n\t\t\t\t\tEnter updated cost price: ", "GREEN", 20);
            cin >> cost;
            Text_Animation("\n\t\t\t\t\tEnter updated selling price: ", "GREEN", 20);
            cin >> sell;
            Text_Animation("\n\t\t\t\t\tEnter updated quantity: ", "GREEN", 20);
            cin >> quantity;
            p.update_product(id, name, sell, cost, quantity);
            cin.ignore();
            cin.get();
            break;
        }
        case 4: {
            int id;
            Text_Animation("\n\t\t\t\t\tEnter product ID to delete: ", "GREEN", 20);
            cin >> id;
            p.delete_item(id);
            cin.ignore();
            cin.get();
            break;
        }
        case 5:{
            p.profit();
            cin.ignore();
            cin.get();
            break;
        }
        case 6: {
            int id;
            string name, designation;
            double salary;Text_Animation("\n\t\t\t\t\tEnter employee ID: ", "GREEN", 20);
            cin >> id;
            Text_Animation("\n\t\t\t\t\tEnter employee name: ", "GREEN", 20);
            cin.ignore(); // Clear the input buffer
            getline(cin, name);
            Text_Animation("\n\t\t\t\t\tEnter designation: ", "GREEN", 20);
            getline(cin, designation);

            Text_Animation("\n\t\t\t\t\tEnter salary: ", "GREEN", 20);
            cin >> salary;

            e.Add_Employee(id, name, designation, salary);
            cin.ignore();
            cin.get();
            break;
        }
        case 7:
            e.Employee_display();
            cin.ignore();
            cin.get();
            break;
        case 8: {
            int id;
            string name, designation;
            double salary;Text_Animation("\n\t\t\t\t\tEnter employee ID to update: ", "GREEN", 20);
            cin >> id;
            Text_Animation("\n\t\t\t\t\tEnter updated employee name: ", "GREEN", 20);
            cin.ignore(); 
            getline(cin, name);
            Text_Animation("\n\t\t\t\t\tEnter updated designation: ", "GREEN", 20);
            getline(cin, designation);
            Text_Animation("\n\t\t\t\t\tEnter updated salary: ", "GREEN", 20);
            cin >> salary;

            e.update_Employee(id, name, designation, salary);
            cin.ignore();
            cin.get();
            break;
        }
        case 9: {
            int id;
            Text_Animation("\n\t\t\t\t\tEnter employee ID to delete: ", "GREEN",20);
            cin >> id;
            e.delete_Employee(id);
            cin.ignore();
            cin.get();
            break;
        }
        case 10:
            Text_Animation("\n\t\t\t\t\tExiting the program...", "GREEN", 20);
            cin.ignore();
            cin.get();
            break;
        default:
        Text_Animation("\n\t\t\t\t\tInvalid choice. Please choose a valid option.","RED",20);
        }
    } while (choice != 10);
}
    struct CartItem {
        int item_id;
        string item_name;
        double price;
        int quantity;

        CartItem(int id, string name, double pr, int qty) : item_id(id), item_name(name), price(pr), quantity(qty) {}
    };

class CustomerPanel:public product {
    vector<CartItem> cart;
       

public: 

    CustomerPanel(){
        cart.clear();
        load_from_file();
    }
   
    void add_to_cart() {
        int id, qty;
        cout << "Enter the product ID to add to cart: ";
        cin >> id;
        cout << "Enter quantity: ";
        cin >> qty;

        item* product = find_product(id);
        if (product) {
            if (product->quantity_items >= qty) {
                cart.push_back(CartItem(id, product->item_name, product->sell_price, qty));
                product->quantity_items -= qty;
                cout << "Item added to cart!" << endl;
            } else {
                cout << "Not enough stock available!" << endl;
            }
        } else {
            cout << "Product not found!" << endl;
        }
    }

    void display_cart() {
        if (cart.empty()) {
            cout << "Your cart is empty." << endl;
            return;
        }

        cout << setw(50) << left << "Cart Details" << endl;
        cout << setw(50) << setfill('=') << "" << endl;
        cout << setw(5) << left << "ID"
             << setw(15) << "Name"
             << setw(10) << "Price"
             << setw(10) << "Quantity"
             << setw(10) << "Total" << endl;
        cout << setw(50) << setfill('-') << "" << endl;

        double total = 0;
        for (const auto& item : cart) {
            double item_total = item.price * item.quantity;
            total += item_total;
            cout << setw(5) << left << item.item_id
                 << setw(15) << item.item_name
                 << setw(10) << item.price
                 << setw(10) << item.quantity
                 << setw(10) << item_total << endl;
        }
        cout << setw(50) << setfill('-') << "" << endl;
        cout << "Total Cart Value: $" << total << endl;
    }

    void remove_from_cart() {
        int id;
     Text_Animation("\n\t\t\t\tEnter the product ID to remove from cart: ", "BOLDBLUE", 30);
        cin >> id;

        for (auto it = cart.begin(); it != cart.end(); ++it) {
            if (it->item_id == id) {
                item* product = find_product(id);
                if (product) {
                    product->quantity_items += it->quantity;  
                }
                cart.erase(it);
                cout << "Item removed from cart." << endl;

                
                return;
            }
        }
        Text_Animation("Item not found in your cart.","BOLDRED",20);

    }

    void buy_items() {
        if (cart.empty()) {
            cout << "Your cart is empty!" << endl;
            return;
        }

        double total = 0;
        for (const auto& item : cart) {
            total += item.price * item.quantity;
        }

Text_Animation("\n\t\t\t\t=========================================", "BOLDBLUE", 30);
Text_Animation("\n\t\t\t\t|         Purchase Summary              |", "BOLDBLUE", 30);
Text_Animation("\n\t\t\t\t=========================================", "BOLDBLUE", 30);
Text_Animation("\n\t\t\t\t| Proceeding with purchase...           |", "BOLDGREEN", 30);

cout << fixed << setprecision(2);  // Ensures 2 decimal places for total
Text_Animation("\n\t\t\t\t| Total to pay: $" + to_string(total) + "                |", "BOLDYELLOW", 30);

Text_Animation("\n\t\t\t\t| Purchase successful!                  |", "BOLDGREEN", 30);
Text_Animation("\n\t\t\t\t| Thank you for your order!             |", "BOLDGREEN", 30);
Text_Animation("\n\t\t\t\t=========================================", "BOLDBLUE", 30);

        save_to_file();
        cart.clear(); 
            }

    void cancel_order() {
        if (cart.empty()) {
            cout << "" << endl;
            Text_Animation("\n\t\t\t\tYour cart is empty! No orders to cancel.", "BOLDCYAN", 30);
            
            return;
        }

        for (const auto& cart_item : cart) {
            item* product = find_product(cart_item.item_id);
            if (product) {
                product->quantity_items += cart_item.quantity;  
            }
        }
        Text_Animation("\n\t\t\t\tOrder canceled. All items returned to inventory.", "BOLDCYAN", 30);
        
        cart.clear();  
    }
    void display_menu() {
    int choice;
    while (true) {
        Text_Animation("\n\t\t\t\t===== Welcome to the shopping cart!=====", "BOLDCYAN", 30);
        Text_Animation("\n\t\t\t\t1. View Products", "BOLDCYAN", 30);
        Text_Animation("\n\t\t\t\t2. Add to Cart", "BOLDCYAN", 30);
        Text_Animation("\n\t\t\t\t3. View Cart", "BOLDCYAN", 30);
        Text_Animation("\n\t\t\t\t4. Buy Items", "BOLDCYAN", 30);
        Text_Animation("\n\t\t\t\t5. Cancel Order", "BOLDCYAN", 30);
        Text_Animation("\n\t\t\t\t6. Exit", "BOLDCYAN", 30);
        Text_Animation("\n\t\t\t\tEnter your choice (1-6): ", "BOLDCYAN", 30);

        cin >> choice;
        switch (choice) {
            case 1:
            load_from_file();
            system("cls");
            display_item1();
                break;
            case 2:
                add_to_cart();
                break;
            case 3:
                display_cart();
                break;
            case 4:
                buy_items();
                break;
            case 5:
                cancel_order();
                break;
            case 6:
                cout << "Thank you for visiting. Goodbye!" << endl;
                Text_Animation("\n\t\t\t\tThank you for visiting. Goodbye!", "BOLDCYAN", 30);
                return;  
            default:
                Text_Animation("\n\t\t\t\tInvalid choice. Please try again.", "BOLDCYAN",30);
                break;
        }
    }
}


private:
    item* find_product(int id) {
        item* temp =get_head();
        while (temp) {
            if (temp->item_id == id) {
                return temp; 
            }
            temp = temp->next;
        }
        return nullptr; 
    }
};
int main() {
   system("cls");
    product p;
    employee_detail e;
    CustomerPanel c;
    LoadingAnimation loadingAnimation;
    loadingAnimation.start();
    loadingAnimation.waitForKeyPress();
    Admin portal;
    
    system("cls");
   while (true) {

    portal.enterUsername();
    portal.enterPassword();
    if (portal.verifyCredentials()) {
        portal.showNextScreen();
        break;
    } else {
        system("cls");
        Text_Animation("\n\t\t\t\t\tIncorrect username or password. Access denied.\n", "RED", 30);
        system("cls");
        Text_Animation("\n\t\t\t\t\tPlease try again! Enter correct username and password.\n", "GREEN", 30);

    }
    }
    int choice;

    while (true) {
        system("cls");
        Text_Animation("\n\t\t\t\t\t1. Admin Panel\n", "BOLDCYAN", 30);
        Text_Animation("\n\t\t\t\t\t2. Customer Panel\n", "BOLDCYAN", 30);
        Text_Animation("\n\t\t\t\t\t3. Exit", "BOLDCYAN\n", 30);
        Text_Animation("\n\t\t\t\t\tEnter your choice: ", "BOLDCYAN\n", 30);
        cin >> choice;
        switch (choice) {
            case 1:
                manage_supermarket(p,e,portal);
                break;
            case 2: {
                c.display_menu();
                break;
            }
            case 3:
            system("cls");
            Text_Animation("\n\t\t\t\t\tGood bye! have a nice day.\n", "BOLDMAGENTA", 30);
                break;
            default:
                Text_Animation("\n\t\t\t\t\tInvalid option. Please try again.\n", "RED", 30);
        }
    }
    return 0;
}  