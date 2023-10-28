#include <iostream>
// #include<string.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <fstream>>
#include <vector>
#include <string>

#define max 100
using namespace std;

// Class Customer
class Customer
{
public:
    string name;
    string address;
    string phone;
    int total_days;
    string from_date;
    string to_date;
    float total_Rent;
    float payment_advance;
    float remaining_payment;
    int booking_id;
};

class Room
{
public:
    int comfort_type; // 1 for full furnished and 0 for semi furnished
    int stype;        // 1 for 2 person and 0 for single person
    int ac;           // 1 for ac and 0 for non ac
    int roomNumber;
    int rent;
    int status;
    Customer cust;
};
void save_data_fie(Room rooms[max])
{
    ofstream fout;
    fout.open("record.txt");

    while (fout)
    {
        for (int i = 0; i < max; i++)
        {
            if (rooms[i].status == 1)
            {
                fout << "room_id=" << i << endl;
                fout << rooms[i].cust.name << endl;
                fout << rooms[i].cust.address << endl;
                fout << rooms[i].cust.booking_id << endl;
                fout << rooms[i].cust.phone << endl;
                fout << rooms[i].cust.total_Rent << endl;
                fout << rooms[i].cust.total_days << endl;
                fout << rooms[i].cust.from_date << endl;
                fout << rooms[i].cust.to_date << endl;
                fout << rooms[i].cust.payment_advance << endl;
                fout << rooms[i].cust.remaining_payment << endl;
                fout << "\n";
            }
        }
        fout.close();
    }
}
void get_file_data(Room rooms[max])
{
    int c = 0;
    string x;
    vector<string> vec[max];
    ifstream in;
    in.open("record.txt");
    if (!in)
    {
        cout << "Cannot Open File. Or File Not Find\n";
    }
    char str[1000];

    while (in)
    {
        in.getline(str, 1000);
        if (in)
        {
            if (str[0] == 'r')
                c++;
            vec[c].push_back(str);
        }
    }
    in.close();

    for (int i = 1; i <= c; i++)
    {

        string room_no = vec[i][0];

        // char room_no[10] = vec[i][0];
        char r[10];
        for (int j = 8, k = 0; room_no[j] != NULL; j++)
        {
            // r[k]=room_no[j]-48;
            r[k++] = room_no[j];
        }

        int room_id = atoi(r);
        cout << room_id;
        char book_id[10];
        for (int j = 0; vec[i][3][j] != NULL; j++)
        {
            book_id[j] = vec[i][3][j];
        }
        int b_i = atoi(book_id);
        char t_r[10];
        for (int j = 0; vec[i][5][j] != NULL; j++)
        {
            t_r[j] = vec[i][5][j];
        }
        float tt_r = atof(t_r);
        char a_p[10];
        for (int j = 0; vec[i][9][j] != NULL; j++)
        {
            a_p[j] = vec[i][9][j];
        }
        float aa_p = atof(a_p);
        char p_r[10];
        for (int j = 0; vec[i][10][j] != NULL; j++)
        {
            p_r[j] = vec[i][10][j];
        }
        float pp_r = atoi(p_r);
        char t_dd[10];
        for (int j = 0; vec[i][6][j] != NULL; j++)
        {
            t_dd[j] = vec[i][6][j];
        }
        int tt_dd = atoi(t_dd);
        rooms[room_id].status = 1;
        rooms[room_id].cust.name = vec[i][1];
        rooms[room_id].cust.address = vec[i][2];
        rooms[room_id].cust.booking_id = b_i;
        rooms[room_id].cust.phone = vec[i][4];
        rooms[room_id].cust.total_Rent = tt_r;
        rooms[room_id].cust.total_days = tt_dd;
        rooms[room_id].cust.from_date = vec[i][7];
        rooms[room_id].cust.to_date = vec[i][8];
        rooms[room_id].cust.payment_advance = aa_p;
        rooms[room_id].cust.remaining_payment = pp_r;
    }
}
int r_id = 1000;
void display_customer_details(Room rooms[max], int room_id)
{
    cout << "\n\nCustomer Booking id is = " << rooms[room_id].cust.booking_id;
    cout << "\nRoom number = " << room_id;
    cout << "\nCustomer Name= " << rooms[room_id].cust.name;
    cout << "\nCustomer Address= " << rooms[room_id].cust.address;
    cout << "\nCustomer's Phone number= " << rooms[room_id].cust.phone;
    cout << "\nRoom Check-in Date= " << rooms[room_id].cust.from_date;
    cout << "\nRoom Check-out Date= " << rooms[room_id].cust.to_date;
    cout << "\nTotal Rent= " << rooms[room_id].cust.total_Rent;
    cout << "\nAdvance payment Done = " << rooms[room_id].cust.payment_advance;
    cout << "\nRemaining Payment = " << rooms[room_id].cust.remaining_payment;
}
void define_room_types(Room rooms[max])
{
    int c = 1;
    for (int i = 0; i < 100; i++)
    {
        if (i < 20)
        {
            rooms[i].ac = 1;
            rooms[i].comfort_type = 1;
            rooms[i].stype = 1;
            rooms[i].rent = 5000;
            rooms[i].status = 0;
        }
        else if (i < 30)
        {
            rooms[i].ac = 1;
            rooms[i].comfort_type = 1;
            rooms[i].stype = 0;
            rooms[i].rent = 4500;
            rooms[i].status = 0;
            rooms[i].roomNumber = c;
            c++;
        }
        else if (i < 40)
        {
            rooms[i].ac = 1;
            rooms[i].comfort_type = 0;
            rooms[i].stype = 1;
            rooms[i].rent = 4000;
            rooms[i].status = 0;
            rooms[i].roomNumber = c;
            c++;
        }
        else if (i < 50)
        {
            rooms[i].ac = 1;
            rooms[i].comfort_type = 0;
            rooms[i].stype = 0;
            rooms[i].rent = 3800;
            rooms[i].status = 0;
            rooms[i].roomNumber = c;
            c++;
        }
        else if (i < 60)
        {
            rooms[i].ac = 0;
            rooms[i].comfort_type = 1;
            rooms[i].stype = 1;
            rooms[i].rent = 3500;
            rooms[i].status = 0;
            rooms[i].roomNumber = c;
            c++;
        }
        else if (i < 70)
        {
            rooms[i].ac = 0;
            rooms[i].comfort_type = 1;
            rooms[i].stype = 0;
            rooms[i].rent = 3200;
            rooms[i].status = 0;
            rooms[i].roomNumber = c;
            c++;
        }
        else if (i < 80)
        {
            rooms[i].ac = 0;
            rooms[i].comfort_type = 0;
            rooms[i].stype = 1;
            rooms[i].rent = 3000;
            rooms[i].status = 0;
            rooms[i].roomNumber = c;
            c++;
        }
        else if (i < 100)
        {
            rooms[i].ac = 0;
            rooms[i].comfort_type = 0;
            rooms[i].stype = 0;
            rooms[i].rent = 2500;
            rooms[i].status = 0;
            rooms[i].roomNumber = c;
            c++;
        }
    }
}
bool check_payment_advance(float price, float ad_pay_price)
{
    float per_fifty = (50 * price) / 100;
    if (per_fifty > ad_pay_price)
        return false;
    else
        return true;
}
void available_rooms(Room rooms[max])
{
    int aft = 0;
    int afs = 0;
    int ast = 0;
    int ass = 0;
    int nft = 0;
    int nfs = 0;
    int nst = 0;
    int nss = 0;
    for (int i = 0; i < max; i++)
    {
        if (rooms[i].status == 0)
        {
            if (rooms[i].ac == 1 && rooms[i].comfort_type == 1 && rooms[i].stype == 1)
            {
                aft++;
            }
            else if (rooms[i].ac == 1 && rooms[i].comfort_type == 1 && rooms[i].stype == 0)
            {
                afs++;
            }
            else if (rooms[i].ac == 1 && rooms[i].comfort_type == 0 && rooms[i].stype == 1)
            {
                ast++;
            }
            else if (rooms[i].ac == 1 && rooms[i].comfort_type == 0 && rooms[i].stype == 0)
            {
                ass++;
            }
            else if (rooms[i].ac == 0 && rooms[i].comfort_type == 1 && rooms[i].stype == 1)
            {
                nft++;
            }
            else if (rooms[i].ac == 0 && rooms[i].comfort_type == 1 && rooms[i].stype == 0)
            {
                nfs++;
            }
            else if (rooms[i].ac == 0 && rooms[i].comfort_type == 0 && rooms[i].stype == 1)
            {
                nst++;
            }
            else if (rooms[i].ac == 0 && rooms[i].comfort_type == 0 && rooms[i].stype == 0)
            {
                nss++;
            }
        }
    }

    cout << "\n1.Full Furnished Ac Room for Two persons"
         << "\t\t"
         << "Available Rooms  =" << aft;
    cout << "\n2.Full Furnished Ac Room for Single persons"
         << "\t\t"
         << "Available Rooms  =" << afs;
    cout << "\n3.Semi Furnished Ac Room for Two persons"
         << "\t\t"
         << "Available Rooms  =" << ast;
    cout << "\n4.Semi Furnished Ac Room for Single persons"
         << "\t\t"
         << "Available Rooms  =" << ass;
    cout << "\n5.Full Furnished Non Ac Room for Two persons"
         << "\t\t"
         << "Available Rooms  =" << nft;
    cout << "\n6.Full Furnished Non Ac Room for Single persons"
         << "\t\t"
         << "Available Rooms  =" << nfs;
    cout << "\n7.Semi Furnished Non Ac Room for Two persons"
         << "\t\t"
         << "Available Rooms  =" << nst;
    cout << "\n8.Semi Furnished Non Ac Room for Single persons"
         << "\t\t"
         << "Available Rooms  =" << nss;
}
void check_out_room(Room rooms[max])
{
    int room_no, ans;
    cout << "\n\nEnter Room no = ";
    cin >> room_no;
    int room_id = room_no;
    if (rooms[room_id].status == 0)
    {
        cout << "\n\nRoom is already checked-out......";
        cout << "\nConfirm your room No and Try Again !!!";
    }
    else
    {
        cout << "\n\nRoom Details :";
        display_customer_details(rooms, room_id);
        cout << "\n\nYou have to pay Remaining payment of =" << rooms[room_id].cust.remaining_payment;
    abc:
        cout << "\nHave you done payment ?  ";
        cout << "\n1.yes";
        cout << "\n2.No";
        cout << "\nEnter = ";
        cin >> ans;
        switch (ans)
        {
        case 1:
            rooms[room_id].status = 0;
            cout << "\n\nThankyou For Visiting Hotel";
            cout << "\nHave a nice Day";
            break;
        case 2:
            cout << "\nPlease pay the payment first to check-out";
            goto abc;
            break;
        default:
            cout << "\nPlease Enter Valid Input";
            goto abc;
            break;
        }
    }
    save_data_fie(rooms);
}
int get_ava_room_no(int room_type, Room rooms[max])
{
    for (int i = 0; i < max; i++)
    {
        if (room_type == 111)
        {
            if (rooms[i].status == 0)
                return i;
        }
        if (room_type == 110)
        {
            if (rooms[20 + i].status == 0)
                return 20 + i;
        }
        if (room_type == 101)
        {
            if (rooms[30 + i].status == 0)
                return 30 + i;
        }
        if (room_type == 100)
        {
            if (rooms[40 + i].status == 0)
                return 40 + i;
        }
        if (room_type == 011)
        {
            if (rooms[50 + i].status == 0)
                return 50 + i;
        }
        if (room_type == 010)
        {
            if (rooms[60 + i].status == 0)
                return 60 + i;
        }
        if (room_type == 001)
        {
            if (rooms[70 + i].status == 0)
                return 70 + i;
        }
        if (room_type == 000)
        {
            if (rooms[80 + i].status == 0)
                return 80 + i;
        }
    }
    return -1;
}

