#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



class Vehicle {
public:
    string capacity;
    string type;
    string automanu; // a: automatic m:manual
    string make;     // Ford/Honda
    int model;       // 2020, etc
    int price;
    string available;

    Vehicle() {
        make = "";
        model = 0;
        automanu = "";
        capacity = "0";
        price = 0;
        available = "yes";
    }
    Vehicle(string make, int model, string automanu, int capacity, int price) {
        this->make = make;
        this->model = model;
        this->automanu = automanu;
        this->capacity = capacity;
        this->price = price;
        this->available = "yes";
    }
    
    Vehicle(string make, int model, string automanu, int price) {
        this->make = make;
        this->model = model;
        this->automanu = automanu;
        this->price = price;
        this->available = "yes";
    }

    string getAvailable() {
        return this->available;
    }

    void setAvailable(string available) {
        this->available = available;
    }
    
    virtual Vehicle operator=(const Vehicle& C)
      {
          this->type = C.type;
          this->make = C.make;
          this->model = C.model;
          this->automanu = C.automanu;
          this->capacity = C.capacity;
          this->price = C.price;
          this->available = C.available;
          
          return *this;
      }

    int calcInvoice(int day) { return price * day; }
    friend istream& operator>>(istream& is, Vehicle& t);
    friend ostream& operator<<(ostream& os, Vehicle& t);
};

istream& operator>>(istream& is, Vehicle& t) {
    is >> t.type >> t.make >> t.model >> t.automanu >> t.capacity >> t.price >> t.available;
    return is;
}
ostream& operator<<(ostream& os, Vehicle& t) { 
    os << t.type << " " << t.make << " " << t.model << " " << t.automanu << " " << t.capacity << " " << t.price;
    return os;
}

class Truck : public Vehicle {
public:
    Truck() : Vehicle() {
        type = "Truck";
    }

    Truck(string make, int model, string automanu, int capacity, int price) : Vehicle(make, model, automanu, capacity, price) {
        type = "Truck";
    }
    
    virtual Vehicle operator=(const Vehicle& C) 
     override {
          this->type = C.type;
          this->make = C.make;
          this->model = C.model;
          this->automanu = C.automanu;
          this->capacity = C.capacity;
          this->price = C.price;
          this->available = C.available;
          
          return *this;
      }

    int calcInvoice(int day) { return price * day; }
    friend istream& operator>>(istream& is, Truck& t);
    friend ostream& operator<<(ostream& os, Truck& t);
};

istream& operator>>(istream& is, Truck& t) {
    is >> t.type >> t.make >> t.model >> t.automanu >> t.capacity >> t.price >> t.available;
    return is;
}
ostream& operator<<(ostream& os, Truck& t) {
    os << t.type << " " << t.make << " " << t.model << " " << t.automanu << " " << t.capacity << " " << t.price << " " << t.available;
    return os;
}

class SUV : public Vehicle {
public:
    SUV() : Vehicle() {
        type = "SUV";
        capacity = "-";
    };

    SUV(string make, int model, string automanu, int price) : Vehicle(make, model, automanu, price) {
        type = "SUV";
    }
    
    virtual Vehicle operator=(const Vehicle& C) override
      {
          this->type = C.type;
          this->make = C.make;
          this->model = C.model;
          this->automanu = C.automanu;
          this->capacity = C.capacity;
          this->price = C.price;
          this->available = C.available;
          
          return *this;
      }

    int calcInvoice(int day) { return price * day; }
    friend istream& operator>>(istream& is, SUV& t);
    friend ostream& operator<<(ostream& os, SUV& t);
};

istream& operator>>(istream& is, SUV& t) {
    is >> t.type >> t.make >> t.model >> t.automanu >> t.available >> t.price >> t.available;
    return is;
}
ostream& operator<<(ostream& os, SUV& t) {
    os << t.type << " " << t.make << " " << t.model << " " << t.automanu << " " << "-" << " " << t.price << " " << t.available;
    return os;
}

