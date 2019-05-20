//
// Copyright [2019] <Copyright Qiyang Ding>
//

#include "Console.h"
#include <vector>
#include <map>
#include <string>

// Execute the sql sentences
bool sqlExecute(string sqlTemp, sqlite3* db) {
  char* zErrMsg = 0;
  int res = sqlite3_exec(db, sqlTemp.c_str(), 0, 0, &zErrMsg);
  if (res == SQLITE_OK) {
    cout << "success" << endl;
    return true;
  } else {
    cout << "fail:" << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    return false;
  }
}

// Get specfic dates
string getDueTime() {
  // %H:%M:%S
  time_t second;
  time(&second);
  second += 3600 * 24 * 30;
  tm localTm;
  localtime_s(&localTm, &second);

  char localTimeStr[128] = {0};
  strftime(localTimeStr, sizeof(localTimeStr), "%F", &localTm);

  return localTimeStr;
}

// Open the sqlite3
Console::Console() {
  int res = sqlite3_open("test.db", &db);
  if (res != SQLITE_OK) {
    cout << "fail!" << sqlite3_errmsg(db) << endl;
  } else {
    cout << "success" << endl;
  } 
}

// Login the system (Username should be unique)
User Console::login(string username, string password) {
  ostringstream ostr1;
  ostr1 << "SELECT Id, Name, Gender, bookBorrow, bookReserve, Permission FROM "
           "User WHERE "
        << "Username = '" << username << "' AND Password = '" << password
        << "';";
  int id = 0;
  string name;
  string gender;
  int permission = 0;
  int booknumber = 0;
  int Reservenumber = 0;
  char* errmsg;
  char** pResult;
  int nRow;
  int nCol;
  int nResult = sqlite3_get_table(db, ostr1.str().c_str(), &pResult, &nRow,
                                  &nCol, &errmsg);
  if (nResult != SQLITE_OK) {
    // sqlite3_close(db);
    cout << errmsg << endl;
    sqlite3_free(errmsg);
    return User();
  }
  if (nRow == 0) {
    return User();
  }
  int index = nCol;
  id = atoi(pResult[index]);
  index++;
  name = pResult[index];
  index++;
  gender = pResult[index];
  index++;
  booknumber = atoi(pResult[index]);
  index++;
  Reservenumber = atoi(pResult[index]);
  index++;
  permission = atoi(pResult[index]);
  index++;
  switch (permission) {
    case 1:
      return Admin(id, name, gender, booknumber, Reservenumber);
    case 2:
      return Student(id, name, gender, booknumber, Reservenumber);
    case 3:
      return Staff(id, name, gender, booknumber, Reservenumber);
    default:
      return User();
  }
}

// Search the books from database (Name should be the first)
vector<Book> Console::searchBook(map<string, string> type) {
  vector<Book> result;
  ostringstream ostr1;
  ostr1 << "SELECT Name, Isbn, Author, Publisher, BookId, BookCondition, "
           "dueTime, Price, ReserveId FROM Book";
  if (!type.empty()) {
    ostr1 << " WHERE";
    map<string, string>::iterator iter = type.begin();
    ostr1 << " " << iter->first << " LIKE '%" << iter->second << "%";
    iter++;
    while (iter != type.end()) {
      ostr1 << "'AND " << iter->first << " LIKE '%" << iter->second << "%";
      iter++;
    }
    ostr1 << "';";
  }
  string name;
  string author;
  string publisher;
  string isbn;
  double price;
  int bookId;
  int reserveid;
  string bookCondition;
  string dueTime;
  string temp = ostr1.str();
  char* errmsg;
  char** pResult;
  int nRow;
  int nCol;
  int nResult = sqlite3_get_table(db, ostr1.str().c_str(), &pResult, &nRow,
                                  &nCol, &errmsg);
  if (nResult != SQLITE_OK) {
    // sqlite3_close(db);
    cout << errmsg << endl;
    sqlite3_free(errmsg);
    return result;
  }
  int index = nCol;
  for (int i = 0; i < nRow; i++) {
    name = pResult[index];
    index++;
    isbn = pResult[index];
    index++;
    author = pResult[index];
    index++;
    publisher = pResult[index];
    index++;
    bookId = atoi(pResult[index]);
    index++;
    bookCondition = pResult[index];
    index++;
    dueTime = pResult[index];
    index++;
    price = atof(pResult[index]);
    index++;
    reserveid = atoi(pResult[index]);
    index++;
    result.push_back(Book(name, isbn, author, publisher, bookCondition, price,
                          bookId, dueTime, reserveid));
  }
  return result;
}

