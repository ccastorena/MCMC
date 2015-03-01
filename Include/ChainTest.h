/*
 * File:   newtestclass.h
 * Author: ccastorena
 *
 * Created on Nov 22, 2014, 6:52:21 AM
 */

#ifndef CHAINTEST_H
#define	CHAINTEST_H

#include <cppunit/extensions/HelperMacros.h>


/** general error tolerance value */
#define _tolerance 0.0001

/** number of mcmc iterations to run when testing that things converge*/
#define _nGenerations 10000000

class ChainTest : public CPPUNIT_NS::TestFixture {
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

