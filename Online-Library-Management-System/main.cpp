#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "Transaction.h"
#include "Admin.h"
#include "Library.h"
#include "Book.h"
//download the video if the quality is not clear :)

using namespace std;

int main() {
  Library* library = new Library();
  //read in user.txt
  string tempUserName, tempUserStatus, tempUserTransactions;
  int tempUserBalance, tempUserID, tempUserLoyalty;
  ifstream input("user.txt");
  if (!input.is_open()) {
    cerr << "File not found! user" << endl;
    exit(1);
  }
  //load user file into user array
  User* user = new User[20];
  for (int i = 0; i < 20; i++) {
    input >> tempUserName;
    input.ignore();
    getline(input, tempUserStatus);
    getline(input, tempUserTransactions);
    input >> tempUserBalance;
    input >> tempUserID;
    input >> tempUserLoyalty;
    input.ignore();
    user[i].setName(tempUserName); 
    user[i].setStatus(tempUserStatus);
    user[i].setTransactions(tempUserTransactions);
    user[i].setBalance(tempUserBalance);
    user[i].setIDnum(tempUserID);
    user[i].setLoyalty(tempUserLoyalty);
    library->addUser(user[i]);
  }
  
  //read in admin.txt
  string tempAdminName;
  int tempAdminID, tempSalary, tempYrsWork;
  ifstream inputA("admin.txt");
  if (!inputA.is_open()) {
    cerr << "File not found! admin" << endl;
    exit(1);
  }
  //load admin file into admin array
  Admin* admin = new Admin[20];
  for (int i = 0; i < 5; i++) {
    getline(inputA, tempAdminName);
    inputA >> tempAdminID;
    inputA >> tempYrsWork;
    inputA >> tempSalary;
    inputA.ignore();
    
    admin[i].setName(tempAdminName); 
    admin[i].setSalary(tempSalary);
    admin[i].setYrsWork(tempYrsWork);
    admin[i].setadminID(tempAdminID);
    library->addAdmin(admin[i]);
  }

  //read in book.txt
  Book* book = new Book[20];
  string tempTitle, tempGenre, tempAuthor, tempAvailability;
  int tempSize, tempIDnum;
  ifstream inputB("books.txt"); 
  if (!inputB.is_open()) {
    cerr << "File not found! book" << endl;
    exit(1);
  }
  //load book file into book array
  for (int i = 0; i < 20; i++) {
    getline(inputB, tempTitle);
    getline(inputB, tempAuthor);
    getline(inputB, tempGenre);
    inputB >> tempSize;
    inputB >> tempIDnum;
    inputB >> tempAvailability;
    inputB.ignore(); 
    book[i].setTitle(tempTitle); 
    book[i].setAuthor(tempAuthor);
    book[i].setGenre(tempGenre);
    book[i].setSize(tempSize);
    book[i].setIDnum(tempIDnum);
    book[i].setAvailability(tempAvailability);
    library->addBook(book[i]);
  }

  //output file 
  ofstream fout; // Output file stream

   // Open file
  fout.open("outfile.txt");

   if (!fout.is_open()) {
      cout << "Could not open file outfile.txt." << endl;
      return 1;
   }
  
  cout << "WELCOME TO THE RED PLANET LIBRARY"<< endl;
  cout << "--------------------------------------"<< endl;
  cout << "             _____" << endl;
  cout << "         ,-:` \\,',`'-, " << endl;
  cout << "       .'-;_,;  ':-;_,'."<< endl;
  cout << "      /;   '/    ,  _`.-\\"<< endl;
  cout << "     | '`. (`     /` ` \\`|"<< endl;
  cout << "     |:.  `\\`-.   \\_   / |"<< endl;
  cout << "     |     (   `,  .`\\ ;'|"<< endl;
  cout << "      \\     | .'     `-'/"<< endl;
  cout << "       `.   ;/        .'"<< endl;
  cout <<"          `'-._____."<< endl;
  cout << "             -----"<< endl;
  cout << "             |   |"<< endl;
  cout << "             |   |"<< endl;
  cout << "            --   --"<< endl;
  cout << "            \\     /"<< endl;
  cout << "             \\   /"<< endl;
  cout << "              \\ /"<< endl;
  cout << "               V"<< endl;
  cout << "           ___---___" << endl;        
  cout << "        .--         --." << endl;    
  cout << "      ./   ()      .-. \\." << endl;
  cout << "     /            (   )  \\" << endl;
  cout << "   | ()       0    ._.  .  |" << endl;
  cout << "  |                         |" << endl;     
  cout << "  |                         |" << endl;
  cout << "  |       .--.              |" << endl;
  cout << "   | .   |    |            |" << endl;
  cout << "    \\    `._-'        .   /" << endl;   
  cout << "     `\\  o    ()         /" << endl;    
  cout << "        `--___    ___--'" << endl;
  cout << "              --- " << endl;
  cout << "--------------------------------------"<< endl << endl;

  
  int num = 0;
  cout <<  endl << "Please select 1 for User and 2 for Admin" << endl;
  cin >> num;
  int id = 0; //asking id to know which user/admin
  
  if (num == 1){
    cout << endl <<  "Please enter User ID:" << endl;
    cin >> id;

    //finds user using user id 
    User tempUser;
    tempUser.setIDnum(id);
    User* currUser = library->searchUser(id, tempUser);
    //notifies user of reward
    if (currUser->getLoyalty() > 1){
      cout <<  endl << "You have a notification!" << endl;
      currUser->printRewards();
    }
    string choice = "";
    while (choice != "f"){
      //menu
      cout << endl <<  "Choose: " << endl;
      cout << "a.	Borrow Book" << endl;
      cout << "b.	Return Book" << endl;
      cout << "c.	View Loyalty Tier" << endl;
      cout << "d.	View Transaction Report" << endl;
      cout << "e.	View Balance" << endl;
      cout << "f.	Exit" << endl;
      cin >> choice;
      if (choice == "f")
        exit(-1);
      //borrow book
        if (choice == "a") {
            cout << endl << "Borrow: Type in book title:" << endl;
            string title = "";
            cin.ignore();
            getline(cin, title);

            Book tempBook;
            tempBook.setTitle(title);
            Book* currBook = library->searchBook(title, tempBook);
            if (currBook != nullptr) {
                if (currBook->getAvailability() == "Y") {
                    cout << currBook->getTitle() << " written by " << currBook->getAuthor() << " in " << currBook->getGenre() << " being borrowed..." << endl;
                    library->borrowBook(currUser, currBook); // Borrow book and print transaction details

                  string transactionFinal = currUser->getTransactions() + ", " + currBook->getTitle();
                  currUser->setTransactions(transactionFinal);
                  currBook->setAvailability("N");
                  currUser->setBalance(currUser->getBalance()+1);
                  fout << currUser->getName() << "'s transaction report: " << endl << "Transactions: " << currUser->getTransactions() << endl << "Balance: " << currUser->getBalance() << endl;

                } else {
                    cout << "Sorry, this book is not available." << endl;
                }
            } else {
                cout << "Book not found." << endl;
            }
          //return book
        } else if (choice == "b") {
            cout << endl << "Return: Type in book title:" << endl;
            string title = "";
            cin.ignore();
            getline(cin, title);

            Book tempBook;
            tempBook.setTitle(title);
            Book* currBook = library->searchBook(title, tempBook);
            if (currBook != nullptr) {
                cout << currBook->getTitle() << " written by " << currBook->getAuthor() << " in " << currBook->getGenre() << " being returned..." << endl;
                library->returnBook(currUser, currBook); // Return book and print transaction details
              currUser->setBalance(currUser->getBalance()-1);
              fout << currUser->getName() << "'s transaction report: " << endl << "Transactions: " << currUser->getTransactions() << endl << "Balance: " << currUser->getBalance() << endl;
              currBook->setAvailability("Y");
            } 
            else {
                cout << "Book not found." << endl;
            }
        }

      //get loyalty of user
      else if (choice == "c"){
        cout << endl << currUser->getLoyalty() << endl;
        currUser->printRewards();
      }
      //print Transaction Report of user
      else if (choice == "d"){
        cout << endl;
        currUser->printTransactionReport();
      }
      //print balance of user
      else if (choice == "e"){
        cout << currUser->getBalance() << endl; 
      }
    }
  }
  else if (num == 2){
    //admin id, creates admin object using id
    cout <<  endl << "Please enter Admin ID:" << endl;
    cin >> id;
    Admin tempAdmin;
    tempAdmin.setadminID(id); 
    Admin* currAdmin = library->searchAdmin(id, tempAdmin);
    string choice = "";
    //menu
    cout <<  endl << "Choose: " << endl;
    cout << "a.	Add worker" << endl;
    cout << "b.	Remove worker" << endl;
    cout << "c.	Reward worker" << endl;
    cout << "d.	View Salary" << endl;
    cout << "e.	Exit" << endl;
    while (choice != "e"){
      cin >> choice;
      if (choice == "e")
        exit(-1);
      //add worker
      if (choice == "a"){
        cout <<  endl << "Add: Type in worker name:" << endl;
        string nameW = "";
        cin >> nameW;
        cin.ignore();
        cout << "Add: Type in worker ID:" << endl;
        int idN = 0;
        cin >> idN;
        int salaryW = 0;
        cout << "Add: Type in salary:" << endl;
        cin >> salaryW;
        int sizeAdmin = library->getAdminSizeL();
        admin[sizeAdmin-1].setName(nameW); 
        admin[sizeAdmin-1].setSalary(salaryW);
        admin[sizeAdmin-1].setYrsWork(0);
        admin[sizeAdmin-1].setadminID(idN);
        library->addAdmin(admin[sizeAdmin-1]);
        cout << admin[sizeAdmin-1].getName() << " added!" << endl;
        fout << currAdmin->getName() << "'s report: " << endl << "Added: " << nameW << endl << "ID: " << idN << endl << "Salary: " << salaryW << endl;
      }
        //remove worker
      else if (choice == "b"){
        cout <<  endl << "Remove: Type in worker ID:" << endl;
        int idRem = 0;
        cin >> idRem;
        Admin* remAdmin = library->searchAdmin(idRem, tempAdmin);
        library->removeAdmin(remAdmin); //create new array?
        int ind = 0;
        for (int i = 0; i < 20; i++){
          if (admin[i].getadminID() == remAdmin->getadminID()){
            ind = i;
          }
        }
        cout << admin[ind].getName() << " removed!" << endl;
        fout << currAdmin->getName() << "'s report: " << endl << "Removed: " << remAdmin->getName() << endl << "ID: " << remAdmin->getadminID() << endl << "Salary: " << remAdmin->getSalary() << endl;
        admin[ind].setName("");
        admin[ind].setadminID(0);
        admin[ind].setYrsWork(0);
        admin[ind].setSalary(0);
      }
      //reward ANOTHER worker
      if (choice == "c"){
        cout <<  endl << "Who would you like to reward? (ID)" << endl;
        int idRewardAd = 0;
        cin >> idRewardAd;
        Admin tempAdmin;
        tempAdmin.setadminID(id);
        Admin* rewardAdmin = library->searchAdmin(idRewardAd, tempAdmin);
         rewardAdmin->printReward();

      }
      //get salary of admin
      else if (choice == "d")
        cout << "Salary: " << currAdmin->getSalary() << endl;
      cout << endl << "Choose: " << endl;
      cout << "a.	Add worker" << endl;
      cout << "b.	Remove worker" << endl;
      cout << "c.	Reward worker" << endl;
      cout << "d.	View Salary" << endl;
      cout << "e.	Exit" << endl;
    }
  }
  //destructors
  delete[] user;
  delete[] book;
  delete[] admin;
  
}