void book_room(Room rooms[max], int room_id)
{
    cout << "\n\nEnter name = ";
    cin.ignore();
    getline(cin, rooms[room_id].cust.name);
    cout << "Enter address (city and country) = ";
    getline(cin, rooms[room_id].cust.address);
    cout << "Enter phone Number = ";
    getline(cin, rooms[room_id].cust.phone);
    cout << "Enter Total no days =";
    cin >> rooms[room_id].cust.total_days;
    cout << "Enter check-in Date (DD/MM/YYYY) = ";
    cin.ignore();
    getline(cin, rooms[room_id].cust.from_date);
    cout << "Enter check-out Date (DD/MM/YYYY) = ";
    cin.ignore();
    getline(cin, rooms[room_id].cust.to_date);

    rooms[room_id].cust.total_Rent = rooms[room_id].rent * rooms[room_id].cust.total_days;

    cout << "\nThe total Rent for your room will be = " << rooms[room_id].cust.total_Rent;
abc:
    cout << "\nEnter the advance payment amount you want to pay (min 50%) = ";
    cin >> rooms[room_id].cust.payment_advance;
    if (!check_payment_advance(rooms[room_id].cust.total_Rent, rooms[room_id].cust.payment_advance))
    {
        cout << "\nPlease pay minimum 50% of total Rent ";
        cout << "\nMinimum Amount to be paid while your booking =" << ((rooms[room_id].cust.total_Rent * 50) / 100);
        goto abc;
    }
    rooms[room_id].cust.remaining_payment = rooms[room_id].cust.total_Rent - rooms[room_id].cust.payment_advance;
    rooms[room_id].cust.booking_id = r_id++;
    rooms[room_id].status = 1;

    cout << "\nCongratulations Your Room is confirmed";
    display_customer_details(rooms, room_id);
    cout << "\n\nYou Can Check-in now\n";
    save_data_fie(rooms);
}
void book_room_menu(Room rooms[max])
{
    int opt;
abc:
    cout << "\n\n"
         << "Enter which type of room do you want to Book or check-in ? ";
    cout << "\n\n1.Full Furnished Ac Room for Two persons";
    cout << "\n2.Full Furnished Ac Room for Single persons";
    cout << "\n3.Semi Furnished Ac Room for Two persons";
    cout << "\n4.Semi Furnished Ac Room for Single persons";
    cout << "\n5.Full Furnished Non Ac Room for Two persons";
    cout << "\n6.Full Furnished Non Ac Room for Single persons";
    cout << "\n7.Semi Furnished Non Ac Room for Two persons";
    cout << "\n8.Semi Furnished Non Ac Room for Single persons";
    cout << "\n9.Cancel Booking and go back to main menu\n";
    cout << "Enter option = ";
    cin >> opt;
    switch (opt)
    {
    case 1:
    {
        int room_no = get_ava_room_no(111, rooms);
        if (room_no == -1)
        {
            cout << "\n"
                 << "This Type of Room is Full....Try to Book another Type of Room";
            goto abc;
        }
        else
        {
            cout << "\nCongratulations This type of room is available.....Enter your Details to confirm your Check-in!!!!";
            book_room(rooms, room_no);
        }
    }
    break;
    case 2:
    {
        int room_no = get_ava_room_no(110, rooms);
        if (room_no == -1)
        {
            cout << "\n"
                 << "This Type of Room is Full....Try to Book another Type of Room";
            goto abc;
        }
        else
        {
            cout << "\nCongratulations This type of room is available.....Enter your Details to confirm your Check-in!!!!";
            book_room(rooms, room_no);
        }
    }
    break;

    case 3:
    {
        int room_no = get_ava_room_no(101, rooms);
        if (room_no == -1)
        {
            cout << "\n"
                 << "This Type of Room is Full....Try to Book another Type of Room";
            goto abc;
        }
        else
        {
            cout << "\nCongratulations This type of room is available.....Enter your Details to confirm your Check-in!!!!";
            book_room(rooms, room_no);
        }
    }
    break;

    case 4:
    {
        int room_no = get_ava_room_no(100, rooms);
        if (room_no == -1)
        {
            cout << "\n"
                 << "This Type of Room is Full....Try to Book another Type of Room";
            goto abc;
        }
        else
        {
            cout << "\nCongratulations This type of room is available.....Enter your Details to confirm your Check-in!!!!";
            book_room(rooms, room_no);
        }
    }
    break;

    case 5:
    {
        int room_no = get_ava_room_no(011, rooms);
        if (room_no == -1)
        {
            cout << "\n"
                 << "This Type of Room is Full....Try to Book another Type of Room";
            goto abc;
        }
        else
        {
            cout << "\nCongratulations This type of room is available.....Enter your Details to confirm your Check-in!!!!";
            book_room(rooms, room_no);
        }
    }
    break;

    case 6:
    {
        int room_no = get_ava_room_no(010, rooms);
        if (room_no == -1)
        {
            cout << "\n"
                 << "This Type of Room is Full....Try to Book another Type of Room";
            goto abc;
        }
        else
        {
            cout << "\nCongratulations This type of room is available.....Enter your Details to confirm your Check-in!!!!";
            book_room(rooms, room_no);
        }
    }
    break;

    case 7:
    {
        int room_no = get_ava_room_no(001, rooms);
        if (room_no == -1)
        {
            cout << "\n"
                 << "This Type of Room is Full....Try to Book another Type of Room";
            goto abc;
        }
        else
        {
            cout << "\nCongratulations This type of room is available.....Enter your Details to confirm your Check-in!!!!";
            book_room(rooms, room_no);
        }
    }
    break;

    case 8:
    {
        int room_no = get_ava_room_no(000, rooms);
        if (room_no == -1)
        {
            cout << "\n"
                 << "This Type of Room is Full....Try to Book another Type of Room";
            goto abc;
        }
        else
        {
            cout << "\nCongratulations This type of room is available.....Enter your Details to confirm your Check-in!!!!";
            book_room(rooms, room_no);
        }
    }
    break;
    case 9:
        break;
    default:
        cout << "\nYou have Enter Invalid choice....Please Try Again !!! ";
        goto abc;
    }
}
void rooms_type_and_price(Room rooms[max])
{
    cout << "\n1.Full Furnished Ac Room for Two persons"
         << "\t\t"
         << "Rent =" << rooms[1].rent << "/per day";
    cout << "\n2.Full Furnished Ac Room for Single persons"
         << "\t\t"
         << "Rent =" << rooms[22].rent << "/per day";
    cout << "\n3.Semi Furnished Ac Room for Two persons"
         << "\t\t"
         << "Rent =" << rooms[32].rent << "/per day";
    cout << "\n4.Semi Furnished Ac Room for Single persons"
         << "\t\t"
         << "Rent =" << rooms[42].rent << "/per day";
    cout << "\n5.Full Furnished Non Ac Room for Two persons"
         << "\t\t"
         << "Rent =" << rooms[52].rent << "/per day";
    cout << "\n6.Full Furnished Non Ac Room for Single persons"
         << "\t\t"
         << "Rent =" << rooms[62].rent << "/per day";
    cout << "\n7.Semi Furnished Non Ac Room for Two persons"
         << "\t\t"
         << "Rent =" << rooms[72].rent << "/per day";
    cout << "\n8.Semi Furnished Non Ac Room for Single persons"
         << "\t\t"
         << "Rent =" << rooms[82].rent << "/per day";
}
Room rooms[max];
void guest_summary_report(Room rooms[max])
{
    int status = 0;
    cout << "\nGuest Summary Report Of Hotel";
    for (int i = 0; i < max; i++)
    {
        if (rooms[i].status == 1)
        {
            cout << "\n"
                 << i + 1 << ".\t Customer First Name : " << rooms[i].cust.name;
            cout << "\n\t Room Number : " << rooms[i].roomNumber;
            cout << "\n\t Address (only city) : " << rooms[i].cust.address;
            cout << "\n\t Phone : " << rooms[i].cust.phone;
            cout << "\n---------------------------------------";
            status = 1;
        }
    }
    if (status == 0)
    {
        cout << "\nNo Guest is found in the hotel";
    }
}
void search_customer(Room rooms[max])
{
    string name;
    int status = 0;
    cout << "\n\nEnter customer name = ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < max; i++)
    {
        if (rooms[i].cust.name == name)
        {
            cout << "\n\nCustomer found";
            display_customer_details(rooms, i);
            status = 1;
            break;
        }
    }
    if (status == 0)
    {
        cout << "\n"
             << "Customer not found";
    }
}
void hotel_details()
{
    string name = "Grand Hotel";
    string Address = "Esplanade, Kolkata, West Bengal";
    string owner = "Kundu & Jash Pvt. Ltd.";
    string estb = "2000";
    string star = "5 Star Hotel";
    string mob = "9654741623";

    cout << "\n\n"
         << "Welcome to Grand Hotel";
    cout << "\nName=" << name;
    cout << "\nAddress=" << Address;
    cout << "\nOwner=" << owner;
    cout << "\nEstablished=" << estb;
    cout << "\nStar=" << star;
    cout << "\nMobile=" << mob;
}
void menu()
{
    int opt;
    do
    {
        cout << "\n\n######## Hotel Management #########\n";
        cout << "\n*****Welcome to Grand Hotel*****\n";
        cout << "\n1. Get Hotel Details";
        cout << "\n2. Get Hotel Room Types with Price Details";
        cout << "\n3. Available Rooms";
        cout << "\n4. check_in Room (Book Room)";
        cout << "\n5. Check-Out Room";
        cout << "\n6. Search Customer";
        cout << "\n7. Guest Summary Report";
        cout << "\n8. Exit";
        cout << "\n\nEnter Option: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            hotel_details();
            break;
        case 2:
            rooms_type_and_price(rooms);
            break;
        case 3:
            available_rooms(rooms);
            break;
        case 4:
            book_room_menu(rooms);
            break;
        case 5:
            check_out_room(rooms);
            break;
        case 6:
            search_customer(rooms);
            break;
        case 7:
            guest_summary_report(rooms);
            break;
        case 8:
            cout << "\n\n*****Thankyou For Visiting Hotel*****";
            cout << "\nHope We See you soon Again !!!";
            cout << "\nGoodBye and Have a Nice Day !!!\n\n";
            break;
        default:
            cout << "\nInvalid input....Please Try again!!";
        }

    } while (opt != 8);
}

int main()
{
    define_room_types(rooms);
    get_file_data(rooms);
    menu();
    return 0;
}
