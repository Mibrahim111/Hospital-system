#include "Menu.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
#define Reserve 500
#define HospitalsNo 50
#define pats 200
#define adm 20

struct Day
{
	int day;
	int month;
	int year;
};

struct Admin {
	string name;
	string password;
	string ID;
};


struct hospitals {

	string name;
	string specialities[3];
	string ID; //numbers only
	string address;
	int no_of_beds, price_beds, available_beds, clinics;
	float rating;
	int num_rate = 1;

	//vector <Reservation> reservationsQ;// reservations are deleted in "Q" when rated


};

struct patient {
	string userName;
	string userID;//numbers only "pls enter a number"
	string userAge;//numbers only
	char userGender; // m,f only
	string userPassword;
	string height;
	string weight;

	vector <Reservation> PatRes;
	

};

struct Reservation {

	string ResID;
	hospitals hospital;
	/*patient ResPat;*/
	Day ResDay;
	string spec;

};

int iAdmin = 0;
patient userinfo;
Admin admininfo;


vector <hospitals> hospitalList(HospitalsNo); ////using vectors 
vector <patient> user{ {"m","2004","20",'m',"12345","195","100",} };
Reservation Reservations[Reserve]; //use Queue DS and Add member "Date Struct" 
Admin admins[adm] = { {"a1","12345","1"} ,{"a2","12345","2"} };
//intializing two objects "admins" instead of files "not needed" 



//-------------------------------------------------------------

int mainMenu()
{
	int choice = -1;

	while (choice == -1) {
		/*cout << "\n---------------Hospital Management System-----------------\n";
*/
		cout << "\n1)Sign in as a User\n";
		cout << "\n2)Create New User\n"; ///add new user
		  ///run as user function
		cout << "\n3)Sign in as an Admin\n";
		///run as admin function
		cout << "\n4)Create New Admin\n";
		cout << "\n0)Exit\n";

		cin >> choice;

		if (!(0 <= choice && choice <= 4)) {
			cout << "Invalid choice , Please try again\n";
			choice = -1; //loop continues
		}
	}
	return choice;
}

int newAdminMenu() {

	int choice = -1;

	while (choice == -1)
	{


		cout << "\n1)Create a New Admin\n";

		cout << "2)Back\n";

		cout << "0)Exit\n";

		cin >> choice;

		if (!(choice <= 2 && choice >= 0))
		{
			cout << "\nEnter a Valid Option\n";
			choice = -1;
		}
	}
	return choice;
}

int newUserMenu()
{
	int choice = -1;

	while (choice == -1)
	{


		cout << "\n1)Create a New User\n";

		cout << "2)Back\n";

		cout << "0)Exit\n";

		cin >> choice;

		if (!(choice <= 2 && choice >= 0))
		{
			cout << "\nEnter a Valid Option\n";
			choice = -1;
		}
	}
	return choice;
}

int userMenu()

{
	int choice = -1;

	while (choice == -1) {
		cout << "\n---------------------------------User Menu------------------------------\n";

		cout << "\n1)Print User Info\n";
		cout << "\n2)Edit User Info\n";
		cout << "\n3)Search Hospital\n"; //overloading
		cout << "\n4)Rate Hospital\n";  //Overloading
		cout << "\n5)Print All Hospitals' Names\n";
		cout << "\n6)New Reservation\n";
		cout << "\n7)Edit My Reservations\n";
		cout << "\n8)Delete Reservation\n";
		cout << "\n9)showReservation\n";
		cout << "\n10)Back\n";// maybe I will remove it later
		cout << "\n0) Exit\n";

		cin >> choice;

		if (!(0 <= choice && choice <= 10)) {
			cout << "Invalid choice , Please try again\n";
			choice = -1; //loop continues
		}
	}
	return choice;

}

int adminMenu()
{
	int choice = -1;

	while (choice == -1) {
		cout << "\n ----------------------------------- Admin Menu--------------------------------\n";

		cout << "\n1)Add Hospital\n";
		cout << "\n2)Edit Hospital\n";
		cout << "\n3)Remove Hospital\n";
		cout << "\n4)Sort Hospitals by name\n"; //Overloading
		cout << "\n5)Sort Hospitals by price\n";
		cout << "\n6)Print All Hospitals\n";
		cout << "\n7)Search Hospitals\n";//Search and print info
		cout << "\n8)Search Patients\n";
		cout << "\n9)Sort Patient by name\n";//Search and print info
		cout << "\n10)Print All Patients\n";
		cout << "\n11)Remove User\n";
		cout << "\n12)Show Admin Info\n";
		cout << "\n13)Back\n";
		cout << "\n0) Exit\n";

		cin >> choice;

		if (!(0 <= choice && choice <= 13)) {
			cout << "Invalid choice , Please try again\n";
			choice = -1; //loop continues
		}
	}
	return choice;

}

