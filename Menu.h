#pragma once

struct hospitals;

struct Admin;

struct patient;

struct Reservation;

struct Day;

//////////////////////////run 



int mainMenu();

int newAdminMenu();

int newUserMenu();

int userMenu();

int adminMenu();

void runMainMenu();

void runNewUser();

void runNewAdmin();

void runUserMenu();

void runAdminMenu();

////////////// sign-in

void sign_in_as_User();

void sign_in_as_admin();

//////////////reservations

void AddReservation(); 

void modifyReservation();

void ShowReservation();

void cancelReservation();

void rate();

/////////Hospitals

void addHospital();

void editHospital();

void removeHospital();

void printAllHospitals();

void searchHospital();

void ratingHospital();

void sort_name();

void sort_price();

void sortByAvlBeds();

void sortByTotalBeds();

//////Patients

void add_user();

void DisplayInfo();

void searchPatient();

void printAllPatients();

void sort_name_patients();

void deleteUser();

void edit_user();

//////


void addAdmin();

void removeAdmin();

void showAdminInfo();



///////////////






///////////////////////////////

