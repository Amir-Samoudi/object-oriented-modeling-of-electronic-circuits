g++ -c partsLibrary.cpp -I$SYSTEMC_HOME/include -o partsLibrary.o
g++ -c controller_SSC.cpp -I$SYSTEMC_HOME/include -o controller_SSC.o
g++ -c SSCTB.cpp -I$SYSTEMC_HOME/include -o SSCTB.o
g++ -c main.cpp -I$SYSTEMC_HOME/include -o main.o


g++ -o output_file partsLibrary.o controller_SSC.o SSCTB.o main.o -L$SYSTEMC_HOME/lib-linux64 -lsystemc -lm
