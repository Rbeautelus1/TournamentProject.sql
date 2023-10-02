#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
using namespace std;


int main(void)
{
 
try {
 
    
 sql::Driver *driver;
 sql::Connection *con;
 sql::Statement *stmt;
 sql::ResultSet *res;
 sql::PreparedStatement  *prep_stmt;
    
 string firstname, lastname,instrument;
 int bornyear, musicianid;
 bool b;
    
 cout << "Firstname : ";
 cin >> firstname;
 
 cout << "Lastname : ";
 cin >> lastname;
 
 cout << "Instrument : ";
 cin >> instrument;
 
 cout << "Year of birth : ";
 cin >> bornyear;
 
 driver = get_driver_instance();
 
con = driver->connect("tcp://127.0.0.1:3306", "root", "");



 con->setSchema("music");
 
prep_stmt = con->prepareStatement("INSERT INTO musicians (firstname, lastname, born) " \
                                   "VALUES(?,?,?) ");
                                                                    
                                   
prep_stmt->setString(1, firstname);
prep_stmt->setString(2, lastname);
prep_stmt->setInt(3, bornyear);

prep_stmt->execute();

stmt = con->createStatement();

