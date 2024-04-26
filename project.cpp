#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <ctime>
using namespace std;
void loading()
{
    cout << "\t\t\t\tLoading..." << endl;
    char x = 219;
    cout << endl;
    cout << "\t\t\t";
    for (int i = 0; i <= 35; i++)
    {
        cout << x;
        Sleep(75);
    }
    cout << endl;
}
double profit;
// going to use same id in room,guests,payment class to fetching information....

string G_R; // guest to Recetionist
string R_E; // recetionist to employee

void header()
{
    cout << "================================================================" << endl;
    cout << "=                       Hotel Management System                =" << endl;
    cout << "================================================================" << endl;
}
bool employee_login = false;
bool Guest_login = false;
void login_Emplyee(fstream &stream)
{
    string E_n;
    int Empl_id;
    string posi;
    double sa;
    int Man_id;
    string pass;
    fstream temp_employee_stream;
    string up_employee, employee_posi;
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    stream.open("Employee.txt", ios::app | ios::in);
    while (stream >> E_n >> Empl_id >> posi >> sa >> Man_id >> pass)
    {
        if (username == E_n && password == pass)
        {
            employee_login = true;
        }
    }
}
void login_guest(fstream &stream);
void guest_registor(fstream &stream)
{
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    stream.open("login_guest.txt", ios::app | ios::out);
    stream << username << " " << password << endl;
    cout << "you registored successfully.." << endl;
    stream.close();
    login_guest(stream);
}
void login_guest(fstream &stream)
{
    string g_n;
    string g_id;
    stream.open("login_guest.txt", ios::app | ios::in);
    string username, password;
    cout << "Loagin---" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    while (stream >> g_n >> g_id)
    {
        if (username == g_n && password == g_id)
        {
            Guest_login = true;
            cout << "you Login successfully.." << endl;
        }
    }
}
void login_system_guest(int choice, fstream &stream)
{
    if (choice == 1)
    {
        guest_registor(stream);
    }
    else if (choice == 2)
    {
        login_guest(stream);
    }
}
class Reservations;
class Employee;
int filelength;
int filelengthE;
int filelengthR;
class Guest
{
private:
    int Guest_id;
    string Guest_name;
    string Guest_contact;
    string Guest_email;

public:
    Guest()
    {
    }
    Guest(int id, string name, string contact, string email)
    {
        Guest_id = id;
        Guest_name = name;
        Guest_contact = contact;
        Guest_email = email;
    }
    void print_guest()
    {
        cout << "========  Guest ========" << endl;
        cout << " Guest Id: " << Guest_id << endl;
        cout << " Guest Name: " << Guest_name << endl;
        cout << " Guest Contact: " << Guest_contact << endl;
        cout << " Guest Email: " << Guest_email << endl;
    }

