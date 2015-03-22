/*
 * File:   newtestclass.cpp
 * Author: ccastorena
 *
 * Created on Nov 22, 2014, 6:52:21 AM
 */

#include "MCMCDatabaseConnectorTest.h"
#include "MCMCDatabaseConnector.h"
#include "math.h"
#include "DatabaseConnector.h"
#include <gsl/gsl_randist.h>
#include <string>
#include <iostream>
#include <sstream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

//

MCMCDatabaseConnectorTest::MCMCDatabaseConnectorTest ( )
{
}

MCMCDatabaseConnectorTest::~ MCMCDatabaseConnectorTest ( )
{
}

void
MCMCDatabaseConnectorTest::setUp ( )
{

}

void
MCMCDatabaseConnectorTest::tearDown ( )
{
}

void
MCMCDatabaseConnectorTest::testConstructor ( )
{

    MCMCDatabaseConnector testObject = MCMCDatabaseConnector ( "localhost", "tester",
                                                               "password", "MCMCTest" );
}

void
MCMCDatabaseConnectorTest::testCreateRun ( )
{


    MCMCDatabaseConnector testObject = MCMCDatabaseConnector ( "localhost", "tester",
                                                               "password", "MCMCTest" );

    boost::uuids::uuid uuid = boost::uuids::random_generator ( )( );
    std::stringstream uuidString;
    uuidString << uuid;

    testObject.createRun ( uuidString.str ( ) );

}
