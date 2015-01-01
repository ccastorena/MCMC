/*
 * File:   newtestclass.cpp
 * Author: ccastorena
 *
 * Created on Nov 22, 2014, 6:52:21 AM
 */

#include "DatabaseConnectorTest.h"
#include "DatabaseConnector.h"
#include "math.h"
#include<gsl/gsl_randist.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

CPPUNIT_TEST_SUITE_REGISTRATION(DatabaseConnectorTest);

DatabaseConnectorTest::DatabaseConnectorTest() {
}

DatabaseConnectorTest::~DatabaseConnectorTest() {
}

void DatabaseConnectorTest::setUp() {
}

void DatabaseConnectorTest::tearDown() {
}

void DatabaseConnectorTest::testConstructor() {
    DatabaseConnector("localhost", "tester", "password", "MCMCTest");
    CPPUNIT_ASSERT(true);
}


void DatabaseConnectorTest::testCreatePreparedStatement() {
    DatabaseConnector connector = DatabaseConnector("localhost", "tester", "password", "MCMCTest");
    
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    std::cout << uuid << std::endl;
    std::stringstream uuidString;
    uuidString << uuid;
    
    sql::PreparedStatement * stmt =
            connector.getPreparedStatement(
            "insert into runInfo Values(NULL, ?, ?)");
    stmt->setString(1, uuidString.str());
    stmt->setInt(2, 0);
    stmt->execute();
    CPPUNIT_ASSERT(true);
}
