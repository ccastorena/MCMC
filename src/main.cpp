#include <iostream>

/*
 * File:   newtestrunner.cpp
 * Author: ccastorena
 *
 * Created on Nov 22, 2014, 6:52:22 AM
 */

#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "ChainTest.h"
#include "DatabaseConnectorTest.h"
#include "MCMCDatabaseConnectorTest.h"
#include "DatabaseConnector.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DatabaseConnectorTest);
CPPUNIT_TEST_SUITE_REGISTRATION(MCMCDatabaseConnectorTest);
CPPUNIT_TEST_SUITE_REGISTRATION(ChainTest);

int main() {


    // Create the event manager and test controller
    CPPUNIT_NS::TestResult controller;

    // Add a listener that collects test result
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener(&result);

    // Add a listener that print dots as test run.
    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener(&progress);

    // Add the top suite to the test runner
    CPPUNIT_NS::TestRunner runner;
    runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    runner.run(controller);

    // Print test in a compiler compatible format.
    CPPUNIT_NS::CompilerOutputter outputter(&result, CPPUNIT_NS::stdCOut());
    outputter.write();

    return result.wasSuccessful() ? 0 : 1;
}

