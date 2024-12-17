#include "Library.h"
#include "Book.h"
#include "User.h"
#include "Admin.h"
#include "Transaction.h"
#include <fstream>
#include <iostream>
#include <string>

Library::Library(){
  userName = "";
  numBooks = 0;
  numUsers = 0; 
  numAdmin = 1;
  bandwidth = 0;
}
//add book
void Library::addBook(Book newBook){
  books[numBooks] = newBook;
  numBooks++;
} 
//remove book
void Library::removeBook(Book* remBook){
  remBook = nullptr; 
  numBooks--;
}
//add user
void Library::addUser(User newUser){
  users[numUsers] = newUser;
  numUsers++;
}
//remove user
void Library::removeUser(User* remUser){
  remUser = nullptr;
  numUsers--;
}
//add admin
void Library::addAdmin(Admin newAdmin){
  numAdmin++;
  admin[numAdmin-1] = newAdmin;
  admin->setAdminSize(numAdmin);
}
//remove admin
void Library::removeAdmin(Admin* remAdmin){
  numAdmin--;
  admin->setAdminSize(numAdmin);
}
//get admin array size
int Library::getAdminSizeL(){
  return numAdmin;
}

//finds book in book array
Book* Library::searchBook(string title, Book bookList){
  for (int i = 0; i < 20; i++){
      if (books[i].getTitle() == title){
        return &books[i];
      }
    }
  return nullptr;
}
//finds user in user array
User* Library::searchUser(int id, User userList){
  for (int i = 0; i < 20; i++){
      if (users[i].getIDnum() == id){
        return &users[i];
      }
    }
  return nullptr;
}
//finds admin in admin array
Admin* Library::searchAdmin(int id, Admin adminList){
  for (int i = 0; i < 20; i++){
      if (admin[i].getadminID() == id){
        return &admin[i];
      }
  }
  return nullptr;
}
//get name of library
string Library::getName(){
  return NAME;
}
//get number of books of library
int Library::getNumBooks(){
  return numBooks;
}
//get bandwidth of library
int Library::getBandwidth(){
  return bandwidth;
}
//sets number of books
void Library::setNumBooks(int numBooks){
  this->numBooks = numBooks;
}
//sets bandwidth
void Library::setBandwith(int bandwidth){
  this->bandwidth = bandwidth;
}
//adds to transaction and date time when borrowing book
void Library::borrowBook(User* user, Book* book) {
  Transaction transaction;
  time_t now = time(0);
  transaction.setDateTime(ctime(&now)); 
  transaction.setTransactBooks(book->getTitle());
  transaction.setUserID(user->getIDnum());

  string transactionFinal = user->getTransactions() + ", " + transaction.getDateTime(); 
  user->setTransactions(transactionFinal);

  book->setAvailability("N");

  cout << "Date & Time: " << transaction.getDateTime() << endl;
}

//adds to transaction and date time when returning book
void Library::returnBook(User* user, Book* book) {
  Transaction transaction;
  time_t now = time(0);
  transaction.setDateTime(ctime(&now)); 
  transaction.setTransactBooks(book->getTitle());
  transaction.setUserID(user->getIDnum());

  string transactionFinal = user->getTransactions() + ", " + transaction.getDateTime(); 
  user->setTransactions(transactionFinal);

  book->setAvailability("Y");

  cout << "Date & Time: " << transaction.getDateTime() << endl;
}