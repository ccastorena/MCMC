
DROP TABLE IF EXISTS runInfo;
CREATE TABLE runInfo (
    runId INT AUTO_INCREMENT,
    runName VARCHAR(100) UNIQUE,
    lastProcessedFrame INT,
    PRIMARY KEY (runId)
);

DROP TABLE IF EXISTS chainInfo;
CREATE TABLE chainInfo (
    iteration INT,
    runId INT,
    logPosterior DOUBLE,
    effectiveSampleSize DOUBLE
);

DROP TABLE IF EXISTS samples;
CREATE TABLE samples (
    iteration INT,
    runId INT,
    theta BLOB
);