vector<User> Console::searchUser(map<string, string> type) {
  vector<User> result;
  ostringstream ostr1;
  ostr1 << "SELECT Id, Name, Gender, bookBorrow, bookReserve FROM User";
  if (!type.empty()) {
    ostr1 << " WHERE";
    map<string, string>::iterator iter = type.begin();
    ostr1 << " " << iter->first << " LIKE '%" << iter->second << "%";
    iter++;
    while (iter != type.end()) {
      ostr1 << "'AND " << iter->first << " LIKE '%" << iter->second << "%";
      iter++;
    }
    ostr1 << "';";
  }
  string name;
  int id;
  string gender;
  int booknumber;
  int bookReserve;
  string temp = ostr1.str();
  char* errmsg;
  char** pResult;
  int nRow;
  int nCol;
  int nResult = sqlite3_get_table(db, ostr1.str().c_str(), &pResult, &nRow,
                                  &nCol, &errmsg);
  if (nResult != SQLITE_OK) {
    // sqlite3_close(db);
    cout << errmsg << endl;
    sqlite3_free(errmsg);
    return result;
  }
  int index = nCol;
  for (int i = 0; i < nRow; i++) {
    id = atoi(pResult[index]);
    index++;
    name = pResult[index];
    index++;
    gender = pResult[index];
    index++;
    booknumber = atoi(pResult[index]);
    index++;
    bookReserve = atoi(pResult[index]);
    index++;
    result.push_back(User(id, name, gender, booknumber, bookReserve));
  }
  return result;
}

// Add the book to the database
bool Console::addBook(Book book) {
  ostringstream ostr1;
  ostr1 << "INSERT INTO BOOK VALUES (null, '" << book.getName() << "', '"
        << book.getAuthor() << "', '" << book.getPublisher() << "', '"
        << book.getBookCondition() << "', 0, '0', " << book.getPrice() << ", 0"
        << ", '" << book.getIsbn() << "');";
  return sqlExecute(ostr1.str(), db);
}

// Add the user to the database
bool Console::addUser(User user, string username, string password) {
  ostringstream ostr1;
  ostr1 << "INSERT INTO User VALUES (" << user.getId() << ", '"
        << user.getName() << "', '" << user.getGender() << "', '" << username
        << "', '" << password << "', 0, 0, " << user.getPermission() << ");";
  return sqlExecute(ostr1.str(), db);
}

// Update the user in the database
bool Console::updateUser(User user) {
  ostringstream ostr1;
  ostr1 << "UPDATE User SET Name = '" << user.getName() << "', Gender = '"
        << user.getGender() << "' WHERE Id = " << user.getId() << ";";
  return sqlExecute(ostr1.str(), db);
}

// Update the book in the database
bool Console::updateBook(Book book) {
  ostringstream ostr1;
  ostr1 << "UPDATE Book SET Name =  '" << book.getName() << "', Isbn = '"
        << book.getIsbn() << "', Author = '" << book.getAuthor()
        << "', Publisher = '" << book.getPublisher()
        << "', Price = " << book.getPrice()
        << " WHERE bookId = " << book.getBookId() << ";";
  return sqlExecute(ostr1.str(), db);
}

// User borrow the book (dueTime was next month 28)
bool Console::borrowBook(Book book, User user) {
  if (user.isFull()) {
    return false;
  }
  ostringstream ostr1;
  ostr1 << "SELECT * FROM Book WHERE BookId = " << book.getBookId()
        << " AND BookCondition = '"
        << "Stored' AND (ReserveId = " << user.getId() << " OR ReserveId = 0);";
  char* errmsg;
  char** pResult;
  int nRow;
  int nCol;
  int nResult = sqlite3_get_table(db, ostr1.str().c_str(), &pResult, &nRow,
                                  &nCol, &errmsg);
  if (nResult != SQLITE_OK) {
    // sqlite3_close(db);
    cout << errmsg << endl;
    sqlite3_free(errmsg);
    return false;
  }
  if (nRow == 0) {
    return false;
  }
  ostr1.str("");
  ostr1 << "UPDATE User SET bookReserve = bookReserve - 1 WHERE User.Id = "
           "(SELECT ReserveId FROM Book WHERE Book.bookId = "
        << book.getBookId() << " AND ReserveId != 0); ";
  sqlExecute(ostr1.str(), db);
  ostr1.str("");
  ostr1 << "UPDATE Book SET bookCondition =  'On loan-due', borrowId = "
        << user.getId() << ", dueTime = '" << getDueTime()
        << "', ReserveId = 0 WHERE bookId = " << book.getBookId() << ";";
  sqlExecute(ostr1.str(), db);
  ostr1.str("");
  ostr1 << "UPDATE User SET bookBorrow = '" << user.getBookBorrow() + 1
        << "' WHERE Id = " << user.getId() << ";";
  sqlExecute(ostr1.str(), db);
  return true;
}

