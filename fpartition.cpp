/*
    fpartition.cpp

    testing the Partition union-find class
*/

#include <partition.h>

// typedef long IntType;   // for the "one vector<signed>" implementation
typedef size_t IntType; // for the "two vector<unsigned>" implementation

const IntType defaultSize = 10;

void Preamble();
void DisplayMenu();

template < typename N >
void CopyTest(const fsu::Partition<N>& p, fsu::Partition<N> p1);

template < typename N >
void AssignTest(const fsu::Partition<N>& p);

int main (int argc, char* argv[])
{
  bool BATCH = 0;
  IntType size = defaultSize;
  if (argc > 1)
    size = atoi(argv[1]);
  if (argc > 2)
    BATCH = 1;
  fsu::Partition<IntType> * pp = new fsu::Partition<> (size);
  char command = 'x';
  IntType x, y;
  Preamble();
  if (!BATCH) DisplayMenu();
  do
  {
    std::cout << "Enter command ('m' for menu, 'x' to quit): ";
    std::cin >> command;
    switch(command)
    {
    case 'u': case 'U':
      std::cin >> x >> y;
      if (BATCH) std::cout << command << ' ' << x << ' ' << y << '\n';
      pp->Union(x,y);
      break;

    case 'f': case 'F':
      std::cin >> x >> y;
      if (BATCH) std::cout << command << ' ' << x << ' ' << y << '\n';
      if (pp->Find(x,y))
        std::cout << " Find(" << x << ',' << y << ") = true\n";
      else
        std::cout << " Find(" << x << ',' << y << ") = false\n";
      break;

    case 'r': case 'R':
      std::cin >> x;
      if (BATCH) std::cout << command << ' ' << x << '\n';
      pp->Reset(x);
      break;

    case 'c': case 'C':
      if (BATCH) std::cout << command << '\n';
      std::cout << pp->Components() << " components\n";
      break;

    case 's': case 'S':
      if (BATCH) std::cout << command << '\n';
      std::cout << pp->Size() << " elements\n";
      break;

    case 'p': case 'P':
      if (BATCH) std::cout << command << '\n';
      pp->PushSingleton();
      break;

    case 'o': case 'O':
      if (BATCH) std::cout << command << '\n';
      pp->Display(std::cout);
      break;

    case 'd': case 'D':
      if (BATCH) std::cout << command << '\n';
      pp->Dump(std::cout);
      break;

    case 'm': case 'M':
      if (BATCH) std::cout << command << '\n';
      DisplayMenu();
      break;

    case '=':
      if (BATCH) std::cout << command << '\n';
      CopyTest(*pp, *pp);
      AssignTest(*pp);
      break;

    case 'x': case 'X': case 'q':
      if (BATCH) std::cout << command << '\n';
      command = 'Q';
      break;

    default:
      if (BATCH) std::cout << command << '\n';
      std::cout << "command invalid - try again\n";
      while (command != '\n') std::cin.get(command);
    } // switch
  } // do
  while (command != 'Q');
}

void DisplayMenu()
{
  std::cout << "  Partition::operation      command entry\n"
            << "  --------------------      -------------\n"
            << "  Union      ( x , y )      U x y\n"
            << "  Find       ( x , y )      F x y\n"
            << "  Push       ()             P\n"
            << "  Reset      ( size )       R newsize\n"
            << "  Size       ()             S\n"
            << "  Components ()             C\n"
            << "  Display    ( cout )       O\n"
            << "  Dump       ( cout )       D\n"
            << "  Copy Test  ()             =\n";
}

void Preamble()
{
  std::cout << "Welcome to fpartition - a functional interface to the Partition class\n";
}

template < typename N >
void CopyTest(const fsu::Partition<N>& p, fsu::Partition<N> p1)
{
  std::cout << "  begin copy test:\n"
            << "  size of original:       " << p.Size() << '\n'
            << "  size of copy:           " << p1.Size() << '\n'
            << "  components of orignal:  " << p.Components() << '\n'
            << "  components of copy:     " << p1.Components() << '\n'
            << "  end copy test\n";
}

template < typename N >
void AssignTest(const fsu::Partition<N>& p)
{
  fsu::Partition<N> p1(0), p2(0);
  p2 = p1 = p;
  std::cout << "  begin assign test:\n"
            << "  size of original:       " << p.Size() << '\n'
            << "  size of assignee:       " << p2.Size() << '\n'
            << "  components of original: " << p.Components() << '\n'
            << "  components of assignee: " << p2.Components() << '\n'
            << "  end assign test\n";
}
