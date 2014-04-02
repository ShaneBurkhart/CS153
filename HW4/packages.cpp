#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "package.h"
#include "package_2d.h"
#include "package_3d.h"
#include "package_4d.h"

using namespace std;

int main()
{
  // Format output
  cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
  cout.precision(2);

  int num, dimensions;
  float length, width, height, fourth, weight;
  float total_profit = 0;
  string from, to;
  fstream file;
  Package** packages;

  file.open("sampleinput.txt");
  file >> num; // Get number of packages

  packages = new Package*[num];

  for(int i = 0 ; i < num ; i ++){
    file >> dimensions;
    file >> from;
    file >> to;
    // Always a length and width
    file >> length;
    file >> width;

    switch(dimensions){
      case 2: packages[i] = new Package2D(from, to, i, length, width);
              break;
      case 3: file >> height;
              file >> weight;
              packages[i] = new Package3D(from, to, i, length, width, height, weight);
              break;
      case 4: file >> height;
              file >> fourth;
              file >> weight;
              packages[i] = new Package4D(from, to, i, length, width, height, fourth, weight);
              break;
    }

    total_profit += packages[i]->getCharge();

    cout << *packages[i];
  }

  cout << endl;
  cout << "TOTAL PROFIT = $" << total_profit << endl;
  cout << "AVERAGE = $" << total_profit / num << endl;

  // Destroy everyting
  for(int i = 0 ; i < num ; i ++)
    delete packages[i];
  delete packages;

  return 0;
}
