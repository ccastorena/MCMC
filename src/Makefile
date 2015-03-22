include ../Makefile.in

SRC = main.cpp ChainTest.cpp MCMCDatabaseConnectorTest.cpp DatabaseConnectorTest.cpp Chain.cpp  MCMCDatabaseConnector.cpp DatabaseConnector.cpp

OBJ = $(addsuffix .o, $(basename $(SRC)))

Run: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LIBS) 

depend:
	makedepend $(CXXFLAGS) -Y $(SRC)