bool Console::returnBook(Book book) {
  ostringstream ostr1;
  ostr1 << "SELECT * FROM Book WHERE BookId = " << book.getBookId()
        << " AND BookCondition = '"
        << "On loan-due';";
  char* errmsg;
  char** pResult;
  int nRow;
  int nCol;
  int nResult = sqlite3_get_table(db, ostr1.str().c_str(), &pResult, &nRow,
                                  &nCol, &errmsg);
  if (nResult != SQLITE_OK) {
    // sqlite3_close(db);
    cout << errmsg << endl;
    sqlite3_free(errmsg);
    return false;
  }
  if (nRow == 0) {
    return false;
  }
  ostr1.str("");
  ostr1 << "UPDATE User SET bookBorrow = bookBorrow - 1"
           "WHERE User.Id = (SELECT borrowId FROM Book WHERE Book.bookId = "
        << book.getBookId() << ");";
  sqlExecute(ostr1.str(), db);
  ostr1.str("");
  ostr1 << "UPDATE Book SET bookCondition =  'Stored', borrowId = 0,"
           "dueTime = '0' WHERE bookId = "
        << book.getBookId() << ";";
  sqlExecute(ostr1.str(), db);
  return true;
}

// Delete the book
bool Console::deleteBook(Book book) {
  ostringstream ostr1;
  ostr1 << "DELETE FROM Book WHERE BookId = " << book.getBookId() << ";";
  return sqlExecute(ostr1.str(), db);
}

// Delete the user
bool Console::deleteUser(Book book) {
  ostringstream ostr1;
  ostr1 << "DELETE FROM User WHERE Id = " << book.getBookId() << ";";
  return sqlExecute(ostr1.str(), db);
}

bool Console::bookReserve(Book book, User user) {
  if (user.isFullReserve()) {
    return false;
  }
  ostringstream ostr1;
  ostr1 << "SELECT * FROM Book WHERE BookId = " << book.getBookId()
        << " AND BookCondition = '"
        << "On loan-due' AND BorrowId != " << user.getId()
        << " AND ReserveId = 0"
        << ";";
  char* errmsg;
  char** pResult;
  int nRow;
  int nCol;
  int nResult = sqlite3_get_table(db, ostr1.str().c_str(), &pResult, &nRow,
                                  &nCol, &errmsg);
  if (nResult != SQLITE_OK) {
    // sqlite3_close(db);
    cout << errmsg << endl;
    sqlite3_free(errmsg);
    return false;
  }
  if (nRow == 0) {
    return false;
  }
  ostr1.str("");
  ostr1 << "UPDATE User SET bookReserve = bookReserve + 1 WHERE User.Id = "
        << user.getId() << ";";
  sqlExecute(ostr1.str(), db);
  ostr1.str("");
  ostr1 << "UPDATE Book SET ReserveId =  " << user.getId()
        << " WHERE bookId = " << book.getBookId() << ";";
  sqlExecute(ostr1.str(), db);
  return true;
}

// It should be call before returning the book
int Console::getFine(Book book) {
  time_t t2;
  time_t t1;
  time(&t2);
  tm tm_t;
  int year;
  int month;
  int day;
  sscanf_s(book.getBorrowTime().c_str(), "%4d-%2d-%2d", &year, &month, &day);
  tm_t.tm_year = year - 1900;
  tm_t.tm_mon = month - 1;
  tm_t.tm_mday = day;
  tm_t.tm_hour = 0;
  tm_t.tm_min = 0;
  tm_t.tm_sec = 0;
  tm_t.tm_isdst = 0;
  t1 = mktime(&tm_t);
  double temp = difftime(t2, t1);
  if (temp > 0) {
    int64_t daysecond = 3600 * 24;
    int64_t temp2 = (int64_t)(temp / daysecond) - 30;
    if (temp2 > (int64_t)book.getPrice()) {
      return book.getPrice();
    } else {
      return temp2;
    }

  } else {
    return 0;
  }
}

// Exit the system
void Console::exit() { sqlite3_close(db); }
