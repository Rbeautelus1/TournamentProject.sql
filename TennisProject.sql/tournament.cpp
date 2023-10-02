#include <stdlib.h>
#include <iostream>
/*
 Include directly the different
 headers from cppconn/ and mysql_driver.h + mysql_util.h
 (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
using namespace std;

// This program retrieves all of the musicians

// Compile:
// g++ -I/usr/include tournament.cpp -o tournament -I /usr/local/lib -lmysqlcppconn
// 
// Execute:
// ./tournament
// 
 sql::Driver *driver;
 sql::Connection *con;
 sql::Statement *stmt;
 sql::ResultSet *res;
 sql::PreparedStatement  *prep_stmt;


void findall();
void findbyid();
void insertPlayer();
void findbysponsor();
void updatePlayer();
void removePlayer();
void rankR();
void findbyStrings();

int main(void)
{

try {

   
 /* Create a connection */
 driver = get_driver_instance();

  
con = driver->connect("tcp://127.0.0.1:3306", "root", "");

/* Connect to the MySQL music database */
    
 con->setSchema("tournament");
 //stmt = con->createStatement();
    
 int option = 9;
 
 while (option != 8) {
     
     cout << endl;
     cout << "1. Add a player" << endl;
     cout << "2. Find a player by id" << endl;
     cout << "3. Find a player by Sponsor" << endl;
     cout << "4. Show all PlayerInfo" << endl;
     cout << "5. Update Player Rank" << endl;
     cout << "6. Delete Player" << endl;
     cout << "7. Find a players national Rank and record by their id" << endl;
     cout << "8. Find Rakcet and Racket size by string type" << endl;
     cout << "9. Exit" << endl << endl;
     
     cout << "Choice : ";
     cin >> option;
     
     switch(option) {

         case 1: insertPlayer();
                break;
        
         case 2: findbyid();
                 break;
        case 3: findbysponsor();
                break;
        case 4  : findall();
                 break;
        case 5 :  updatePlayer();
              break;
        case 6:  removePlayer();
                break;
        case 7: rankR();
                break;
        case 8: findbyStrings();
                break;
             
     }
 }
 

 delete res;
 delete stmt;
 delete con;
} catch (sql::SQLException &e) {
 cout << "# ERR: SQLException in " << __FILE__;
 cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
 cout << "# ERR: " << e.what();
 cout << " (MySQL error code: " << e.getErrorCode();
 cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}
cout << endl;
return EXIT_SUCCESS;

}

 void findall() 
 {
     
 stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from PlayerInfo");
    
 while (res->next()) 
 {
 
 /* Access column data by alias or column name */
     
     cout << res->getString("Player_Id") << " ";
     cout << res->getString("Fname") << " ";
     cout << res->getString("Lname") << " ";
     cout << res->getString("Country") << endl;
     cout << res->getString("Academy") << endl;
     cout << res->getString("Sponsor") << endl;


 
 }
     
 }


void findbyid() 
{
     
 int Player_Id;
    
 cout << "Enter the Player_Id : ";
 cin >> Player_Id;
    
 
prep_stmt = con->prepareStatement("SELECT * FROM PlayerInfo WHERE Player_Id = ?");
prep_stmt->setInt(1, Player_Id);
res = prep_stmt->executeQuery();


 while (res->next()) 
 {

 /* Access column data by alias or column name */
     
     cout << res->getString("Player_Id") << " ";
     cout << res->getString("Fname") << " ";
     cout << res->getString("Lname") << " ";
     cout << res->getString("Country") << endl;
     cout << res->getString("Academy") << endl;
     cout << res->getString("Sponsor") << endl;
 
 }
}