    void make_reservation()
    {
    }
    void cancel_reservation()
    {
    }
};
class Bill
{
private:
    int bill_id;
    double Amount;
    string Date;
    string method;
    bool bill_status;

public:
    Bill()
    {
    }
    Bill(int id, double a, string date, string m, bool status)
    {
        bill_id = id;
        Amount = a;
        Date = date;
        method = m;
        bill_status = status;
    }
    void vb_status()
    {
        if (bill_status == 1)
        {
            cout << " Status: Paid" << endl;
        }
        else
        {
            cout << " Status: Unpaid" << endl;
        }
    }
    void print_bill()
    {
        cout << "========  Bill ========" << endl;
        cout << " Bill Id: " << bill_id << endl;
        cout << " Amount: " << Amount << endl;
        cout << " Date: " << Date << endl;
        cout << " Method: " << method << endl;
        if (bill_status == 1)
        {
            cout << " Status: Paid" << endl;
        }
        else
        {
            cout << " Status: Unpaid" << endl;
        }
    }
    void pay_bill()
    {
        if (bill_status == 1)
        {
            cout << "Bill Already Paid" << endl;
        }
        else
        {
            bill_status = 1;
            cout << "Bill Paid" << endl;
        }
    }
};
class Room
{
private:
    int room_id;
    string room_type;
    bool status;
    int floor_no;
    double price;
    int capacity;
    string features[3];

public:
    Reservations *res = NULL;
    Room()
    {
    }
    Room(int id, string type, bool st, int f_no, double pr, int cap, string fe[3])
    {
        room_id = id;
        room_type = type;
        status = st;
        floor_no = f_no;
        price = pr;
        capacity = cap;
        for (int i = 0; i < 3; i++)
        {
            features[i] = fe[i];
        }
    }
    void display()
    {
        cout << "=======================================" << endl;
        cout << "Room id: " << room_id << endl;
        cout << "Room type: " << room_type << endl;
        if (status == 0)
        {
            cout << "Room Status: Available" << endl;
        }
        else
        {
            cout << "Room Status: Not Available" << endl;
        }
        cout << "Floor no: " << floor_no << endl;
        cout << "Price: " << price << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Features: ";
        for (int i = 0; i < 3; i++)
        {
            cout << features[i] << " ";
        }
        cout << endl;
        cout << "=======================================" << endl;
    }
    void add_room(Room *room, int size, fstream &add_stream)
    {
        int Choice;
        for (int i = 0; i < size; i++)
        {
            cout << "Enter room id: ";
            cin >> room_id;
            cout << "Enter room type:(1:Luxury,2:Deluxe,3:Economy) ";
            cin >> Choice;
            if (Choice == 1)
            {
                room_type = "Luxury";
            }
            else if (Choice == 2)
            {
                room_type = "Deluxe";
            }
            else if (Choice == 3)
            {
                room_type = "Economy";
            }
            cout << "Enter status: (1 for Available,0 for Unavailable):";
            cin >> status;
            cout << "Enter floor no: ";
            cin >> floor_no;
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter capacity: ";
            cin >> capacity;
            cout << "Enter features:(3 Features Words ) " << endl;
            for (int j = 0; j < 3; j++)
            {
                cin >> features[j];
            }
            room[i] = Room(room_id, room_type, status, floor_no, price, capacity, features);
        }
        add_stream.open("book.txt", ios::app | ios::out);
        for (int i = 0; i < size; i++)
        {
            add_stream << room[i].room_id << " " << room[i].room_type << " " << room[i].status << " " << room[i].floor_no << " " << room[i].price << " " << room[i].capacity << " " << room[i].features[0] << " " << room[i].features[1] << " " << room[i].features[2] << endl;
        }
        add_stream.close();
        delete[] room;
    }
    void lenghtcount(fstream &add_stream)
    {
        string word;
        add_stream.open("book.txt", ios::in);
        while (true)
        {
            getline(add_stream, word);
            if (add_stream.eof())
                break;
            filelength++;
        }
        add_stream.close();
    }
    void view_room(fstream &add_stream)
    {
        lenghtcount(add_stream);
        Room *room = new Room[filelength];
        add_stream.open("book.txt", ios::app | ios::in);
        for (int i = 0; i < filelength; i++)
        {
            add_stream >> room[i].room_id >> room[i].room_type >> room[i].status >> room[i].floor_no >> room[i].price >> room[i].capacity >> room[i].features[0] >> room[i].features[1] >> room[i].features[2];
        }
        add_stream.close();
        for (int i = 0; i < filelength; i++)
        {
            room[i].display();
        }
        delete[] room;
    }
    void view_available(fstream &add_stream)
    {
        lenghtcount(add_stream);
        Room *room = new Room[filelength];
        add_stream.open("book.txt", ios::app | ios::in);
        for (int i = 0; i < filelength; i++)
        {
            add_stream >> room[i].room_id >> room[i].room_type >> room[i].status >> room[i].floor_no >> room[i].price >> room[i].capacity >> room[i].features[0] >> room[i].features[1] >> room[i].features[2];
        }
        add_stream.close();
        for (int i = 0; i < filelength; i++)
        {
            if (room[i].status == 0)
            {
                room[i].display();
            }
        }
        delete[] room;
    }
    void delete_room(fstream &add_stream)
    {
        filelength = 0;
        lenghtcount(add_stream);
        fstream temp_stream;
        int temp_id;
        cout << "room id  you want to delete: " << endl;
        cin >> temp_id;
        add_stream.open("book.txt", ios::app | ios::in);
        temp_stream.open("temp.txt", ios::app | ios::out);
        Room *room = new Room[filelength];
        cout << " filelenght is" << filelength << endl;
        for (int i = 0; i < filelength; i++)
        {
            add_stream >> room[i].room_id >> room[i].room_type >> room[i].status >> room[i].floor_no >> room[i].price >> room[i].capacity >> room[i].features[0] >> room[i].features[1] >> room[i].features[2];
        }
        for (int i = 0; i < filelength; i++)
        {
            if (room[i].room_id != temp_id)
            {
                temp_stream << room[i].room_id << " " << room[i].room_type << " " << room[i].status << " " << room[i].floor_no << " " << room[i].price << " " << room[i].capacity << " " << room[i].features[0] << " " << room[i].features[1] << " " << room[i].features[2] << endl;
            }
        }
        add_stream.close();
        temp_stream.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");
        cout << "Deleted successfully...Room id: " << temp_id << endl;
        delete[] room;
    }
    void update_room(fstream &add_stream)
    {
        filelength = 0;
        lenghtcount(add_stream);
        fstream temp_stream;
        int temp_id;
        cout << "room id  you want to update: " << endl;
        cin >> temp_id;
        add_stream.open("book.txt", ios::app | ios::in);
        temp_stream.open("temp.txt", ios::app | ios::out);
        Room *room = new Room[filelength];
        for (int i = 0; i < filelength; i++)
        {
            add_stream >> room[i].room_id >> room[i].room_type >> room[i].status >> room[i].floor_no >> room[i].price >> room[i].capacity >> room[i].features[0] >> room[i].features[1] >> room[i].features[2];
        }
        for (int i = 0; i < filelength; i++)
        {
            if (room[i].room_id != temp_id)
            {
                temp_stream << room[i].room_id << " " << room[i].room_type << " " << room[i].status << " " << room[i].floor_no << " " << room[i].price << " " << room[i].capacity << " " << room[i].features[0] << " " << room[i].features[1] << " " << room[i].features[2] << endl;
            }
            else
            {
                cout << "Enter room id: ";
                cin >> room[i].room_id;
                cout << "Enter room type: ";
                cin >> room[i].room_type;
                cout << "Enter status: (1,0):";
                cin >> room[i].status;
                cout << "Enter floor no: ";
                cin >> room[i].floor_no;
                cout << "Enter price: ";
                cin >> room[i].price;
                cout << "Enter capacity: ";
                cin >> room[i].capacity;
                cout << "Enter features: ";
                for (int j = 0; j < 3; j++)
                {
                    cin >> room[i].features[j];
                }
                temp_stream << room[i].room_id << " " << room[i].room_type << " " << room[i].status << " " << room[i].floor_no << " " << room[i].price << " " << room[i].capacity << " " << room[i].features[0] << " " << room[i].features[1] << " " << room[i].features[2] << endl;
            }
        }
        add_stream.close();
        temp_stream.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");
        cout << "updated successfully...Room id: " << temp_id << endl;
        delete[] room;
    }
    void update_room_status(int temp_id, fstream &add_stream)
    {
        filelength = 0;
        lenghtcount(add_stream);
        fstream temp_stream;
        add_stream.open("book.txt", ios::app | ios::in);
        temp_stream.open("temp.txt", ios::app | ios::out);
        Room *room = new Room[filelength];
        for (int i = 0; i < filelength; i++)
        {
            add_stream >> room[i].room_id >> room[i].room_type >> room[i].status >> room[i].floor_no >> room[i].price >> room[i].capacity >> room[i].features[0] >> room[i].features[1] >> room[i].features[2];
        }
        for (int i = 0; i < filelength; i++)
        {
            if (room[i].room_id != temp_id)
            {
                temp_stream << room[i].room_id << " " << room[i].room_type << " " << room[i].status << " " << room[i].floor_no << " " << room[i].price << " " << room[i].capacity << " " << room[i].features[0] << " " << room[i].features[1] << " " << room[i].features[2] << endl;
            }
            else
            {
                if (room[i].status == 0)
                {
                    room[i].status = 1;
                }
                else if (room[i].status == 1)
                {
                    room[i].status = 0;
                }
                temp_stream << room[i].room_id << " " << room[i].room_type << " " << room[i].status << " " << room[i].floor_no << " " << room[i].price << " " << room[i].capacity << " " << room[i].features[0] << " " << room[i].features[1] << " " << room[i].features[2] << endl;
            }
        }
        add_stream.close();
        temp_stream.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");
        cout << "updated successfully...Room id: " << temp_id << endl;
        delete[] room;
    }
    void book_room(fstream &add_stream, fstream &rev_stream)
    {
        filelength = 0;
        lenghtcount(add_stream);
        fstream temp_stream;
        int temp_id;
        cout << "Room id  you want to Book: " << endl;
        cin >> temp_id;
        add_stream.open("book.txt", ios::app | ios::in);
        temp_stream.open("temp.txt", ios::app | ios::out);
        Room *room = new Room[filelength];
        for (int i = 0; i < filelength; i++)
        {
            add_stream >> room[i].room_id >> room[i].room_type >> room[i].status >> room[i].floor_no >> room[i].price >> room[i].capacity >> room[i].features[0] >> room[i].features[1] >> room[i].features[2];
        }
        for (int i = 0; i < filelength; i++)
        {
            if (room[i].room_id != temp_id)
            {
                temp_stream << room[i].room_id << " " << room[i].room_type << " " << room[i].status << " " << room[i].floor_no << " " << room[i].price << " " << room[i].capacity << " " << room[i].features[0] << " " << room[i].features[1] << " " << room[i].features[2] << endl;
            }
            else if (room[i].room_id == temp_id && room[i].status == 0)
            {
                int rev_id;
                int guest_id;
                string g_name;
                string g_phone;
                string g_e;
                int bill_id;
                double bill_a;
                string method;
                string b_date;
                bool bill_s;
                int days;
                string reply;
                cout << "Ok! you want to book your room : Room Id : " << temp_id << "is Available" << endl;
                cout << "Please tell me for how many days you want to come as our guest" << endl;
                cin >> days;
                rev_id = room[i].room_id;
                guest_id = room[i].room_id;
                bill_id = room[i].room_id;
                bill_a = room[i].price * days;
                cout << "your bill is " << bill_a << endl;
                cout << "Do you want to pay the bill? (1 means yes,0 means no): ";
                cin >> bill_s;
                if (bill_s == 1)
                {
                    cout << "Enter your method of payment:(online/cash) ";
                    cin >> method;
                    cout << "Enter Your name: ";
                    cin >> g_name;
                    time_t currentTime = time(NULL);
                    string currentDate = ctime(&currentTime);
                    b_date = currentDate;
                    cout << "Enter Your phone: ";
                    cin >> g_phone;
                    cout << "Enter your email: ";
                    cin >> g_e;
                    rev_stream.open("Rev.txt", ios::app | ios::out);
                    rev_stream << rev_id << " " << guest_id << " " << g_name << " " << g_phone << " " << g_e << " " << bill_id << " " << bill_a << " "
                               << " " << method << " " << bill_s << " " << b_date;
                    rev_stream.close();
                    cout << "--------------         RECEIPt        --------------" << endl;
                    cout << "Thanks!" << g_name << endl;
                    cout << "You are our guest now!" << endl;
                    cout << "bill paid: " << bill_a << endl;
                    cout << "----------------------------------------------------" << endl;
                    room[i].status = 1;
                    temp_stream << room[i].room_id << " " << room[i].room_type << " " << room[i].status << " " << room[i].floor_no << " " << room[i].price << " " << room[i].capacity << " " << room[i].features[0] << " " << room[i].features[1] << " " << room[i].features[2] << endl;
                    cout << "Book successfully...Room id: " << temp_id << endl;
                }
                else
                {
                    cout << "You must pay bill first for this reservation" << endl;
                    temp_stream << room[i].room_id << " " << room[i].room_type << " " << room[i].status << " " << room[i].floor_no << " " << room[i].price << " " << room[i].capacity << " " << room[i].features[0] << " " << room[i].features[1] << " " << room[i].features[2] << endl;
                    update_room_status(room[i].room_id, add_stream);
                }
            }
        }
        add_stream.close();
        temp_stream.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");
        delete[] room;
    }
};
class Reservations
{
private:
    int Reservation_id;
    Guest *gptr;
    Bill *bptr;
    int id;

public:
    Reservations()
    {
    }
    Reservations(int id, Guest *g, Bill *b, int room_id)
    {
        this->Reservation_id = id;
        gptr = g;
        bptr = b;
        this->id = room_id;
    }
    void fetch_reservation(fstream &rev_stream, Reservations *rev)
    {
        lenghtcountR(rev_stream);
        gptr = new Guest[filelengthE];
        bptr = new Bill[filelengthE];
        int rev_id;
        int guest_id;
        string g_name;
        string g_phone;
        string g_e;
        int bill_id;
        double bill_a;
        string method;
        string b_date;
        bool bill_s;
        string day, month, date, time, yr;
        rev_stream.open("Rev.txt", ios::in);
        for (int i = 0; i < filelengthE; i++)
        {
            rev_stream >> rev_id >> guest_id >> g_name >> g_phone >> g_e >> bill_id >> bill_a >> method >> bill_s >> day >> month >> date >> time >> yr;
            b_date = day + " " + month + " " + date + " " + time + " " + yr;
            profit += bill_a;
            gptr[i] = Guest(guest_id, g_name, g_phone, g_e);
            bptr[i] = Bill(bill_id, bill_a, b_date, method, bill_s);
            rev[i] = Reservations(rev_id, &gptr[i], &bptr[i], guest_id);
        }
        rev_stream.close();
    }
    void lenghtcountR(fstream &rev_stream)
    {
        string word;
        filelengthE = 0;
        rev_stream.open("Rev.txt", ios::in);
        while (true)
        {
            getline(rev_stream, word);
            if (rev_stream.eof())
                break;
            filelengthE++;
        }
        rev_stream.close();
    }
    void view_specific_reservation(fstream &rev_stream)
    {
        lenghtcountR(rev_stream);
        string name;
        int id;
        cout << "Guest Name: " << endl;
        cin >> name;
        cout << "Reservation ID: " << endl;
        cin >> id;
        int rev_id;
        int guest_id;
        string g_name;
        string g_phone;
        string g_e;
        int bill_id;
        double bill_a;
        string method;
        string b_date;
        bool bill_s;
        string day, month, date, time, yr;
        rev_stream.open("Rev.txt", ios::in);
        for (int i = 0; i < filelengthE; i++)
        {
            rev_stream >> rev_id >> guest_id >> g_name >> g_phone >> g_e >> bill_id >> bill_a >> method >> bill_s >> day >> month >> date >> time >> yr;
            b_date = day + " " + month + " " + date + " " + time + " " + yr;
            if (name == g_name && id == rev_id)
            {
                cout << "Reservation ID: " << rev_id << endl;
                cout << "Guest ID:" << guest_id << endl;
                cout << "Guest Phone: " << g_phone << endl;
                cout << "Resrevation date: " << b_date << endl;
            }
        }
        rev_stream.close();
    }
    void view_total_bill(fstream &rev_stream)
    {
        filelength = 0;
        lenghtcountR(rev_stream);
        string name;
        string phone;
        double total = 0;
        cout << "Guest Name: " << endl;
        cin >> name;
        cout << "guest Phone: " << endl;
        cin >> phone;
        int rev_id;
        int guest_id;
        string g_name;
        string g_phone;
        string g_e;
        int bill_id;
        double bill_a;
        string method;
        string b_date;
        bool bill_s;
        string day, month, date, time, yr;
        rev_stream.open("Rev.txt", ios::in);
        for (int i = 0; i < filelengthE; i++)
        {
            rev_stream >> rev_id >> guest_id >> g_name >> g_phone >> g_e >> bill_id >> bill_a >> method >> bill_s >> day >> month >> date >> time >> yr;
            b_date = day + " " + month + " " + date + " " + time + " " + yr;
            if (name == g_name && phone == g_phone)
            {
                total += bill_a;
            }
        }
        rev_stream.close();
        cout << "============= Bill ========================" << endl;
        cout << " total bill " << total << endl;
        cout << "===========================================" << endl;
    }
    void update_reservations(fstream &rev_stream)
    {
        int rev_id;
        int guest_id;
        string g_name;
        string g_phone;
        string g_e;
        int bill_id;
        double bill_a;
        string method;
        string b_date;
        bool bill_s;
        string day, month, date, time, yr;
        fstream temp_stream;
        filelength = 0;
        lenghtcountR(rev_stream);
        int rep;
        cout << "Enter reservation id which you want to Update:" << endl;
        cin >> rep;
        rev_stream.open("Rev.txt", ios::in);
        temp_stream.open("temp.txt", ios::app | ios::out);
        for (int i = 0; i < filelengthE; i++)
        {
            rev_stream >> rev_id >> guest_id >> g_name >> g_phone >> g_e >> bill_id >> bill_a >> method >> bill_s >> day >> month >> date >> time >> yr;
            b_date = day + " " + month + " " + date + " " + time + " " + yr;
            if (rep != rev_id)
            {
                temp_stream << rev_id << " " << guest_id << " " << g_name << " " << g_phone << " " << g_e << " " << bill_id << " " << bill_a << " "
                            << " " << method << " " << bill_s << " " << b_date << endl;
            }
            else
            {
                cout << "Reservation Id " << endl;
                cin >> rev_id;
                cout << "Guest Id " << endl;
                cin >> guest_id;
                cout << "Guest Name " << endl;
                cin >> g_name;
                cout << "Guest Phone " << endl;
                cin >> g_phone;
                cout << "Guest Email " << endl;
                cin >> g_e;
                cout << "Bill Id " << endl;
                cin >> bill_id;
                cout << "Bill Amount " << endl;
                cin >> bill_a;
                cout << "Payment Method(cash/online) " << endl;
                cin >> method;
                cout << "Bill Status(1/0) " << endl;
                cin >> bill_s;
                temp_stream << rev_id << " " << guest_id << " " << g_name << " " << g_phone << " " << g_e << " " << bill_id << " " << bill_a << " "
                            << " " << method << " " << bill_s << " " << b_date << endl;
            }
        }
        rev_stream.close();
        temp_stream.close();
        remove("Rev.txt");
        rename("temp.txt", "Rev.txt");
    }
    void cancel_reservation(fstream &rev_stream, fstream &add_stream)
    {

        int rev_id;
        int guest_id;
        string g_name;
        string g_phone;
        string g_e;
        int bill_id;
        double bill_a;
        string method;
        string b_date;
        bool bill_s;
        string day, month, date, time, yr;
        fstream temp_stream;
        fstream remove_stream;
        lenghtcountR(rev_stream);
        int rep;
        cout << "Enter reservation id which you want to Cancel:" << endl;
        cin >> rep;
        rev_stream.open("Rev.txt", ios::in);
        temp_stream.open("temp.txt", ios::app | ios::out);
        for (int i = 0; i < filelengthE; i++)
        {
            rev_stream >> rev_id >> guest_id >> g_name >> g_phone >> g_e >> bill_id >> bill_a >> method >> bill_s >> day >> month >> date >> time >> yr;
            b_date = day + " " + month + " " + date + " " + time + " " + yr;
            if (rep == rev_id)
            {
                remove_stream.open("removedrev.txt", ios::app | ios::out);
                cout << "Reservation is canceld Reservation: " << rep << endl;
                remove_stream << rev_id << " " << guest_id << " " << g_name << " " << g_phone << " " << g_e << " " << bill_id << " " << bill_a << " "
                              << " " << method << " " << bill_s << " " << b_date << endl;
                Room *a;
                a->update_room_status(rev_id, add_stream);
                remove_stream.close();
            }
            else
            {
                temp_stream << rev_id << " " << guest_id << " " << g_name << " " << g_phone << " " << g_e << " " << bill_id << " " << bill_a << " "
                            << " " << method << " " << bill_s << " " << b_date << endl;
            }
        }
        rev_stream.close();
        temp_stream.close();
        remove("Rev.txt");
        rename("temp.txt", "Rev.txt");
    }
    void total_cost()
    {
    }
    void print_reservations(fstream &rev_stream, Reservations *rev)
    {
        filelength = 0;
        lenghtcountR(rev_stream);
        for (int i = 0; i < filelengthE; i++)
        {
            cout << "=================================" << endl;
            cout << "Reservation ID: " << rev[i].Reservation_id << endl;
            rev[i].gptr->print_guest();
            rev[i].bptr->print_bill();
            cout << endl;
            cout << "Room ID: " << rev[i].id;
            cout << endl;
            cout << "=================================" << endl;
        }
    }
};
class Employee
{
public:
    string E_name;
    int Employee_id;
    string position;
    double salary;
    int Manager_id;
    string password;
    Employee()
    {
    }
    Employee(string name, int id, string position, double salary, int manager_id, string pass)
    {
        E_name = name;
        Employee_id = id;
        this->position = position;
        this->salary = salary;
        this->Manager_id = manager_id;
        this->password = pass;
    }
    void set_Employee(string name)
    {
        E_name = name;
    }
    void set_Employee_id(int id)
    {
        Employee_id = id;
    }
    void set_position(string position)
    {
        this->position = position;
    }
    void set_salary(double salary)
    {
        this->salary = salary;
    }
    void set_Manager_id(int manager_id)
    {
        this->Manager_id = manager_id;
    }
    void set_password(string pass)
    {
        this->password = pass;
    }
    void add_employee(fstream &employee_stream)
    {

        int id;
        string name;
        string position;
        double salary;
        int manager_id;
        string password;
        employee_stream.open("Employee.txt", ios::app | ios::out);
        cout << "Enter Employee Name: " << endl;
        cin >> name;
        cout << "Enter Employee ID: " << endl;
        cin >> id;
        cout << "Enter Employee Position: " << endl;
        cin >> position;
        cout << "Enter Employee Salary: " << endl;
        cin >> salary;
        cout << "Enter Employee Manager ID: " << endl;
        cin >> manager_id;
        cout << "Enter Employee Password: " << endl;
        cin >> password;
        employee_stream << name << " " << id << " " << position << " " << salary << " " << manager_id << " " << password << endl;
        employee_stream.close();
    }
    void update_employee(fstream &employee_stream)
    {
        string E_n;
        int Empl_id;
        string posi;
        double sa;
        int Man_id;
        string pass;
        fstream temp_employee_stream;
        string up_employee, employee_posi;

        cout << "enter Employee Name: " << endl;
        cin >> up_employee;
        cout << "Enter Employee Position: " << endl;
        cin >> employee_posi;
        employee_stream.open("Employee.txt", ios::in);
        temp_employee_stream.open("temp.txt", ios::app | ios::out);
        while (employee_stream >> E_n >> Empl_id >> posi >> sa >> Man_id >> pass)
        {
            if (up_employee == E_n && employee_posi == posi)
            {
                cout << "Enter Employee Name: " << endl;
                cin >> E_n;
                cout << "Enter Employee ID: " << endl;
                cin >> Empl_id;
                cout << "Enter Employee Position: " << endl;
                cin >> posi;
                cout << "Enter Employee Salary: " << endl;
                cin >> sa;
                cout << "Enter Employee Manager ID: " << endl;
                cin >> Man_id;
                cout << "Enter Employee Password: " << endl;
                cin >> password;
                temp_employee_stream << E_n << " " << Empl_id << " " << posi << " " << sa << " " << Man_id << " " << password << endl;
            }
            else
            {
                temp_employee_stream << E_n << " " << Empl_id << " " << posi << " " << sa << " " << Man_id << " " << password << endl;
            }
        }
        temp_employee_stream.close();
        employee_stream.close();
        remove("temp_employee_stream");
        rename("temp_employ_stream", "Employee");
    }

