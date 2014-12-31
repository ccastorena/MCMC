/* 
 * File:   MCMCDataseConnector.h
 * Author: user
 *
 * Created on December 21, 2014, 1:26 PM
 */

#ifndef MCMCDATASECONNECTOR_H
#define	MCMCDATASECONNECTOR_H
#include <iostream>
class DatabaseConnector;

class MCMCDatabaseConnector {
public:
    MCMCDatabaseConnector();
    MCMCDatabaseConnector(std::string hostName, std::string userName,
        std::string userPassword, std::string database);
    MCMCDatabaseConnector(const MCMCDatabaseConnector& orig);
    
    bool createRun(std::string runName);
    
    virtual ~MCMCDatabaseConnector();
    
private:
    DatabaseConnector* myConnection;
    int runId;
};

#endif	/* MCMCDATASECONNECTOR_H */