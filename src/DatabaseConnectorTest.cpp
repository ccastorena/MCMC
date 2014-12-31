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
