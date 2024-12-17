#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book{

private:
  string title, genre, author;
  int size, IDnum;
  string availability;

public:
  Book();
  Book (string btitle, string bauthor, string bgenre, int bsize, int bIDnum, int bavailability);
//getters
  string getTitle(); //returns title of book
  string getGenre(); //returns genre of book
  string getAuthor(); //returns author of book
  string getAvailability(); //returns if book if available
  int getSize(); //returns size of book
  int getIDnum(); //returns unique id of book
//setters
  void setTitle(string); //sets title of book to string input
  void setGenre(string); //sets genre of book to string input
  void setAuthor(string); //sets author of book to string input
  void setAvailability(string); //sets availability of book to bool input
  void setSize(int); //sets size of book to int input
  void setIDnum(int); //sets id of book to id input

};
#endif