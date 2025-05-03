CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11 -fpermissive
ftp.o:ftp.c
	$(CXX) $(CXXFLAGS) -g -c -O $< -o $@
dbgc.o:dbgc.c
	$(CXX) $(CXXFLAGS) -g -c -O $< -o $@	
main:main.c ftp.o 
	$(CXX) $(CXXFLAGS) -g -O $^ -o $@