    void print_employee()
    {
        cout << "==================================" << endl;
        cout << "Employee Name: " << E_name << endl;
        cout << "Employee ID: " << Employee_id << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
        cout << "Manager ID: " << Manager_id << endl;
        cout << "Password: " << password << endl;
        cout << "=================================" << endl;
    }
    void checkinGuest(fstream &stream)
    {
        time_t currentTime = time(NULL);
        string currentDate = ctime(&currentTime);
        string checkin;
        int id;
        string way;
        int RoomId;
        cout << "Room Id: " << endl;
        cin >> RoomId;
        cout << "Enter guestid: " << endl;
        cin >> id;
        way = "IN";
        checkin = currentDate;
        stream.open("DatesGuest.txt", ios::app | ios::out);
        stream << RoomId << " " << id << " " << way << " " << checkin;
        stream.close();
    }
    void checkoutGuest(fstream &stream)
    {
        time_t currentTime = time(NULL);
        string currentDate = ctime(&currentTime);
        string checkout;
        int id;
        int RoomId;
        string way;
        cout << "Room Id: " << endl;
        cin >> RoomId;
        cout << "Enter guestid: " << endl;
        cin >> id;
        way = "OUT";
        checkout = currentDate;
        stream.open("DatesGuest.txt", ios::app | ios::out);
        stream << RoomId << " " << id << " " << way << " " << checkout;
        stream.close();
    }
    void view_dates(fstream &stream)
    {
        cout << "===========  customer getin or getout dates   ===========" << endl;
        int RoomId, id;
        string way, day, month, date, time, yr;
        stream.open("DatesGuest.txt", ios::app | ios::in);
        while (stream >> RoomId >> id >> way >> day >> month >> date >> time >> yr)
        {
            string b_date = day + " " + month + " " + date + " " + time + " " + yr;
            cout << "================================================" << endl;
            cout << "b_date: " << b_date << endl;
            cout << "Guest: " << way << endl;
            cout << "Guest ID: " << id << endl;
            cout << "room_id: " << RoomId << endl;
            cout << "reservation: " << id << endl;
            cout << "================================================" << endl;
        }
        cout << "================================================================" << endl;
        stream.close();
    }
    void manage_reservations(fstream &stream, fstream &add_stream)
    {

        Reservations *a;
        filelength = 0;
        a->lenghtcountR(stream);
        Reservations *b = new Reservations[filelength];
        a->fetch_reservation(stream, b);
        cout << "============   Reservations   ============" << endl;
        a->print_reservations(stream, b);
        int choice;
        cout << "1:Update Reservation" << endl;
        cout << "2:cancel Reservation" << endl;
        cin >> choice;
        if (choice == 1)
        {
            a->update_reservations(stream);
        }
        else if (choice == 2)
        {
            a->cancel_reservation(stream, add_stream);
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
        delete a;
        delete[] b;
    }
    void lenghtcountE(fstream &stream)
    {
        string word;
        filelength = 0;
        stream.open("Employee.txt", ios::in);
        while (true)
        {
            getline(stream, word);
            if (stream.eof())
                break;
            filelength++;
        }
        stream.close();
    }
    void fetch_out(fstream &stream)
    {
        string E_n;
        int Empl_id;
        string posi;
        double sa;
        int Man_id;
        string pass;
        lenghtcountE(stream);
        Employee *fetch_out = new Employee[filelength];
        stream.open("Employee.txt", ios::in);
        for (int i = 0; i < filelength; i++)
        {
            stream >> E_n >> Empl_id >> posi >> sa >> Man_id >> pass;
            fetch_out[i] = Employee(E_n, Empl_id, posi, sa, Man_id, pass);
            fetch_out[i].print_employee();
        }
    }
};
class Receptionist : public Employee
{
public:
    string Shift;
    Receptionist()
    {
    }
    Receptionist(string name, int id, string position, double salary, int manager_id, string pass, string shift)
    {
        E_name = name;
        Employee_id = id;
        this->position = position;
        this->salary = salary;
        this->Manager_id = manager_id;
        this->password = pass;
        this->Shift = shift;
    }
    void view_Receptionist()
    {
        cout << "==================================" << endl;
        cout << "Employee Name: " << E_name << endl;
        cout << "Employee ID: " << Employee_id << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
        cout << "Manager ID: " << Manager_id << endl;
        cout << "Password: " << password << endl;
        cout << "Shift: " << Shift << endl;
        cout << "=================================" << endl;
    }
    void shift_Receptionist(fstream &stream)
    {
        string E_n;
        int Empl_id;
        string posi;
        double sa;
        int Man_id;
        string pass;
        string shift_A;
        bool s = true; // for shift assignings
        lenghtcountE(stream);
        int count = 0;
        Receptionist *fetch_out = new Receptionist[20];
        stream.open("Employee.txt", ios::in);
        for (int i = 0; i < filelength; i++)
        {
            stream >> E_n >> Empl_id >> posi >> sa >> Man_id >> pass;
            if (posi == "Receptionist")
            {
                if (s = true)
                {
                    shift_A = "Nigth";
                    s = false;
                }
                else
                {
                    shift_A = "Day";
                    s = true;
                }
                fetch_out[count++] = Receptionist(E_n, Empl_id, posi, sa, Man_id, pass, shift_A);
            }
        }
        for (int i = 0; i < count; i++)
        {
            fetch_out[i].view_Receptionist();
        }
        stream.close();
    }

