/*
partition.h
template<typename N>Partition
Amir Yousef
10/19/2014
COP4531
Proj3
*/

#ifndef _PARTITION_H
#define _PARTITION_H
#include <iostream>
#include <vector.h>
#include <cstdlib>

namespace fsu
{

template < typename N = size_t >

class Partition
{

public:
explicit Partition     ( N size )  :  parent_((size_t)size, 0) , rank_((size_t)size, 0) {}
void     Reset         () 	{}
void     Reset         ( N newsize )  { std::cout << newsize << " elements" << std::endl; }
void     PushSingleton () { parent_.PushBack((N)parent_.Size()); rank_.PushBack(0); }
void     Union         ( N x , N y ) { Link(Root(x),Root(y)); }
bool     Find          ( N x , N y ) { return Root(x) == Root(y); }
bool     Find          ( N x , N y ) const  { return Root(x) == Root(y); }
size_t   Size          () const { return rank_.Size(); }
size_t   Components    () const { return parent_.Size(); }
void     Display       ( std::ostream& os ) const { os << "{"; for(size_t i=0; i<Partition::Size(); ++i) os << "{ " << i << " }"; os << "}"; os <<'\n'; }
void     Dump          ( std::ostream& os ) const { for(size_t i=0; i<Partition::Size(); ++i) os << "V[" << i << "] = " << -1 << " ;" << "  Root(" << i << ") = " << i << '\n'; }

private:
N    Root   ( N x ) { return parent_[x];}
N    Root   ( N x ) const { return parent_[x];}
void Link   ( N root1 , N root2 )
{
N newSize = 0;
if (rank_[root2] < rank_[root1]) 
{
parent_[root1] = root2;
parent_[root2] = newSize;
} 
else 
{
parent_[root2] = root1;
parent_[root1] = newSize;
}
}

private:
fsu::Vector <N> parent_;
fsu::Vector <N> rank_;
};

}

#endif