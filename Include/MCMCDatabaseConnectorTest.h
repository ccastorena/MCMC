/*
 * File:   newtestclass.h
 * Author: ccastorena
 *
 * Created on Nov 22, 2014, 6:52:21 AM
 */

#ifndef MCMCDATABASECONNECTORTEST_H
#define	MCMCDATABASECONNECTORTEST_H

#include <cppunit/extensions/HelperMacros.h>

class MCMCDatabaseConnectorTest : public CPPUNIT_NS::TestFixture {
    
    CPPUNIT_TEST_SUITE(MCMCDatabaseConnectorTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testCreateRun);
    CPPUNIT_TEST_SUITE_END();

public:
    MCMCDatabaseConnectorTest();
    virtual ~MCMCDatabaseConnectorTest();
    void setUp();
    void tearDown();

private:
    void testConstructor();
    void testCreateRun();
};

#endif	/* MCMCDATABASECONNECTORTEST_H*/

