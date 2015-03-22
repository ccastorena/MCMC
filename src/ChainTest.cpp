/*
 * File:   newtestclass.cpp
 * Author: ccastorena
 *
 * Created on Nov 22, 2014, 6:52:21 AM
 */

#include "ChainTest.h"
#include "Chain.h"
#include "math.h"
#include<gsl/gsl_randist.h>

void
normalProposalFunction ( double currentValue, double* proposedValue, gsl_rng * r )
{
    *proposedValue = currentValue + gsl_ran_gaussian ( r, 1 );
}

double
normalPosteriorFunction ( double Theta )
{
    return log ( gsl_ran_gaussian_pdf ( Theta, 1 ) );
}

ChainTest::ChainTest ( )
{
}

ChainTest::~ ChainTest ( )
{
}

void
ChainTest::setUp ( )
{
}

void
ChainTest::tearDown ( )
{
}

void
ChainTest::testConstructor ( )
{
    Chain<gsl_vector>* a ( );
    CPPUNIT_ASSERT ( true );
}

void
ChainTest::testAccept ( )
{
    double logCurrentPosterior = log ( 0.9 );
    double logPropPosterior = log ( 0.8 );

    Chain<gsl_vector*>* a = new Chain<gsl_vector*>( );

    CPPUNIT_ASSERT ( a->accept ( 0.1, 0.1 ) == 1 );

    double sum = 0;
    for ( int i = 0; i < _nGenerations; i ++ )
    {
        sum += a->accept ( logCurrentPosterior, logPropPosterior );
    }
    double proportion = sum / _nGenerations;
    double statistic = ( 1 - proportion / ( exp ( logPropPosterior ) / exp ( logCurrentPosterior ) ) );
    CPPUNIT_ASSERT ( ( statistic < _tolerance ) == 1 );
}

void
ChainTest::testRunChain ( )
{
    boost::uuids::uuid uuid = boost::uuids::random_generator ( )( );
    std::stringstream uuidString;
    std::stringstream runName;
    runName << uuid;
    std::string hostName = "localhost";
    std::string userName = "tester";
    std::string password = "password";
    std::string databaseName = "MCMCTest";

    Chain<double>* C = new Chain<double>(
                                          runName.str ( ),
                                          userName,
                                          password,
                                          databaseName,
                                          hostName,
                                          normalProposalFunction,
                                          normalPosteriorFunction );

    double startingValue = 0;
    double* samples = C->runChain ( &startingValue, _nGenerations );

    double x1 = 0; // firstMoment
    double x2 = 0; // secondMoment

    for ( int i = 0; i < _nGenerations; i ++ )
    {
        x1 += samples[i];
        x2 += pow ( samples[i], 2 );
    }

    std::cout << x1 / _nGenerations << std::endl;
    std::cout << pow ( x2 / _nGenerations, 0.5 ) << std::endl;
}