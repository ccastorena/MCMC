/* 
 * File:   MCMCDataseConnector.cpp
 * Author: user
 * 
 * Created on December 21, 2014, 1:26 PM
 */

#include "MCMCDatabaseConnector.h"
#include "DatabaseConnector.h"
#include <string>
#include <iostream>
#include <sstream>

MCMCDatabaseConnector::MCMCDatabaseConnector() {
}

MCMCDatabaseConnector::MCMCDatabaseConnector(std::string hostName,
        std::string userName, std::string userPassword, std::string database)
{
    myConnection = new DatabaseConnector(hostName, userName, userPassword,
            database);
}

MCMCDatabaseConnector::MCMCDatabaseConnector(const MCMCDatabaseConnector& orig) {    
}

MCMCDatabaseConnector::~MCMCDatabaseConnector() {
    delete myConnection;
}

bool MCMCDatabaseConnector::createRun(std::string runName)
{
    std::stringstream insertStatement;
    insertStatement << "insert into runInfo values(NULL, " << "\""
            << runName << "\"" << ", 0)";

    myConnection->execute(insertStatement.str());

    std::stringstream getRunIdQuery;
    getRunIdQuery << "select runId from runInfo where runName = \"" << runName << "\";";
    std::cout << getRunIdQuery.str() << std::endl;
    sql::ResultSet* idResults = myConnection->executeQuery(getRunIdQuery.str());
    idResults->next()
    runId = idResults->getInt(1);

}