class User {
private:
    string name;
    string password;
    int budget;

public:
    User() : name{ "" }, password{ "" }, budget{ 0 }{}

    void setName(string name) { this->name = name; }

    string getName() { return this->name; }

    void setPassword(string password) { this->password = password; }

    string getPassword() { return this->password; }

    void setBudget(int budget) { this->budget = budget; }

    int getBudget() { return this->budget; }

    void addBudget(int newBudget) { this->budget += newBudget; } 
   
};

void Resize(int& size, User*& arr); //to user array
void getUsers(User*& user, int& size, int& counter);
void setUsers(User*& user, int& size, int& counter);
void Resize(int& size, Vehicle*& arr); //to vehicle array
void getVehicles(Vehicle*& vehicle, int& size, int& counter);
void setVehicles(Vehicle*& vehicle, int& size, int& counter);
void mainMenu();
bool login(User*& user, int& i, int counter);
bool Adminlogin(User*& user, int& i, int counter);
void depositChoose(User*& user, Vehicle*& vehicle, int& i, int& vhcCounter);
void createUser(User*& user, int& size, int& counter);
void rentCar(User*& user, Vehicle*& vehicle, int vhcCounter, int i);
void returnCar(User*& user, Vehicle*& vehicle, int vhcCounter, int i);
void Resize(int& size, User*& arr);
void menuChoose(User* user, Vehicle* vehicle, int &vhcCounter, int &vhcSize, int &size, int &counter);

int main() {
    int size = 10; //user array size
    int counter=0;
    int vhcSize = 10; //Vehicle array size
    int vhcCounter = 0;

    User* user;
    user = new User[size];

    Vehicle* vehicle;
    vehicle = new Vehicle[vhcSize];
    getUsers( user, size, counter);
    getVehicles(vehicle, vhcSize, vhcCounter); 
    menuChoose(user, vehicle, vhcCounter, vhcSize, size, counter);
    
    setUsers(user, size, counter);
    setVehicles(vehicle, vhcSize, vhcCounter); 
	
	delete []user;
	delete []vehicle;
    return 0;
}




void mainMenu() {
    cout << endl
        << "\t\t\t\tWelcome" << endl<< "\t\t"; 
        for (int i = 0; i < 40; i++)
        {
            cout << "*";
        }
        cout<<endl<< "\t\t\t\t1-Login" << endl
        << "\t\t\t\t2-Register" << endl
        << "\t\t\t\t3-Exit" << endl;
}
void depositMenu(User* user, int& i) {
    
    system("CLS");
    cout << endl;
    cout << "\t\t" << user[i].getName()<<"\t\t\t" << "Your budget: " << user[i].getBudget()<<endl<< "\t\t";
    for (int i = 0; i < 40; i++)
    {
        cout << "*";
    }
    cout << endl
        << "\t\t\t1-Deposit Money" << endl
        << "\t\t\t2-Rent a Car" << endl
        << "\t\t\t3-Return the Car" << endl
        << "\t\t\t4-Exit" << endl;
    cout << endl;
    cout << "\t\tlutfen secim yapiniz:";
}

void menuChoose(User* user, Vehicle* vehicle, int& vhcCounter, int& vhcSize, int& size, int& counter) {
    int chs = 0; // chs = choose to welcome menu
    int i;
    bool flag;
    
    while (chs != 3) {
        mainMenu();
        cout << endl;
        cout << "\t\tPlease choose: ";
        
        cin >> chs;
        system("CLS");
        
        switch (chs)
        {
        case 1:
            flag = login(user, i, counter);
            if (flag == 1) {

                depositChoose(user, vehicle, i, vhcCounter);
            }
            break;
        case 2:
            createUser(user, size, counter);
            break;
        default:
        	if(chs!=3) {
        		cout << "\t\tPlease enter a valid number" << endl;
			}
            break;
        }       
    }
}

