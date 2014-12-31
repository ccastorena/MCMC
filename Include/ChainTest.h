/*
 * File:   newtestclass.h
 * Author: ccastorena
 *
 * Created on Nov 22, 2014, 6:52:21 AM
 */

#ifndef CHAINTEST_H
#define	CHAINTEST_H

#include <cppunit/extensions/HelperMacros.h>

class ChainTest : public CPPUNIT_NS::TestFixture {
    
    /** general error tolerance value */
    double tolerance = 0.0001;
    
    /** number of mcmc iterations to run when testing that things converge*/
    int nGenerations = 10000000;
    
    CPPUNIT_TEST_SUITE(ChainTest);

    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testAccept);
    CPPUNIT_TEST(testRunChain);
    
    CPPUNIT_TEST_SUITE_END();

public:
    ChainTest();
    virtual ~ChainTest();
    void setUp();
    void tearDown();

private:
    void testConstructor();
    void testAccept();
    void testRunChain();
};

#endif	/* CHAINTEST_H*/