//-----------------------------------------------

void runMainMenu()
{
	user.reserve(pats);
	
	int choice = mainMenu();
	while (1) {


		switch (choice) {

		case 0:
			exit(0);

		case 1:
			sign_in_as_User();
			break;
		case 2:
			runNewUser();

			break;
		case 3:
			sign_in_as_admin();
			break;
		case 4:
			runNewAdmin();
			/*default:
				cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
				break;*/
		}
	}
}

void runNewUser()
{
	int choice = newUserMenu();

	switch (choice) {
	case 0:
		exit(0);
		break;
	case 1:
		add_user();
		break;
	case 2:
		runMainMenu();
		break;
	default:
		cout << "Invalid input! Please enter a number between 0 and 2." << endl;
		break;
	}
}

void runNewAdmin()
{
	int choice = newAdminMenu();

	switch (choice) {
	case 0:
		exit(0);
		break;
	case 1:
		addAdmin();
		break;
	case 2:
		runMainMenu();
		break;
	default:
		cout << "Invalid input! Please enter a number between 0 and 2." << endl;
		break;
	}
}

void runUserMenu()
{
	int choice = userMenu();

	/*while (choice != 0) {*/



	switch (choice) {

	case 0:
		exit(0);
	case 1:
		DisplayInfo();
		break;
	case 2:
		edit_user();
		break;
	case 3:
		searchHospital();
		break;
	case 4:
		rate(); //rate
		break;
	case 5:
		printAllHospitals();
		break;
	case 6: AddReservation();

		break;
	case 7: modifyReservation();

		break;
	case 8:cancelReservation();

		break;

	case 9:
		ShowReservation();
		break;
	case 10:
		runMainMenu();
		break;


	default:
		cout << "Invalid input! Please enter a number between 0 and 10." << endl;
		break;
	}

	//}
}

void runAdminMenu()
{
	int choice = adminMenu();

	/*while (choice != 0) {*/


	switch (choice) {

	case 0:
		exit(0);
		break;

	case 1:
		addHospital();
		break;
	case 2:
		editHospital();   //edit hos
		break;
	case 3:
		removeHospital();  //remove hos
		break;
	case 4:
		sort_name();
		break;
	case 5:
		sort_price();
		break;
	case 6:
		printAllHospitals();
		break;
	case 7:
		searchHospital();
		break;
	case 8:
		searchPatient();
		break;
	case 9:
		sort_name_patients();
		break;
	case 10:
		printAllPatients();
		break;
	case 11:
		deleteUser();
		break;
	case 12:
		showAdminInfo();
		break;
	case 13:
		runMainMenu();
		break;

	default:
		cout << "Invalid input! Please enter a number between 0 and 13" << endl;
		break;
	}

	//}
}

//reservations in user menu

//patients menu in admin menu
//hospitals menu in admin menu
//----------------------------------------------------------------

