/*
 * File:   DatabaseConnector.cpp
 * Author: user
 *
 * Created on December 14, 2014, 11:38 AM
 */

#include "DatabaseConnector.h"
#include <sstream>
#include <string>

DatabaseConnector::DatabaseConnector() {}

DatabaseConnector::DatabaseConnector(std::string hostName, std::string userName,
        std::string userPassword, std::string database) {
    
    /* Create a connection */
    driver = get_driver_instance();

    /* Connect to the MySQL test database */
    con = driver->connect(hostName, userName, userPassword);

    /* Use the right database*/
    std::stringstream useQuery;
    useQuery << "USE " << database;

    execute(useQuery.str());
}

DatabaseConnector::DatabaseConnector(const DatabaseConnector& orig) {
}

DatabaseConnector::~DatabaseConnector() {
    delete con;
}

bool DatabaseConnector::execute(std::string query)
{ 
    sql::Statement *stmt = con->createStatement();
    return stmt->execute(query);
}

sql::ResultSet* DatabaseConnector::executeQuery(std::string query)
{
    sql::ResultSet* result;
    sql::Statement *stmt = con->createStatement();
    result = stmt->executeQuery(query);
    return result;
}