void getUsers(User*& user, int& size, int& counter) { //fill in the user array from file(user.txt)
    int i = 0;
    int budget;
    int counters=0;
    string name, password;

    ifstream infile;

    if (!infile.is_open())
    {
        infile.open("user.txt");
    }
  
    while (!infile.eof()) {
        infile >> name >> password >> budget;
        user[i].setName(name);
        user[i].setPassword(password);
        user[i].setBudget(budget);
        ++i;

        if (i == size) {
            Resize(size, user);
        }
    }

    counter = i-1;
    infile.close();
    ifstream inAdminFile;
    if (!infile.is_open())
    {
        inAdminFile.open("admin-1.txt");
    }
    inAdminFile >> name >> password;
    user[i].setName(name);
    user[i].setPassword(password);
    user[i].setBudget(budget);
    inAdminFile.close();
}


void setUsers(User*& user, int& size, int& counter) { //fill in the file(user.txt) from user array
    ofstream outfile;
    outfile.open("user.txt");

    for (int i = 0; i < counter; ++i) {
        outfile << user[i].getName() << " " << user[i].getPassword() << " " << user[i].getBudget() << endl;
    }

    outfile.close();
}


void getVehicles(Vehicle*& vehicle, int& size, int& counter) { //fill in the vehicle array from file(cars.txt)
    int i = 0;
    string make;

    Truck truck;
    SUV suv;

    ifstream infile;
    if (!infile.is_open())
    {
        infile.open("cars.txt");
    }

    while (!infile.eof()) {
        infile >> make;

        if (make == "Truck") {
            infile >> truck;
            vehicle[i] = truck;
        }
        else if (make == "SUV") {
            infile >> suv;
            vehicle[i] = suv;
        }
        ++i;

        if (i == size) {
            Resize(size, vehicle);
        }
    }
    counter = i - 1; 

    infile.close();
}

void setVehicles(Vehicle*& vehicle, int& size, int& counter) { //fill in the file(cars.txt) from vehicle array
    ofstream outfile;
    outfile.open("cars.txt");
    
    Truck truck;
    SUV suv;

    for (int i = 0; i < counter; ++i) {
    	if(vehicle[i].type == "Truck") {
    		truck = vehicle[i];
    		outfile << truck.type << " " << truck << endl;
		}
		else if(vehicle[i].type == "SUV") {
			suv = vehicle[i];
			outfile << suv.type << " " << suv << endl;
		}
        
    }

    outfile.close();
}

bool login(User*& user, int& i, int counter) {
    string name, password; // users name, surname and password   
    int budget;
    int flag = 0;

    cout << "\t\tPlease enter your username: ";
    getline(cin >> ws, name);

    for (i = 0; i < counter+1; i++) {
        if (name == user[i].getName()) {
            flag = 1;
            
            cout << "\t\tEnter your password: ";
            cin >> password;

            while (password != user[i].getPassword()) {
                cout << "\t\twrong password, try again(type 'exit' to exit):";

                cin >> password;

                if (password == "exit") {
                    flag = 0;
                    break;
                }
            }
            break;
        }
        
    }

    if (flag == 0 && password != "exit") {
        cout << "\t\tUser not found!" << endl;
    }

    return flag;
}



void depositChoose(User*& user, Vehicle*& vehicle, int& i, int& vhcCounter) {
    int chs=0;
    int budget;

    while (chs != 4) {

        
        depositMenu(user, i);

        cin >> chs;

        if (chs == 1) {
            cout << "\t\tEnter your budget: ";
            cin >> budget;
            user[i].addBudget(budget);
            cout << "\t\tYour budget is " << user[i].getBudget() << " dollars" << endl;
        }

        else if (chs == 2) {
            rentCar(user, vehicle, vhcCounter, i);
        }

        else if (chs == 3) {
            returnCar(user, vehicle, vhcCounter, i);
        }
        
    }
}



