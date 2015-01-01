/*
 * File:   newtestclass.h
 * Author: ccastorena
 *
 * Created on Nov 22, 2014, 6:52:21 AM
 */

#ifndef NEWTESTCLASS_H
#define	NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class DatabaseConnectorTest : public CPPUNIT_NS::TestFixture {
    
    CPPUNIT_TEST_SUITE(DatabaseConnectorTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testCreatePreparedStatement);
    CPPUNIT_TEST_SUITE_END(); 

public:
    DatabaseConnectorTest();
    virtual ~DatabaseConnectorTest();
    void setUp();
    void tearDown();

private:
    void testConstructor();
    void testCreatePreparedStatement();
};

#endif	/* NEWTESTCLASS_H */

