CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11 -fpermissive
ftp.o:ftp.c
	$(CXX) $(CXXFLAGS) -g -c -O $< -o $@
dbgc.o:dbgc.c
	$(CXX) $(CXXFLAGS) -g -c -O $< -o $@	
archie_db.o:archie_db.c
	$(CXX) $(CXXFLAGS) -g -c -O $< -o $@
main:main.c ftp.o archie_db.o
	$(CXX) $(CXXFLAGS) -g -O $^ -o $@