void findbyStrings()
{
     
string StringType;
    
 cout << "Enter the players StringType : ";
 cin >> StringType;
    
 
prep_stmt = con->prepareStatement("select StringType, NameofRacket, Size from Racket where StringType = ? and Size < 98");
prep_stmt->setString(1, StringType);
res = prep_stmt->executeQuery();


 while (res->next()) 
 {

 /* Access column data by alias or column name */
     
     cout << res->getString("StringType") << " ";
     cout << res->getString("NameofRacket") << " ";
     cout << res->getInt("Size") << " ";
     
 
 }
}


void findbysponsor()
{
    string Sponsor;
    
    cout << "Enter the Sponsor name: ";
    cin >> Sponsor;

    prep_stmt = con->prepareStatement("SELECT * FROM PlayerInfo WHERE Sponsor = ?");
prep_stmt->setString(1,Sponsor);
res = prep_stmt->executeQuery();


 while (res->next()) 
 {

 /* Access column data by alias or column name */
     
     cout << res->getString("Player_Id") << " ";
     cout << res->getString("Fname") << " ";
     cout << res->getString("Lname") << " ";
     cout << res->getString("Country") << endl;
     cout << res->getString("Academy") << endl;
     cout << res->getString("Sponsor") << endl;
 
 }

}


void rankR()
{
     
 int Player_Id;
    
 cout << "Enter the Player_Id : ";
 cin >> Player_Id;
    
 
prep_stmt = con->prepareStatement("SELECT Player_Id, national, wins, losses, forfeits FROM Rank join Record using (Player_Id) where Player_Id = ?");
prep_stmt->setInt(1, Player_Id);
res = prep_stmt->executeQuery();


 while (res->next()) 
 {

 /* Access column data by alias or column name */
     
     cout << res->getInt("Player_Id") << " ";
     cout << res->getString("national") << " ";
     cout << res->getInt("wins") << " ";
     cout << res->getInt("losses") << " ";
     cout << res->getInt("forfeits") << " ";
    
 
 }
}


void insertPlayer()
{
    string Fname, Lname,Country,Academy,Sponsor;
 int Player_Id;
 bool b;
    
cout << "Player ID : ";
cin >> Player_Id;

 cout << "Firstname : ";
 cin >> Fname;
 
 cout << "Lastname : ";
 cin >> Lname;
 
 cout << "Country : ";
 cin >> Country;
 
 cout << "Academy : ";
 cin >> Academy;

 cout << "Sponsor : ";
 cin >> Sponsor;

 con->setSchema("tournament");
 
prep_stmt = con->prepareStatement("INSERT INTO PlayerInfo (Player_Id,Fname, Lname, Country,Academy, Sponsor) " \
                                   "VALUES(?,?,?,?,?,?) ");
                                                                    
                                   
prep_stmt->setInt(1, Player_Id);
prep_stmt->setString(2, Fname);
prep_stmt->setString(3, Lname);
prep_stmt->setString(4, Country);
prep_stmt->setString(5, Academy);
prep_stmt->setString(6, Sponsor);

prep_stmt->execute();

cout << "New Player added!" << endl;

//stmt = con->createStatement();
}


void updatePlayer()
{
  int Player_Id, international;
  cout << "Please enter the Player_Id : ";
  cin >> Player_Id;
  cout << "Enter their new International Rank: ";
  cin >> international;
 
  prep_stmt = con->prepareStatement("UPDATE Rank " \
                                   "SET international = ? WHERE Player_Id = ?");
  prep_stmt->setInt(1, international);
  prep_stmt->setInt(2, Player_Id);
 
  prep_stmt->execute();
 
  cout << "\n Player international number updated!" << endl;
}
 

void removePlayer()
{
  int Player_Id;
 
  cout << "Please enter the Player_Id that you want to remove:";
  cin >> Player_Id;
  cout << "\n\n";
 
  prep_stmt = con->prepareStatement("DELETE FROM PlayerInfo " \
                                   "WHERE Player_Id = ?");
  prep_stmt->setInt(1, Player_Id);
 
  prep_stmt->execute();
 
  cout << "Player removed!\n";
}
 
