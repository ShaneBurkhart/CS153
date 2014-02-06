
#include "gmatrix.h"
using namespace std;

int main()
{
  GMatrix m(10, 10, 5, 2);

  cout << "Basic" << endl;
  cout << m << endl << endl;

  GMatrix c(m);
  cout << "Copy Constructor" << endl;
  cout << c << endl << endl;

  GMatrix p(5, 5, 4, 3);
  m = p;
  cout << "Equal Operator" << endl;
  cout << p << endl << endl;
  cout << m << endl << endl;

  return 0;
}
