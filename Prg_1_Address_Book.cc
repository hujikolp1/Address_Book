#include <string> //to_string(int)
#include <stdlib.h> //rand
#include <time.h> //time
#include <iostream>
using namespace std;

const int NUM_FIELDS = 4,
        FIRST_NAME = 0,
        LAST_NAME = 1,
        TEL = 2,
        ADDR = 3;


void displayMenu();
void displayAddressBook(string **AddressBook, const int user_count);
void addPerson(string **AddressBook, int &user_count);
void sort(string **AddressBook, const int user_count);
void deleteContact(string **AddressBook, const int user_count);
void lowerCase(string &input);

string randLastName();
string randFirstName();
string randStreetName();
string lastnameInput;

int main() {
    srand ( time(NULL) );
    int user_count = 0;
    string **AddressBook; //first, last, tel, addr

    int menuItem;
    bool keepGoing = true;
    do {
        displayAddressBook(AddressBook, user_count);
        displayMenu();
        cin >> menuItem;
        cin.ignore();
        switch (menuItem) {
            case 1:
                cout << "1. Add a new contact" << endl;
                addPerson(AddressBook, user_count);
                break;
            case 2:
                cout << "2. Update an existing contact" << endl;
                break;
            case 3:
                cout << "3. Delete a contact" << endl;
                deleteContact(AddressBook, user_count);
                break;
            case 4:
                cout << "4. List all added contacts in sorted order" << endl;
                sort(AddressBook, user_count);
                break;
            case 5:
                cout << "5. Search for a given contact" << endl;
                break;
            case 6:
                cout << "6. Quit" << endl;
                keepGoing = false;
                break;
            default:
                break;
        }
    } while(keepGoing);

    for (int i = 0; i < user_count; i++)
        delete[] AddressBook[i];

    return 0;
}

void displayMenu() {
    cout << "\n\n";
    cout << "1. Add a new contact" << endl;
    cout << "2. Update an existing contact" << endl;
    cout << "3. Delete a contact" << endl;
    cout << "4. List all added contacts in sorted order" << endl;
    cout << "5. Search for a given contact" << endl;
    cout << "6. Quit" << endl;
}

void displayAddressBook(string **AddressBook, const int user_count) {
    cout << "\n";
    for (int i = 0; i < user_count; i++) {
        cout << AddressBook[i][LAST_NAME] << ", " << AddressBook[i][FIRST_NAME] << ". " << AddressBook[i][TEL] << ". " << AddressBook[i][3] << "." << endl;
    }
    cout << "\n";
}

void addPerson(string **AddressBook, int &user_count) {

    AddressBook[user_count] = new string[NUM_FIELDS];

    // Fake Data For Testing
    // AddressBook[user_count][FIRST_NAME] = randFirstName();
    cout << "enter lastname ";
    cin >>lastnameInput;
    AddressBook[user_count][LAST_NAME] = lastnameInput;
    // randLastName();
    AddressBook[user_count][TEL] = "(" + to_string(rand()%(1000-100)+100) + ") " + to_string(rand()%(1000-100)+100) + "-" + to_string(rand()%(10000-1000)+1000);
    AddressBook[user_count][ADDR] = to_string(rand()%(1000-100)+100) + " " + randStreetName();

    //cout << "First name? ";
    //getline(cin, AddressBook[user_count][FIRST_NAME]);
    //cout << "Last name? ";
    //getline(cin, AddressBook[user_count][LAST_NAME]);
    //cout << "Phone number? ";
    //getline(cin, AddressBook[user_count][TEL]);
    //cout << "Address? ";
    //getline(cin, AddressBook[user_count][ADDR]);

    user_count++;
}


void sort(string **AddressBook, const int user_count) {
    for(int i=1;i<user_count; i++) {
        for(int j=0;j<(user_count-i); j++)
            if(AddressBook[j][LAST_NAME] > AddressBook[j+1][LAST_NAME]) {
                std::swap(AddressBook[j][LAST_NAME], AddressBook[j+1][LAST_NAME]);
            }
    }
}

void deleteContact(string **AddressBook, const int user_count) {
    int toPass;
    string temp[1][4];
    string lastname_Delete;
    cout << "Enter last name you want to delete: ";
    cin >> lastname_Delete;

    for (int i = 0; i < user_count; i++) {
        if(AddressBook[i][LAST_NAME] == lastname_Delete){
            toPass = i;
            cout << toPass;
        }
    }

    for(int i=toPass; i<user_count; i++) {
      for (int j=0; j<4;j++){
        temp[i][j] = AddressBook[i][j];
      }
      for (int j=0; j<4;j++){
        AddressBook[i][j] = AddressBook[i+1][j];
      }
      for (int j=0; j<4;j++){
        AddressBook[i+1][j] = temp[i][j];
      }
    }
    for(int i=0; i<user_count-1; i++) {
        cout << AddressBook[i][LAST_NAME] << ", " << AddressBook[i][FIRST_NAME] << ". " << AddressBook[i][TEL] << ". " << AddressBook[i][3] << "." << endl;
    }
}

string randLastName() {
    string lastNames[20] = {
        "Cooper",
        "Ingram",
        "Chapman",
        "Pacheco",
        "Pittman",
        "Orr",
        "Horton",
        "Payne",
        "Cooke",
        "Espinoza",
        "Arnold",
        "Mccoy",
        "Boyle",
        "Vaughan",
        "Clayton",
        "Washington",
        "Bennett",
        "Mooney",
        "Valencia",
        "Blankenship"
    };
    int randomIndex = rand()%20;
    return lastNames[randomIndex];
}
string randFirstName() {
    string firstNames[20] = {
        "Giada",
        "Darius",
        "Trevor",
        "Angela",
        "Tanya",
        "Josiah",
        "Carolyn",
        "Mariah",
        "Sanai",
        "Catalina",
        "Logan",
        "Baylee",
        "Abdiel",
        "Gage",
        "Salma",
        "Nora",
        "Tristian",
        "Maddison",
        "Haven",
        "Annie"
    };
    int randomIndex = rand()%20;
    return firstNames[randomIndex];
}
string randStreetName() {
    string streetNames[20] = {
        "Church Street",
        "Union Street",
        "Lake Street",
        "Holly Court",
        "9th Street",
        "Fieldstone Drive",
        "Oxford Court",
        "Mechanic Street",
        "Highland Avenue",
        "Linda Lane",
        "Prospect Avenue",
        "Cobblestone Court",
        "Valley Road",
        "North Avenue",
        "Primrose Lane",
        "Oak Street",
        "Maiden Lane",
        "Hudson Street",
        "Hillcrest Drive",
        "Elm Street"
    };
    int randomIndex = rand()%20;
    return streetNames[randomIndex];
}

void lowerCase (string &input){
  for(int i=0; i<input.length();i++){
    input[i]=tolower(input[i]);
  }
}
