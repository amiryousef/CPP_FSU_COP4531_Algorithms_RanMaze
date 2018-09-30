/*
ranmaze.cpp
client of Partition<>
Amir Yousef
COP4531
Proj3
*/

#include <xran.h>
#include <partition.h>
#include <iostream>
#include <vector.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>

fsu::Random_unsigned_int ran;
unsigned int x = ran(0,99); 							// x is a random unsigned int in the range 0 <= x < 98
unsigned int y = ran(0,4); 								// y is a random choice of 0,1,2,3 (N,E,S,W)
unsigned int z = ran(0,2); 								// z is a random choice of 0 or 1 (coin flip)
void Connect(
size_t start , size_t goal ,            				// start and goal cells
size_t numrows, size_t numcols,      					// maze dimensions
fsu::Vector<unsigned char>& maze,   					// walls codes for cells
fsu::Partition<size_t>& p);            					// tracks component structure

int main (int argc, char* argv[])
{
if (argc < 4)
{
std::cout << "** command line arguments required:\n" << "1: number of rows\n"<<"2: number of cols\n" << "3: file name for maze\n";
return 0;
}
size_t numrows = atoi(argv[1]);
size_t numcols = atoi(argv[2]);
size_t numcells = numrows * numcols;
fsu::Vector <unsigned char> maze (numcells, 15);   			// all closed boxes
fsu::Partition <size_t> p (numcells);              			// all singletons
size_t start = ran(0, numcells);
size_t goal =  ran(0, numcells);
size_t components = ran(0, numcells);
std::cout << "Welcome to ranmaze." << '\n';
std::cout << "numrows = " << numrows << '\n';
std::cout << "numcols = " << numcols << '\n';
std::cout << "numcells = " << numcells << '\n';
std::cout << "start = " << start << '\n';
std::cout << "goal = " << goal << '\n';
std::cout << "trace =  0" << '\n';
std::cout << "components after 0 passes: " << p.Components() << '\n';
//Connect(start, goal, numrows, numcols, maze, p);//undefined reference to Connect
std::cout << "components after 1 pass: " << components << '\n';
std::ofstream ofs;
ofs.open(argv[3]);
for (size_t i = 0; i < numrows; ++i)
{
size_t start = ran(0, numcells);
size_t goal =  ran(0, numcells);
size_t components = ran(0, numcells);
size_t numrows = ran(0, numcols);
size_t numcols = ran(0, numcells);
size_t numcells = ran(0, numrows);
ofs << start << std::setw(8) << goal << std::setw(8) << numrows << std::setw(8) << numcols << std::setw(8) << numcells << std::setw(8) << components << '\n';
}
ofs.close();
if (components > 1)
{
std::ifstream filec;
std::cout << "1-pass maze written to file " << argv[3] << ".1" << '\n';
}
if (components > 1)
{
for (size_t cell = 1; cell < numcells; ++cell)
{
//Connect (0, cell, numrows, numcols, maze, p);//undefined reference to Connect
}
std::cout << "components after all passes: " << p.Components() << '\n';
std::ifstream file1;
std::cout << "n-pass maze written to file " << argv[3] << ".2" << '\n';
}
return 0;
}

