/*
 * File:   DatabaseConnector.h
 * Author: user
 *
 * Created on December 14, 2014, 11:38 AM
 */

#ifndef DATABASECONNECTOR_H
#define	DATABASECONNECTOR_H

/*
 *   Include directly the different
 *     headers from cppconn/ and mysql_driver.h + mysql_util.h
 *       (and mysql_connection.h). This will reduce your build time!
 *       */
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

class DatabaseConnector {
public:
    DatabaseConnector();
    DatabaseConnector(std::string hostName, std::string userName,
            std::string userPassword, std::string database);
    DatabaseConnector(const DatabaseConnector& orig);

    /** Returns a prepared statement pointer.*/
    sql::PreparedStatement * getPreparedStatement(std::string stmt);

    /** exectues the input query and returns true if it executed successfully.*/
    bool execute(std::string query);

    /** executes the input query and returns the resuls.*/
    sql::ResultSet* executeQuery(std::string query);

    virtual ~DatabaseConnector();

private:
    sql::Driver *driver;
    sql::Connection *con;

};

#endif	/* DATABASECONNECTOR_H */