void sign_in_as_User()
{

	while (1) {

		patient p1;
		string password, username;

		cout << "\nPlease enter Username: ";
		cin >> username;
		cout << "\nPlease enter password: ";
		cin >> password;

		if (username == "0" && password == "0")
			runMainMenu();

		bool flag = 0;
		int cnt = 0;
		for (int i = 0; i < pats; i++)
		{
			if (username == user[i].userName && password == user[i].userPassword)
			{
				userinfo = user[i];
				p1 = user[i];
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
		if (cnt == 3)
			exit(1);
		else
		{
			cnt++;
			cout << "\nInvalid username or password\n \n press 0 0 to return to main menu\n";

		}
	}
	while (1) {

		runUserMenu();
	}

}

void sign_in_as_admin() {

	while (1) {

		Admin a1;

		string password, username;

		cout << "\nPlease enter Username: ";
		cin >> username;
		cout << "\nPlease enter password: ";
		cin >> password;

		bool flag = 0;
		int cnt = 0;


		if (username == "0" && password == "0")
			runMainMenu();

		for (int i = 0; i < adm; i++)
		{

			if (username == admins[i].name && password == admins[i].password)
			{
				admininfo = admins[i];
				a1 = admins[i];
				flag = 1;
				break;
			}

		}

		if (flag)
			break;

		else
		{
			cnt++;
			cout << "\nInvalid username or password\n \n press 0 0 to return to main menu\n";
		}
	}
	while (1) {


		runAdminMenu();
	}



}



//reservations Add , Edit , Rate , Delete (Automatically after rating)
//-----------------------------------------------------------------

int numReservation = 0;

void AddReservation() {
	if (numReservation >= Reserve) {
		cout << "Reservation limit reached." << endl;
		return;
	}

	Reservation newReservation;

	cout << "Enter ReservationID: ";
	cin >> newReservation.ResID;
	while (1) {
		string str;
		cout << "Enter Hospital Name: ";
		cin >> str;

		bool flag = 0;
		for (int i = 0; i < hospitalList.size(); i++)
			if (str == hospitalList[i].name)
			{
				hospitalList[i].available_beds--;
				newReservation.hospital = hospitalList[i];
				flag = 1;
				break;
			}
		
		if (!flag)
		{
			cout << "Invalid Hospital Name\n";
			
		}
		else
			break;

	}
	cout << "Enter Reservation Day: ";
	cin >> newReservation.ResDay.day >> newReservation.ResDay.month >> newReservation.ResDay.year;

	cout << "Enter speciality: ";
	cin >> newReservation.spec;


	Reservations[numReservation++] = newReservation;
	userinfo.PatRes.push_back(newReservation);
	cout << "Reservation added successfully!" << endl;

}

void ShowReservation()
{
	if (numReservation == 0) 
	{
		cout << "No Reservations found." << endl;
		return;
	}

	cout << "Reservation Details: " << endl;
	for (int i = 0; i < userinfo.PatRes.size(); i++) {
		cout << "ReservationID: " << userinfo.PatRes[i].ResID << endl;
		cout << "\nHospital's Name: " << userinfo.PatRes[i].hospital.name << "\nHospital's ID: " << userinfo.PatRes[i].hospital.ID << "\nHospital's Address: " << userinfo.PatRes[i].hospital.address <<"\nHospital's Rating: " << userinfo.PatRes[i].hospital.rating << endl;
         		
		cout << "\nReservationDay: " << userinfo.PatRes[i].ResDay.day << " /" << Reservations[i].ResDay.month << "/" << Reservations[i].ResDay.year << "\n";
		cout << "ReservationSpeciality: " << userinfo.PatRes[i].spec << endl;
		cout << "Reservation Price: " << userinfo.PatRes[i].hospital.price_beds << endl;
		cout << "\n****************************************************************\n";
	}
}

void modifyReservation() {
	cout << " Enter ReservationID " << '\n';
	string reservationID;

	cin >> reservationID;
	for (int i = 0; i < numReservation; i++) {
		if (Reservations[i].ResID == reservationID) {
			cout << "Enter new ReservationDay: ";
			cin >> Reservations[i].ResDay.day >> Reservations[i].ResDay.month >> Reservations[i].ResDay.year;

			cout << "Enter new Reservation speciality: ";
			cin >> Reservations[i].spec;


			cout << "Reservation modified successfully!" << '\n';
			return;
		}
	}

	cout << "Invalid Reservation." << '\n';
	return;
}

void cancelReservation() {
	cout << " Enter ReservationID to cancel your reservation " << '\n';
	string reservationID;

	cin >> reservationID;
	for (int i = 0; i < numReservation; i++) {
		if (Reservations[i].ResID == reservationID) {
			for (int j = i; j < numReservation - 1; j++)
			{
				Reservations[j] = Reservations[j + 1]; //shift left
			}
			numReservation--;
			cout << "\n    Reservation cancelled     \n";
			return;
		}
	}

	cout << " Invalid ID " << '\n';
	return;
}

void ratingHospital() {
	string str;
	int r;
	cout << "\nPlease enter hospital's name\n";
	cin >> str;

	bool found = 0;
	/*if (hospitalList.size() <= 0)
		cout << "NO Hospitals in the system\n";
	else*/
		for (int i = 0; i < hospitalList.size(); i++)
		{
			if (str == hospitalList[i].name)
			{
				while (1) {
					cout << "\nEnter a number between 1 and 5 to rate the hospital\n";
					cin >> r;
					if (r < 1 || r>5)
					{
						cout << "\n Invalid Input \n";
					}

					else {
						hospitalList[i].rating += r;
						hospitalList[i].rating /= hospitalList[i].num_rate;
						hospitalList[i].num_rate++;
						cout << "\nRating added successfully\n";
						found = 1;
						
						break;
					}
				}
				break;
			}

		}
	if (!found)

		cout << "\nInvalid name\n";

}

void rate()
{
	int r;
	cout << "Please enter reservation ID\n";
	string id;
	cin >> id;

	for (int i = 0; i < numReservation; i++)
	{
		if (id == Reservations[i].ResID)
		{
			while (1) {
				cout << "\nEnter a number between 1 and 5 to rate the hospital\n";
				cin >> r;
				if (r < 1 || r>5)
				{
					cout << "\n Invalid Input \n";
				}

				else {
					Reservations[i].hospital.rating += r;
					Reservations[i].hospital.rating /= Reservations[i].hospital.num_rate;
					Reservations[i].hospital.num_rate++;
					cout << "\nRating added successfully\n";
					/*found = 1;*/

					break;
				}

			}
		}
		else
		{
			cout << "\nInvalid Reservation\n ";
		}
	}
}

// -----------------------------------------------------------------


	int HosList = 0;

void addHospital()
{
	hospitals newHospital;
	string str;

	cout << "\nEnter Hospital's name :";
	cin >> str;

	cout << "\nEnter Hospital's ID :";
	cin >> newHospital.ID;

	cout << "\nEnter Hospital's Address :";
	cin >> newHospital.address;

	cout << "\nEnter Hospital's Beds Number :";
	cin >> newHospital.no_of_beds;

	cout << "\nEnter Hospital's Beds Price :";
	cin >> newHospital.price_beds;

	/*cout << "\nEnter Hospital's Clinics Number  :";
	cin >> newHospital.clinics;*/

	cout << "\nEnter specialities (3) :" << "\n";
	for (int i = 0; i < 3; ++i)
	{
		cin >> newHospital.specialities[i];
	}

	newHospital.available_beds = newHospital.no_of_beds;

	newHospital.rating = 0;  newHospital.name = str;

	hospitalList[HosList] = newHospital; HosList++;
	cout << "\nHospital Added Successfully\n";


}

void editHospital()
{
	string n; string id;
	cout << "\nEnter Hospital's Name and ID to edit it ";
	cin >> n >> id;
	for (int i = 0; i < HosList; ++i) {
		if (n == hospitalList[i].name && id == hospitalList[i].ID)
		{
			cout << "\nEnter new name :";
			cin >> hospitalList[i].name;

			cout << "\nEnter new ID :";
			cin >> hospitalList[i].ID;

			cout << "\nEnter new Address :";
			cin >> hospitalList[i].address;

			cout << "\nEnter new number of beds :";
			cin >> hospitalList[i].no_of_beds;

			cout << "\nEnter new price of beds :";
			cin >> hospitalList[i].price_beds;

			cout << "\nEnter new number of clincs :";
			cin >> hospitalList[i].clinics;

			cout << "\nData edited successfully\n";
			return;
		}
	}
	cout << "Invalid Hospital Name or ID\n.";
	return;
}

void removeHospital()
{
	string n;
	cout << "\n Enter Hospital's Name to remove :";
	cin >> n;
	bool changed = 0;

	for (int i = 0; i < HosList; ++i) {
		if (n == hospitalList[i].name) {
			for (int j = i; j < HosList - 1; ++j) {
				cout << "\n         Hospital is removed         \n";
				if (j != HosList - 1)
					hospitalList[j] = hospitalList[j + 1]; //shift left

			}
			changed = 1;
			HosList--;
			return;
		}



	}

	cout << "\n Invalid Data \n";
	return;
}

void printAllHospitals() {
	if (HosList == 0)
	{
		cout << "\nThe Hospital list is empty\n";
		return;
	}

	cout << "\n\n Hospitals List \n\n";

	for (int i = 0; i < HosList; ++i) {
		cout << "Name:" << hospitalList[i].name << '\n';
		cout << "ID:" << hospitalList[i].ID << '\n';
		cout << "Address:" << hospitalList[i].address << '\n';
		cout << "Total number of beds:" << hospitalList[i].no_of_beds << '\n';
		cout << "Availble beds:" << hospitalList[i].available_beds << '\n';
		cout << "Beds' Price:" << hospitalList[i].price_beds << '\n';
		cout << "Specialities:"; for (int j = 0; j < 3; j++)cout << hospitalList[i].specialities[j] << " ";
		cout << "\nRating :" << hospitalList[i].rating << '\n';

		cout << "\n****************************************************\n";
	}
}

void searchHospital()
{
	string name;
	string id;
	cout << "Enter name:";
	cin >> name;
	cout << "Enter id:";
	cin >> id;


	bool found = 0;
	for (int i = 0; i < HosList; i++) {
		if (hospitalList[i].ID == id && hospitalList[i].name == name) {
			cout << "\nName:" << hospitalList[i].name << '\n';
			cout << "ID:" << hospitalList[i].ID << '\n';
			cout << "Total number of beds:" << hospitalList[i].no_of_beds << '\n';
			cout << "Availble beds:" << hospitalList[i].available_beds << '\n';
			cout << "Beds' Price:" << hospitalList[i].price_beds << '\n';
			cout << "Rating :" << hospitalList[i].rating << '\n';
			cout << "clinics :" << hospitalList[i].clinics << '\n';
			cout << "Specialities:"; for (int j = 0; j < 3; j++)cout << hospitalList[i].specialities[j] << " ";
			cout << "\n****************************************************\n";

			found = 1;
			return;

		}

	}

	cout << "\nInvalid name or ID\n";
	return;
}

void sort_name() {

	for (int i = 0; i < HosList - 1; i++)
		for (int j = 0; j < HosList - i - 1; j++)
			if (hospitalList[j].name > hospitalList[j + 1].name)
				swap(hospitalList[j], hospitalList[j + 1]);

	cout << "\nSorted Successfully\n";
}

void sort_price() {
	for (int i = 0; i < HosList - 1; i++)
		for (int j = 0; j < HosList - i - 1; j++)
			if (hospitalList[j].price_beds > hospitalList[j + 1].price_beds)
				swap(hospitalList[j], hospitalList[j + 1]);
	cout << "\nSorted Successfully\n";
}

void sortByAvlBeds()
{
	for (int i = 0; i < HosList - 1; i++)
		for (int j = 0; j < HosList - i - 1; j++)
			if (hospitalList[j].available_beds > hospitalList[j + 1].available_beds)
				swap(hospitalList[j], hospitalList[j + 1]);
	cout << "\nSorted Successfully\n";

}

void sortByTotalBeds()
{
	for (int i = 0; i < HosList - 1; i++)
		for (int j = 0; j < HosList - i - 1; j++)
			if (hospitalList[j].no_of_beds > hospitalList[j + 1].no_of_beds)
				swap(hospitalList[j], hospitalList[j + 1]);
	cout << "\nSorted Successfully\n";
}


//-------------------------------------------------


int index = 0;

void add_user() {


	cout << "\nCreate a new user, please enter valid data\n";

	cout << "\nEnter username: " << endl;
	cin >> user[index].userName;

	cout << "\nEnter userID: " << endl;
	cin >> user[index].userID;

	cout << "\nEnter user Age: " << endl;
	cin >> user[index].userAge;

	while (1) {
		cout << "\nEnter user Gender (m/f)" << endl;
		char str;
		cin >> str;
		tolower(str);
		if (str == 'm' || str == 'f')
		{
			user[index].userGender = str;
			break;
		}
	}

	cout << "\nEnter user password: " << endl;
	cin >> user[index].userPassword;

	cout << "\nEnter user height: " << endl;
	cin >> user[index].height;

	cout << "\nEnter user weight: " << endl;
	cin >> user[index].weight;

	user[index].PatRes.resize(Reserve);

	index++;

	cout << "\n       User Added Successfully       \n";
}

void DisplayInfo() {

	cout << "Your username is: " << userinfo.userName << endl;

	cout << "Your ID is: " << userinfo.userID << endl;

	cout << "Your age is: " << userinfo.userAge << endl;

	cout << "Your gender is: " << userinfo.userGender << endl;

	cout << "Your height is: " << userinfo.height << endl;

	cout << "Your weight is: " << userinfo.weight << endl;

	cout << "Your password is: " << userinfo.userPassword << endl<<endl;

	ShowReservation();

	/*cout << "Your reservations : \n";
	if (userinfo.PatRes.size() != 0)
		for (int i = 0; i < userinfo.PatRes.size(); i++)
		{
			cout << userinfo.PatRes[i].ResID << " " <<
				userinfo.PatRes[i].hospital.name << " " << userinfo.PatRes[i].hospital.ID << "\n"
				<< userinfo.PatRes[i].ResDay.day << "/"
				<< userinfo.PatRes[i].ResDay.month << "/"
				<< userinfo.PatRes[i].ResDay.year << "\n";
		}
	else
		cout << "\nNO reservations found\n";*/
}

void searchPatient()
{

	string id;

	string name;
	cout << "Enter id:";
	cin >> id;
	cout << "Enter name:";
	cin >> name;

	for (int i = 0; i < index; i++) {
		if (user[i].userID == id && user[i].userName == name)
		{
			userinfo = user[i];
			DisplayInfo();
		}
	/*for (int i = 0; i < index; i++) {
		if (user[i].userID == id && user[i].userName == name) {
			cout << "\nuserId: " << user[i].userID << "\nuserName: " << user[i].userName << "\nuserAge: " << user[i].userAge << "\nuserGender: " << user[i].userGender << "\nuserWeight: " << user[i].weight << " kg" << "\nuserHeight" << user[i].height << " cm" << "\nuserPassword :" << user[i].userPassword << "\n";

			if (userinfo.PatRes.size() != 0)
				for (int i = 0; i < userinfo.PatRes.size(); i++)
					cout << userinfo.PatRes[i].ResID << " " <<
					userinfo.PatRes[i].hospital.name << " " << userinfo.PatRes[i].hospital.ID << "\n"
					<< userinfo.PatRes[i].ResDay.day << " "
					<< userinfo.PatRes[i].ResDay.month << " "
					<< userinfo.PatRes[i].ResDay.year << " " << "\n";
			else
				cout << "\nYou haven't made any reservations yet\n";
			break;
		}
		*/
		else
			cout << "\ninvalid id/name\n";
	}


}

void printAllPatients()
{
	if (index == 0)
	{
		cout << "\nthe patients list is empty\n";
		return;
	}
	cout << "\n\n Patients list \n\n";
	for (int i = 0; i < index; ++i)
	{
		cout << "Name: " << user[i].userName << '\n';
		cout << "Id: " << user[i].userID << '\n';
		cout << "Age: " << user[i].userAge << '\n';
		cout << "Gender: " << user[i].userGender << '\n';
		cout << "weight: " << user[i].weight << '\n';
		cout << "height: " << user[i].height << '\n';
		cout << "Password: " << user[i].userPassword << '\n';

		cout << "\n***********************************\n";
	}
}

void edit_user() {

	userinfo;

	string ID;
	string name;
	int age;
	char gender;
	string password;

	cout << "Enter new username: " << endl;
	cin >> name;
	cout << "Enter new userID: " << endl;
	cin >> ID;
	cout << "Enter new user Age: " << endl;
	cin >> age;

	while (1) {
		cout << "\nEnter new user Gender (m/f)" << endl;
		char str;
		cin >> str;
		tolower(str);
		if (str == 'm' || str == 'f')
		{
			gender = str;
			break;
		}
	}

	cout << "Enter user password: " << endl;
	cin >> password;


	for (int i = 0; i < index; i++) {
		if (user[i].userID == userinfo.userID  && user[i].userName == userinfo.userName) {
			user[i].userName = name;
			user[i].userID = ID;
			user[i].userAge = age;
			user[i].userPassword = password;
			user[i].userGender = gender;
		}
	}
	userinfo.userName = name;
	userinfo.userID = ID;
	userinfo.userAge = age;
	userinfo.userPassword = password;
	userinfo.userGender = gender;


}

void sort_name_patients()
{
	/*for (int i = 0; i < size; i++) {
		cout << "Enter name:";
		cin >> user[i].name;
	}*/

	for (int i = 0; i < index - 1; i++)
		for (int j = 0; j < index - i - 1; j++)
			if (user[j].userName > user[j + 1].userName)
				swap(user[j], user[j + 1]);


}

void deleteUser()
{
	string str;
	cout << "\nEnter Username to remove patient\n";
	cin >> str;


	for (int i = 0; i < index; i++)
	{
		if (str == user[i].userName)
		{
			for (int j = i; j < index - 1; ++j) {


				user[j] = user[j + 1]; //shift left

			}
			cout << "\nRemoved successfully\n";
			index--;
			return;
		}
	}

	cout << "\nInvalid Data\n";
	return;
}


//-----------------------------------------------------------------

//add admin
void addAdmin() {


	string n, pass;
	string id;


	cout << "Enter your name : ";
	cin >> n;
	cout << "Enter your password : ";
	cin >> pass;
	cout << "Enter your id : ";
	cin >> id;

	admins[iAdmin].name = n;
	admins[iAdmin].password = pass;
	admins[iAdmin].ID = id;
	iAdmin++;



	cout << "\n       Admin Added successfully       \n";

}

void removeAdmin() {
	string str;
	cout << "\nEnter Admin's name to remove\n";
	cin >> str;

	for (int i = 0; i < iAdmin; i++)
	{
		if (str == admins[i].name)
		{
			for (int j = i; j < iAdmin - 1; ++j) {
				cout << "\n         Admin is removed         \n";
				if (j != iAdmin - 1)
				{
					admins[j] = admins[j + 1]; //shift left
					iAdmin--;
					admininfo.ID = "0";
					admininfo.name = "0";
					admininfo.password = "0";
					return;
				}

			}

		}
	}

}
// needs DEBUGGING

void showAdminInfo() {
	cout << "\nName :" << admininfo.name;

	cout << "\nID :" << admininfo.ID;

	cout << "\nPassword:" << admininfo.password;

}

////files--------------------------------

void write(hospitals hospitallist[]) {
	fstream out("hospitalData.txt", ios::out);
	if (!out)
	{
		cout << "file not found\n";
		return;
	}
	for (int i = 0; i < HosList; i++)
	{
		out << hospitalList[i].name << " " << hospitalList[i].ID << " "
			<< hospitalList[i].no_of_beds << " " << hospitalList[i].price_beds << " "
			<< hospitalList[i].clinics << "\n";
	}
	out.close();
}

void write(vector <patient> patients)
{
	fstream out("userData.txt", ios::out);
	if (!out)
	{
		cout << "file not found\n";
		return;
	}
	for (int i = 0; i < patients.size(); i++)
	{
		out << patients[i].userName << " " << patients[i].userID << " "
			<< patients[i].userAge << " " << patients[i].userGender << " "
			<< patients[i].userPassword << " " << patients[i].height << " " <<
			patients[i].weight << endl;

		for (int j = 0; j < (int)patients[i].PatRes.size();j++)
		{
			out << patients[i].PatRes[j].ResID << " " << patients[i].PatRes[j].hospital.name << " "
			<< patients[i].PatRes[j].hospital.ID << " " << patients[i].PatRes[j].hospital.address << " " << patients[i].PatRes[j].hospital.no_of_beds
				<< " " << patients[i].PatRes[j].hospital.price_beds << " " << patients[i].PatRes[j].hospital.specialities
				<< " " << patients[i].PatRes[j].ResDay.day << " " << patients[i].PatRes[j].ResDay.month << " " << patients[i].PatRes[j].ResDay.year <<
				" " << patients[i].PatRes[j].spec << endl;
		}
	}
	out.close();
}

//void write(Admin admins[])
//{
//	fstream out("adminData.txt", ios::out);
//	if (!out)
//	{
//		cout << "file not found\n";
//		return;
//	}
//	for (int i = 0; i <iAdmin; i++)
//	{
//		out << admins[i].name << " " << admins[i].password << " "
//			<< admins[i].ID << "\n";
//	}
//	out.close();
//}

//void write(Reservation res[]){
//	fstream out("userData.txt", ios::out);
//	if (!out)
//	{
//		cout << "file not found\n";
//		return;
//	}
//	for (int i = 0; i < numReservation; i++)
//	{
//		out << res[i].ReservationID << " " << res[i].HospitalID << " "
//			<< res[i].ReservationDay << "\n";
//	}
//}

/////////////////////////////////////////////////////

