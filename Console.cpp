#include "Console.h"

bool sqlExecute(string sqlTemp, sqlite3* db) {
	char sql[200];
	strcpy_s(sql, sqlTemp.c_str());
	char* zErrMsg = 0;
	int res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res == SQLITE_OK) {
		cout << "success";
		return true;
	} else {
		cout << "fail:" << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		return false;
	}
}

Console::Console() {
	int res = sqlite3_open("test.db", &db);
	if (res != SQLITE_OK) {
		cout << "fail!" << sqlite3_errmsg(db) << endl;
	} else {
		cout << "success" << endl;
	}
}

vector<Book> Console::searchBook(map<string, string> type) {
	vector<Book> result;
	ostringstream ostr1;
	ostr1 << "SELECT Name, Author, Publisher, BookId FROM Book";
	if (!type.empty()) {
		ostr1 << " WHERE";
		map<string, string>::iterator iter = type.begin();
		ostr1 << " " << iter->first << " = '" << iter->second;
		iter ++;
		while (iter != type.end()) {
			ostr1 << "', " << iter->first << " = '" << iter->second;
			iter ++;
		}
		ostr1 << "';";
	}
	string name;
	string author;
	string publisher;
	int bookId;
	string temp = ostr1.str();
	char* errmsg;
	char** pResult;
	int nRow;
	int nCol;
	int nResult = sqlite3_get_table(db, ostr1.str().c_str(), &pResult, &nRow, &nCol, &errmsg);
	if (nResult != SQLITE_OK) {
		sqlite3_close(db);
		cout << errmsg << endl;
		sqlite3_free(errmsg);
		return result;
	}
	int index = nCol;
	for (int i = 0; i < nRow; i++) {
		name = pResult[index];
		index++;
		author = pResult[index];
		index++;
		publisher = pResult[index];
		index++;
		bookId = atoi(pResult[index]);
		index++;
		result.push_back(Book(name, author, publisher, bookId));
	}
	return result;
}

bool Console::addBook(Book book) {
	ostringstream ostr1;
	ostr1 << "INSERT INTO BOOK VALUES ('" << book.getName() << "', '"
		<< book.getAuthor() << "', '" << book.getPublisher() << "', " << book.getBookId() << ");";
	string temp = ostr1.str();
	return sqlExecute(temp, db);

}

bool Console::updateBook(Book book) {
	ostringstream ostr1;
	ostr1 << "UPDATE Book SET Name =  '" << book.getName() << "', Author = '" 
		<< book.getAuthor() << "', Publisher = '" << book.getPublisher() << "' WHERE bookId = " << book.getBookId() << ";";
	string temp = ostr1.str();
	return sqlExecute(temp, db);
}

