#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "User.h"
#include "Admin.h"
#include "Transaction.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

class Library{
private:
  const string NAME;
  string userName;
  int numBooks; //
  int numUsers;  //
  int numAdmin;
  int bandwidth;

  //
  //vector<Book> books; // is a list of obj
  User users[20];
  Book books[20];
  Admin admin[20];

public:
  // constructor
  Library();
  
  void addBook(Book newbook); 
  void addUser(User newUser);
  void addAdmin(Admin newAdmin);
  
  void removeBook(Book*);
  void removeUser(User*);
  void removeAdmin(Admin*);
  
  
  User* searchUser(int, User); 
  Book* searchBook(string, Book);
  Admin* searchAdmin(int, Admin);
  
  string getName();
  int getNumBooks();
  int getBandwidth();
  int getAdminSizeL();
  void setNumBooks(int numBooks);
  void setBandwith(int bandwidth);
  void borrowBook(User* user, Book* book); 
  void returnBook(User* user, Book* book);
};
#endif