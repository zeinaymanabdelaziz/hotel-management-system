// Mai Waheed 202200556 //
// Zeina Ayman 202200351 //
// Farida Mohamed 202202579 //

#include <iostream>
#include <string>
using namespace std;
struct Room
{
    int RoomNumber;
    string RoomType;
    bool IsBooked;
};
struct Guest
{
    string GuestName;
    string GuestType;
    int GuestRoomNumber;
    int DaysNumber;
};
class Hotel
{
    private:
    int NRooms;
    Room* rooms;
    Guest* guests;
    public:
    Hotel(){
        cout << "Enter the number of rooms in the hotel: ";
        cin >> NRooms;
        rooms = new Room[NRooms];
        guests = new Guest[100];
    }
    void ManageRooms(){
        cout << "The room number of the available single rooms are: ";
        for (int i = 0;i < NRooms/2;i++){
            rooms[i].RoomNumber = i+1;
            rooms[i].IsBooked = false;
            rooms[i].RoomType = "single";
            cout << rooms[i].RoomNumber << "  ";
        }
        cout << "\nThe room number of the available double rooms are: ";
        for (int i = NRooms/2;i < NRooms;i++){
            rooms[i].RoomNumber = i+1;
            rooms[i].IsBooked = false;
            rooms[i].RoomType = "double";
            cout << rooms[i].RoomNumber << "  ";
        }
        cout << endl;
        for (int i = 0; i < 100; i++){
            guests[i].GuestName = " ";
            guests[i].DaysNumber = 0;
            guests[i].GuestRoomNumber = 0;
            guests[i].GuestType = " ";
        }
    }
    void CheckIn() {
        for (int i = 0; i < 100; i++) {
            if(guests[i].GuestName == " "){
                cout << "Enter guest " << i + 1 << " name: ";
                cin >> guests[i].GuestName;
                cout << "Enter how many days guest " << guests[i].GuestName << " want to stay: ";
                cin >> guests[i].DaysNumber;
                cout << "Enter the room type guest " << guests[i].GuestName << " want single or double: ";
                cin >> guests[i].GuestType;
                bool x = false;
                for (int a = 0; a < NRooms; a++) {
                    if (rooms[a].RoomType == guests[i].GuestType && rooms[a].IsBooked == false) {
                        guests[i].GuestRoomNumber = rooms[a].RoomNumber;
                        rooms[a].IsBooked = true;
                        x = true;
                        cout << "Booking is successful Guest " << guests[i].GuestName << " room number is: " << guests[i].GuestRoomNumber << endl;
                        break;
                    }
                }
                if (x == false) {
                    cout << "Sorry no " << guests[i].GuestType << " rooms available !" << endl;
                }
                break;
            }
        }
    }
    void GetAvailableRooms(){
        int scount = 0;
        int dcount = 0;
        for (int i = 0;i < NRooms;i++){
            if (rooms[i].IsBooked == false && rooms[i].RoomType == "single"){
                scount++;
                if (scount == 1){
                    cout << "The available single room numbers are: ";
                }   
                cout << rooms[i].RoomNumber << " ";
            }
            if (i == NRooms-1 && scount > 0){
                cout << "\n" << scount << " Single rooms available !" << endl;
            }
        }
        for (int i = 0;i < NRooms;i++){
            if (rooms[i].IsBooked == false && rooms[i].RoomType == "double"){
                dcount++;
                if (dcount == 1){
                    cout << "The available double room numbers are: ";
                }
                cout << rooms[i].RoomNumber << " ";
            }
            if (i == NRooms-1 && dcount > 0){
                cout << "\n" << dcount << " Double rooms available !" << endl;
            }
        }
        if (scount == 0 && dcount == 0){
            cout << "NO Available rooms !" << endl;
        }
    }
    void SearchGuest(){
        string Searchname;
        cout << "Enter the name of the guest you want to find: ";
        cin >> Searchname;
        bool presentguest = false;
        for (int i = 0;i < 100;i++){
            if (guests[i].GuestName == Searchname) {
                cout << "Name: " << guests[i].GuestName << " // Room number: " << guests[i].GuestRoomNumber << " // Days: " << guests[i].DaysNumber << endl;
                presentguest = true;
            }
        }
        if (presentguest == false) {
            cout << "Guest not found in the hotel !" << endl;
        }
    }
    void GuestSummaryReport(){
        int TotalIncome = 0;
        int TotalBookings = 0;
        int TotalSingle = 0;
        int TotalDouble = 0;
        int PriceSingle = 1000;
        int PriceDouble = 2000;
        for (int i = 0;i < 100;i++){
            if (guests[i].GuestType == "single"){
                TotalSingle += guests[i].DaysNumber * PriceSingle;
            }
            if (guests[i].GuestType == "double"){
                TotalDouble += guests[i].DaysNumber * PriceDouble;
            }
            if (rooms[i].IsBooked == true){
                TotalBookings++;
            }
        }
        TotalIncome = TotalSingle + TotalDouble;
        cout << "Guest summary report: " << endl;
        cout << "Total bookings: " << TotalBookings << endl;
        cout << "Total income: " << TotalIncome << endl;
    }
    void MakePayment(){
        int PriceSingle = 1000;
        int PriceDouble = 2000;
        string name;
        cout << "Enter the name of the guest who want to pay: ";
        cin >> name;
        int payment;
        bool found = false;
        for (int i = 0;i < 100;i++){
            if (guests[i].GuestName == name){
                found = true;
                if (guests[i].GuestType == "double"){
                    payment = guests[i].DaysNumber * PriceDouble;
                    cout << "Customer " << name << " payment is: " << payment << endl;
                }
                else{
                    payment = guests[i].DaysNumber * PriceSingle;
                    cout << "Customer " << name << " payment is: " << payment << endl;
                } 
            }
        }
        if (found == false){
            cout << "Guest not found in the hotel !" << endl;
        }
    }
    void CheckOut(){
        string name;
        cout << "Enter the name of the guest who want to check out: ";
        cin >> name;
        int room;
        cout << "Enter the room number that want to check out: ";
        cin >> room;
        bool test = false;
        for (int i = 0;i < 100;i++){
            if (guests[i].GuestName == name){
                test = true;
                guests[i].DaysNumber = 0;
                guests[i].GuestRoomNumber = 0;
                guests[i].GuestName = " ";
                guests[i].GuestType = " ";
                for (int i = 0;i < NRooms;i++){
                    if(rooms[i].RoomNumber == room){
                    rooms[i].IsBooked = false;
                    }
                }
                cout << "Guest checked out successful !" << endl;
                break;
            }
        }
        if (test == false) {
                cout << " Guest " << name << " hasn't booked a room in the hotel !" << endl;
        }
    }
    void DeleteRecord(){
        for (int i = 0;i < NRooms;i++){
            rooms[i].IsBooked = false;
        }
        for (int i = 0;i < 100;i++){
            guests[i].DaysNumber = 0;
            guests[i].GuestRoomNumber = 0;
            guests[i].GuestName = " ";
            guests[i].GuestType = " ";
        }
        cout << "All records got deleted successful !" << endl;
    }
};
int main()
{
    Hotel hotel;
    hotel.ManageRooms();
    cout << "\nOPTIONS : " << endl;
    cout << "Option 1 : Check in" << endl;
    cout << "Option 2 : Get available rooms" << endl;
    cout << "Option 3 : Search information of a specific guest" << endl;
    cout << "Option 4 : Get guests summary report" << endl;
    cout << "Option 5 : Make payment for a guest" << endl;
    cout << "Option 6 : Check out" << endl;
    cout << "Option 7 : Delete all records" << endl;
    cout << "Option 8 : Exit Program\n" << endl;
    int choice = 0;
    while (choice != 8){
        cout << "Enter the option you want to choose : ";
        cin >> choice;
        if (choice == 1){
            hotel.CheckIn();
        }
        if (choice == 2){
            hotel.GetAvailableRooms();
        }
        if (choice == 3){
            hotel.SearchGuest();
        }
        if (choice == 4){
            hotel.GuestSummaryReport();
        }
        if (choice == 5){
            hotel.MakePayment();
        }
        if (choice == 6){
            hotel.CheckOut();
        }
        if (choice == 7){
            hotel.DeleteRecord();
        }
    }
}