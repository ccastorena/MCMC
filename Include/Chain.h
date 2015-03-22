/*
 * File:   Chain.h
 * Author: ccastorena
 *
 * Created on November 15, 2014, 12:20 PM
 */

#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <iostream>
#include  "gsl/gsl_randist.h"
#include <boost/shared_ptr.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <math.h>
#include "MCMCDatabaseConnector.h"

#ifndef CHAIN_H
#define	CHAIN_H

template <typename paramType> class Chain {
public:

    Chain() {
        gsl_rng_env_setup();
        T = gsl_rng_default;
        r = gsl_rng_alloc(T);

    }

    Chain(
            std::string runName,
            std::string userName,
            std::string password,
            std::string databaseName,
            std::string hostName,
            void (*proposalFunctionParam) (paramType currentVal, paramType* proposedVal, gsl_rng * r),
            double (*posteriorFunctionParam) (paramType Theta)
            ) {
        gsl_rng_env_setup();
        T = gsl_rng_default;
        r = gsl_rng_alloc(T);
        setProposalFunction(proposalFunctionParam);
        setPosteriorFunction(posteriorFunctionParam);

        m_Connection = new MCMCDatabaseConnector(hostName, userName, password, databaseName);
        createRun(runName);
        this->runId = m_Connection->getRunId(runName);

    }

    virtual ~Chain() {
    }

    /**Determines whether or not to accept according to the metropolis-hastings
     * ratio*/
    bool accept(double currentPosterior, double proposalPosterior) {
        return log(gsl_ran_flat(r, 0, 1)) <
                (proposalPosterior - currentPosterior);
    }

    paramType* runChain(paramType* startingValue, int nGenerations) {

        paramType* samples = (paramType*) calloc(nGenerations, sizeof (paramType));
        samples[0] = *startingValue;

        double* logPosteriorValues =
                (double*) calloc(nGenerations, sizeof (double));

        logPosteriorValues[0] = posteriorFunction(*startingValue);

        for (int i = 1; i < nGenerations; i++) {
            paramType currentValue = samples[i - 1];
            paramType* proposedValue = new paramType();
            proposalFunction(currentValue, proposedValue, r);
            double proposedLogPosterior = posteriorFunction(*proposedValue);
            bool acceptProposal =
                    accept(logPosteriorValues[i - 1], proposedLogPosterior);

            if (acceptProposal) {
                samples[i] = *proposedValue;
                logPosteriorValues[i] = proposedLogPosterior;
            } else {
                samples[i] = samples[i - 1];
                logPosteriorValues[i] = logPosteriorValues[i - 1];
            }
        }
        free(logPosteriorValues);
        return samples;
    }

private:

    void setProposalFunction(void (*proposalFunctionParam) (
            paramType currentVal, paramType* proposedVal, gsl_rng * r)) {
        proposalFunction = proposalFunctionParam;
    }

    void setPosteriorFunction(double (*posteriorFunctionParam) (paramType Theta)) {
        posteriorFunction = posteriorFunctionParam;
    }

    void createRun(std::string runName) {
        m_Connection->createRun(runName);
    }

    void insertSample(paramType* sample)
    {
        
    }
    const gsl_rng_type * T;

    gsl_rng * r;

    void (*proposalFunction) (paramType currentVal, paramType* proposedVal, gsl_rng * r);

    double (*posteriorFunction) (paramType Theta);

    MCMCDatabaseConnector* m_Connection;

    int runId;

};

#endif	/* CHAIN_H */
