/*
 * File:   MCMCDataseConnector.h
 * Author: user
 *
 * Created on December 21, 2014, 1:26 PM
 */

#ifndef MCMCDATASECONNECTOR_H
#define	MCMCDATASECONNECTOR_H
#include <iostream>

#include "DatabaseConnector.h"
class DatabaseConnector;

class MCMCDatabaseConnector {
public:
    MCMCDatabaseConnector();
    MCMCDatabaseConnector(std::string hostName, std::string userName,
            std::string userPassword, std::string database);
    MCMCDatabaseConnector(const MCMCDatabaseConnector& orig);

    bool createRun(std::string runName);

    int getRunId(std::string runName);

    bool executeQuery(std::string query){myConnection->execute(query);}

    virtual ~MCMCDatabaseConnector();

private:
    DatabaseConnector* myConnection;
};

#endif	/* MCMCDATASECONNECTOR_H */