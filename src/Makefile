include ../Makefile.in

SRC = main.cpp ChainTest.cpp Chain.cpp MCMCDatabaseConnectorTest.cpp MCMCDatabaseConnector.cpp DatabaseConnectorTest.cpp DatabaseConnector.cpp

OBJ = $(addsuffix .o, $(basename $(SRC)))

Run: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LIBS) 

depend:
	makedepend $(CXXFLAGS) -Y $(SRC)