void createUser(User*& user, int& size, int& counter) {
    string name, password;
    int chs = 0, budget, i;

    int flag = 0;
    cout << "Create a username (Do not use spaces): "; 
                                  
    if (size == counter) {
        Resize(size, user);
    }
    getline(cin >> ws, name);

    for (i = 0; i < counter; ++i) {
        if (user[i].getName() == name) {
            cout << "You are already registered!" << endl;
            flag = 1;
        }
    }

    if (flag == 0) {
        cout << "create password: ";
        cin >> password;
        cout << "Do you want to deposit money into your account? (1-Yes, "
            "2-No): ";
        cin >> chs;

        if (chs == 1) {
            cout << "Enter your budget: ";
            cin >> budget;

            user[counter].setName(name);
            user[counter].setPassword(password);
            user[counter].setBudget(budget);

            counter++;
        }

        else if (chs == 2) {
            user[counter].setName(name);
            user[counter].setPassword(password);
            user[counter].setBudget(0);

            counter++;
        }
    }
}

void rentCar(User*& user, Vehicle*& vehicle, int vhcCounter, int i) {
    int count = 1;
    
    int chs;
    int day;
    int j;
    
    system("CLS");
    cout << endl;
    cout << "\t\t" << user[i].getName() << "\t\t\t\t" << "Your budget: " << user[i].getBudget() << endl << "\t\t";//*******duzelt
    for (int i = 0; i < 55; i++)
    {
        cout << "*";
    }
   
    cout << endl;
    cout << "\t\t" << "    " << "\t" << "Type" << "\t" << "Make" << "\tModel" << "\tAuto-Manual" << "\tCapacity" <<"\tPrice" << endl<<"\t\t";
    for (int i = 0; i < 55; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int j = 0; j < vhcCounter; ++j) {
        if (vehicle[j].getAvailable() == "yes") {
            cout << "\t\t" <<count<<"\t" << vehicle[j].type << "\t" << vehicle[j].make << "\t" << vehicle[j].model << "\t" << vehicle[j].automanu << "\t\t" << vehicle[j].capacity << "\t\t" << vehicle[j].price << endl;
            ++count;
        }
        
    }

    cout << endl << "\t\tPress '0' for a higher menu" << endl;

    cout << "\t\tWhat number vehicle do you want? ";
    cin >> chs;

    if (chs != 0) {
        cout << "\t\tHow many days do you want to rent? ";
        cin >> day;

        if (day > 0) {
            count = 0;
            for (j = 0; j < vhcCounter; ++j) {
                if (vehicle[j].getAvailable() == "yes") {
                    ++count;
                    if (count == chs) {
                        if (user[i].getBudget() >= vehicle[j].calcInvoice(day)) {
                            vehicle[j].available = user[i].getName();
                            
                            user[i].setBudget(user[i].getBudget() - vehicle[j].calcInvoice(day));
                            
                            break;
                        }

                        else {
                            cout << "Your budget is insufficient!" << endl;
                            break;
                        }
                    }
                }
            }
        }
        else {
            cout << "Please enter positive number!" << endl;
        }
    }


}

void returnCar(User*& user, Vehicle*& vehicle, int vhcCounter, int i) {
    int count = 0;
    int chs;
    int j;

    cout << endl << "Vehicles you have rented:" << endl << "0- Exit" << endl;
    for (j = 0; j < vhcCounter; ++j) {

        if (vehicle[j].getAvailable() == user[i].getName()) {
            ++count;
            cout << count << "- " << vehicle[j] << endl;
        }
    }
    cout << "The number of the vehicle you want to return: ";
    cin >> chs;

    count = 0;
    for (j = 0; j < vhcCounter; ++j) {
        if (vehicle[j].getAvailable() == user[i].getName()) {
            ++count;
            if (count == chs) {
                vehicle[j].setAvailable("yes");
                cout << vehicle[j] << " is returned!" << endl;
                break;
            }
        }
    }
}

void Resize(int& size, User*& arr)
{ 
    int newSize = size + 10;
    User* newArr = new User[newSize];

    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }

    size = newSize;
    delete[] arr;
    arr = newArr;
}

void Resize(int& size, Vehicle*& arr) {
    int newSize = size + 20;
    Vehicle* newArr = new Vehicle[newSize];

    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }

    size = newSize;
    delete[] arr;
    arr = newArr;
}