    void handle_checkin(fstream &stream)
    {
        checkinGuest(stream);
    }
    void handle_checkout(fstream &stream)
    {
        checkoutGuest(stream);
    }
};
class HouseKeeping : public Employee
{
public:
    Room *Checkroom = NULL;
    bool clean;
    HouseKeeping()
    {
    }
    HouseKeeping(string name, int id, string position, double salary, int manager_id, string pass)
    {
        E_name = name;
        Employee_id = id;
        this->position = position;
        this->salary = salary;
        this->Manager_id = manager_id;
        this->password = pass;
    }
};
class Maintainance : public Employee
{
public:
    Maintainance()
    {
    }
    Maintainance(string name, int id, string position, double salary, int manager_id, string pass)
    {
        E_name = name;
        Employee_id = id;
        this->position = position;
        this->salary = salary;
        this->Manager_id = manager_id;
        this->password = pass;
    }
};

class Manager : public Employee
{
public:
    Employee *employee = NULL;
    string task;
    Manager()
    {
    }
    Manager(string name, int id, string position, double salary, int manager_id, string pass)
    {
        E_name = name;
        Employee_id = id;
        this->position = position;
        this->salary = salary;
        this->Manager_id = manager_id;
        this->password = pass;
    }

    void view_Manager()
    {
        cout << "==================================" << endl;
        cout << "Manager Name: " << E_name << endl;
        cout << "Employee ID: " << Employee_id << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
        cout << "Manager ID: " << Manager_id << endl;
        cout << "Password: " << password << endl;
        cout << "=================================" << endl;
    }
    void assigntasks(fstream &stream, fstream &Tstream)
    {
        string E_n;
        int Empl_id;
        cout << "in assigntasks" << endl;
        string posi;
        double sa;
        int Man_id;
        string pass;
        lenghtcountE(stream);
        stream.open("Employee.txt", ios::app | ios::in);
        Tstream.open("task.txt", ios::app | ios::out);
        for (int i = 0; i < filelength; i++)
        {
            stream >> E_n >> Empl_id >> posi >> sa >> Man_id >> pass;
            cout << "Employee Name" << E_n << endl;
            string task;
            cin >> task;
            cout << task << endl;
            Tstream << E_n << " " << task << endl;
        }
        stream.close();
        Tstream.close();
    }
    void updateTask(fstream &Tstream)
    {
        fstream TeampFile;
        TeampFile.open("temp.txt", ios::app | ios::out);
        Tstream.open("task.txt", ios::app | ios::in);
        string TaskName;
        string E_NAME;
        string t, e;
        cout << "Enter Task Name: " << endl;
        cin >> TaskName;
        cout << "ENter Employee Name: " << endl;
        cin >> E_NAME;
        while (Tstream >> e >> t)
        {
            if (TaskName == t && E_NAME == e)
            {
                cout << "Enter Task Name: " << endl;
                cin >> t;
                cout << "ENter Employee Name: " << endl;
                cin >> e;
                TeampFile << e << " " << t << endl;
            }
            else
            {
                TeampFile << e << " " << t << endl;
            }
        }
        TeampFile.close();
        Tstream.close();
    }
    void view_tasks(fstream &Tstream)
    {

        string E_n;
        string task;
        Tstream.open("task.txt", ios::app | ios::in);
        while (Tstream >> E_n >> task)
        {
            cout << "Employee Name: " << E_n << endl;
            cout << "Task: " << task << endl;
        }
        Tstream.close();
    }
};
int main()
{
    fstream add_stream /*rooms*/, rev_stream /*reservation*/, checkin_stream /*dates*/, employee_stream /*employees*/, login_stream /*login for guest */,
        task_stream /*employees task*/;

    header();
    loading();
    system("CLS");
    header();
    int choice;
    const int rev_size = 100;
    Reservations *rev = new Reservations[rev_size];
    Room *room = NULL;
    while (true)
    {
    p:
        system("CLS");
        header();
        cout << "protal" << endl;
        cout << "1: Admin " << endl;
        cout << "2: Guest" << endl;
        cout << "3: Employee" << endl;
        cout << "4: Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            login_Emplyee(employee_stream);
            if (employee_login == true)
            {
            A:
                system("CLS");
                header();

                cout << "1: View All Rooms" << endl;
                cout << "2: Add rooms" << endl;
                cout << "3: Delete rooms" << endl;
                cout << "4: Update rooms" << endl;
                cout << "5: View Reservations History " << endl;
                cout << "6: Update reservation" << endl;
                cout << "7: Delete reservation" << endl;
                cout << "8: Manage resrevation" << endl;
                cout << "9: Add Employee" << endl;
                cout << "10: Update Employee " << endl;
                cout << "11: Delete Employee" << endl;
                cout << "12: View Employees" << endl;
                cout << "13: mark checkin guest" << endl;
                cout << "14: mark checkout guest" << endl;
                cout << "15: view checkin or check out dates" << endl;
                cout << "16:Renevue" << endl;
                cout << "17: Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    room = new Room();
                    room->view_room(add_stream);
                    system("PAUSE");
                    goto A;
                    break;
                }
                case 2:
                {
                    int size;
                    cout << "How many room you want to add?" << endl;
                    cin >> size;
                    room = new Room[size];
                    room->add_room(room, size, add_stream);
                    system("PAUSE");
                    goto A;
                    break;
                }
                case 3:
                {
                    Room *a;
                    a->delete_room(add_stream);
                    system("PAUSE");
                    goto A;
                    break;
                }
                case 4:
                {
                    Room *a;
                    a->update_room(add_stream);
                    system("PAUSE");
                    goto A;
                    break;
                }
                case 5:
                {
                    Reservations *r;
                    r->fetch_reservation(rev_stream, rev);
                    r->print_reservations(rev_stream, rev);
                    system("PAUSE");
                    goto A;
                    break;
                }
                case 6:
                {
                    Reservations *c;
                    c->update_reservations(rev_stream);
                    system("PAUSE");
                    goto A;
                    break;
                }
                case 7:
                {
                    Reservations *c;
                    c->cancel_reservation(rev_stream, add_stream);
                    system("PAUSE");
                    goto A;
                    break;
                }
                case 8:
                {
                    Employee *e;
                    e->manage_reservations(rev_stream, add_stream);
                    system("PAUSE");
                    goto A;
                    delete e;
                }
                case 9:
                {
                    Employee *e;
                    e->add_employee(employee_stream);
                    system("PAUSE");
                    delete e;
                    goto A;
                    break;
                }
                case 10:
                    Employee *e;
                    e->update_employee(employee_stream);
                    system("PAUSE");
                    delete e;
                    goto A;
                    break;
                case 12:
                {
                    Employee *e;
                    e->fetch_out(employee_stream);
                    system("PAUSE");
                    delete e;
                    goto A;
                    break;
                }
                case 13:
                {
                    Employee *ein;
                    ein->checkinGuest(checkin_stream);
                    system("PAUSE");
                    delete ein;
                    goto A;
                    break;
                }
                case 14:
                {
                    Employee *eout;
                    eout->checkoutGuest(checkin_stream);
                    system("PAUSE");
                    delete eout;
                    goto A;
                    break;
                }
                case 15:
                {
                    Employee *ev;
                    ev->view_dates(checkin_stream);
                    system("PAUSE");
                    delete ev;
                    goto A;
                    break;
                }
                case 16:
                {
                    Reservations *c;
                    c->fetch_reservation(rev_stream, rev);
                    cout << "profit: " << profit << endl;
                    system("PAUSE");
                    goto A;
                }
                default:
                    cout << "wrong biee" << endl;
                    system("PAUSE");
                    goto A;
                }
            }
            else
            {
                cout << "wrong password" << endl;
                cout << "try again" << endl;
                system("PAUSE");
                goto p;
            }
            break;
        }
        case 2:
        {
            int login_choice; // login choice
            system("CLS");
            header();
            cout << "1:Registor" << endl;
            cout << "2:Login" << endl;
            cout << "Enter your choice: ";
            cin >> login_choice;
            login_system_guest(login_choice, login_stream);
            if (Guest_login == true)
            {
            G:
                system("CLS");
                header();
                cout << "1: view available rooms" << endl;
                cout << "2: book room" << endl;
                cout << "3: cancel room" << endl;
                cout << "4: View your room" << endl;
                cout << "5: call for Service" << endl;
                cout << "6: feedback " << endl;
                cout << "7: View total Bill" << endl;
                cout << "8: exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    Room *a;
                    a->view_room(add_stream);
                    system("PAUSE");
                    goto G;
                    break;
                }
                case 2:
                {
                    Room *a;
                    a->view_available(add_stream);
                    a->book_room(add_stream, rev_stream);
                    system("PAUSE");
                    goto G;
                    break;
                }
                case 3:
                {
                    cout << G_R << endl;
                    string meassage = "";
                    cin.ignore();
                    getline(cin, meassage);
                    G_R = "GUEST: " + meassage;
                    system("PAUSE");
                    goto G;
                    break;
                }
                case 4:
                {
                    Reservations *c;
                    c->view_specific_reservation(rev_stream);
                    system("PAUSE");
                    goto G;
                    break;
                }
                case 5:
                {
                    cout << G_R << endl;
                    string meassage = "";
                    cin.ignore();
                    getline(cin, meassage);
                    G_R = "GUEST: " + meassage;
                    system("PAUSE");
                    goto G;
                }

                case 6:
                {
                    cout << G_R << endl;
                    string meassage = "";
                    cin.ignore();
                    getline(cin, meassage);
                    G_R = "GUEST: " + meassage;
                    system("PAUSE");
                    goto G;
                    break;
                }
                case 7:
                {
                    Reservations *c;
                    c->view_total_bill(rev_stream);
                    system("PAUSE");
                    goto G;
                    break;
                }
                }
            }
            else
            {
                cout << "Not found!!" << endl;
                cout << "try again" << endl;
                system("PAUSE");
                goto G;
                break;
            }
            break;
        }
        case 3:
        {
            login_Emplyee(employee_stream);
            if (employee_login == true)
            {
                int e_choice;
                system("CLS");
                header();
                cout << "1:Receptionist" << endl;
                cout << "2:Manager" << endl;
                cout << "3:Maintainace" << endl;
                cout << "4:Housekeeping" << endl;
                cout << "5:Exit" << endl;
                cin >> e_choice;
                switch (e_choice)
                {
                case 1:
                {
                E:
                    system("CLS");
                    header();
                    int choice;
                    cout << "1: view available rooms" << endl;
                    cout << "2: book room" << endl;
                    cout << "3: View Reservations History " << endl;
                    cout << "4: Update reservation" << endl;
                    cout << "5: Delete reservation" << endl;
                    cout << "6: mark checkin guest" << endl;
                    cout << "7: Manage resrevation" << endl;
                    cout << "8: Call houskeeping" << endl;
                    cout << "9: mark checkout guest" << endl;
                    cout << "10: call to Workers" << endl;
                    cout << "11: view checkin or check out dates" << endl;
                    cout << "12: view all messages and Reply" << endl;
                    cout << "13:exit" << endl;
                    cin >> choice;
                    if (choice == 1)
                    {
                        Room *a;
                        a->view_available(add_stream);
                        system("PAUSE");
                        goto E;
                    }
                    else if (choice == 2)
                    {
                        Room *a;
                        a->view_available(add_stream);
                        a->book_room(add_stream, rev_stream);
                        system("PAUSE");
                        goto E;
                    }
                    else if (choice == 3)
                    {
                        Reservations *c;
                        c->fetch_reservation(rev_stream, rev);
                        c->print_reservations(rev_stream, rev);
                        system("PAUSE");
                        goto E;
                    }
                    else if (choice == 4)
                    {
                        Reservations *c;
                        c->update_reservations(rev_stream);
                        system("PAUSE");
                        goto E;
                    }
                    else if (choice == 5)
                    {
                        Reservations *c;
                        c->cancel_reservation(rev_stream, add_stream);
                        system("PAUSE");
                        goto E;
                    }
                    else if (choice == 6)
                    {
                        Employee *e;
                        e->checkinGuest(checkin_stream);
                        system("PAUSE");
                        goto E;
                    }
                    else if (choice == 7)
                    {
                        Employee *e;
                        e->manage_reservations(rev_stream, add_stream);
                        system("PAUSE");
                        goto E;
                    }
                    else if (choice == 8)
                    {
                        cout << R_E << endl;
                        string meassage = "";
                        cin.ignore();
                        getline(cin, meassage);
                        R_E = "RECEp: " + meassage;
                        system("PAUSE");
                        goto E;
                    }
                    else if (choice == 9)
                    {
                        Employee *e;
                        e->checkoutGuest(checkin_stream);
                        system("PAUSE");
                        goto E;
                    }
                    else if (choice == 10)
                    {
                        cout << R_E << endl;
                        string meassage = "";
                        cin.ignore();
                        getline(cin, meassage);
                        R_E = "RECEp: " + meassage;
                        system("PAUSE");
                        goto E;
                    }
                    else if (choice == 11)
                    {
                        Employee *ev;
                        ev->view_dates(checkin_stream);
                        system("PAUSE");
                        goto E;
                    }
                    else if (choice == 12)
                    {
                        cout << G_R << endl;
                        cout << R_E << endl;
                        string meassage = "";
                        cin.ignore();
                        getline(cin, meassage);
                        R_E = "RECEp: " + meassage;
                        system("PAUSE");
                        goto E;
                    }
                    else if (choice == 13)
                    {
                        system("PAUSE");
                        goto p;
                    }
                }
                case 2:
                {

                    Manager m("Manager", 123, "Manager", 25000, 123, "Manager@123");
                // m.print_employee();
                M:
                    system("CLS");
                    header();
                    cout << "1:assign task" << endl;
                    cout << "2:update task" << endl;
                    cout << "3:view task" << endl;
                    cout << "4:exit" << endl;
                    int choice;
                    cin >> choice;
                    if (choice == 1)
                    {
                        m.assigntasks(employee_stream, task_stream);
                        m.view_tasks(task_stream);
                        system("PAUSE");
                        goto M;
                    }
                    else if (choice == 2)
                    {
                        m.updateTask(task_stream);
                        m.view_tasks(task_stream);
                        system("PAUSE");
                        goto M;
                    }
                    else if (choice == 3)
                    {
                        m.view_tasks(task_stream);
                        system("PAUSE");
                        goto M;
                    }
                    else if (choice == 4)
                    {
                        goto p;
                        break;
                    }
                    break;
                }
                case 3:
                {
                    Maintainance Maintain("Cleaner", 1, "Maintainance", 20000, 1, "1234");
                    //                    Maintain.print_employee();
                    system("CLS");
                    header();
                    cout << "Assist Portal" << endl;
                    cout << R_E << endl;
                    cout << "write meassage" << endl;
                    cin.ignore();
                    string message = "";
                    getline(cin, message);
                    R_E = message;
                }
                break;
                case 4:
                {
                    HouseKeeping HouseKeep("Raja", 1, "HouseKeeping", 20000, 1, "1234");
                    //                    HouseKeep.print_employee();

                    cout << "Assist portal" << endl;
                    cout << "Assist Portal" << endl;
                    cout << R_E << endl;
                    cout << "write meassage" << endl;
                    cin.ignore();
                    string message = "";
                    getline(cin, message);
                    R_E = message;
                    system("PAUSE");
                    break;
                }
                }
            }
            else
            {
                cout << "wrong Employee" << endl;
                cout << "try again" << endl;
                system("PAUSE");
            }
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
            break;
        }
    }
    return 0;
}
