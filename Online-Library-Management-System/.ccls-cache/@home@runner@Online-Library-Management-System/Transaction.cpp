#include "Transaction.h"
#include <iostream>
# include "User.h"
string Transaction::getTransactID(){
  return transactID;
} //returns transaction ID of book
string Transaction::getDateTime(){
  return dateTime;
} //returns date & time of book transaction
string Transaction::getTransactBooks(){
  return transactBooks;
} //returns transacted book
int Transaction::getUserID(){
  return userID;
} //returns id of user
//setters                
void Transaction::setTransactID(string transactID){ 
  this->transactID = transactID;
} //set transaction ID of book to str input
void Transaction::setDateTime(string dateTime){
  this->dateTime = dateTime;
} //set date & time of book to str input
void Transaction::setTransactBooks(string transactBooks){
  this->transactBooks = transactBooks;
} //returns transacted book
void Transaction::setUserID(int userId){
  this->userID = userId;
} //sets id of user to User input