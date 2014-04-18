#include "stack.h"
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main(){
  const int NUM_BINARY_OPERATORS = 5;
  const string BINARY_OPERATORS[NUM_BINARY_OPERATORS] = {"%", "+", "-", "*", "/"};
  const int NUM_UNARY_OPERATORS = 1;
  const string UNARY_OPERATORS[NUM_UNARY_OPERATORS] = {"!"};
  bool is_binary_operator = false;
  bool is_unary_operator = false;
  Stack<int> s;
  string input = "";
  int num, n1, n2;

  cout << "Welcome to brain calc!" << endl;
  cout << "'$' ends a series of operations.  '#' ends all input." << endl;
  cout << "Enter some brain format operations:" << endl;

  cin >> input;

  while(input != "#"){

    while(input != "$"){
      is_unary_operator = false;
      is_binary_operator = false;

      for(int i = 0 ; i < NUM_BINARY_OPERATORS ; i ++)
        if(input == BINARY_OPERATORS[i]) is_binary_operator = true;
      for(int i = 0 ; i < NUM_UNARY_OPERATORS ; i ++)
        if(input == UNARY_OPERATORS[i]) is_unary_operator = true;

      if(is_binary_operator){
        n2 = s.top();
        s.pop();
        n1 = s.top();
        s.pop();

        if(input == "+")
          s.push(n1 + n2);
        else if(input == "-")
          s.push(n1 - n2);
        else if(input == "/")
          s.push(n1 / n2);
        else if(input == "*")
          s.push(n1 * n2);
        else if(input == "%")
          s.push(n1 % n2);

      }else if(is_unary_operator){
        n2 = s.top();
        s.pop();
        if(input == "!")
          s.push(-n2);

      }else{
        num = atoi(input.c_str());
        s.push(num);
      }

      cin >> input;
    }

    int i = 0;
    cout << "[ ";
    while(!s.isEmpty()){
      if(i) cout << ", ";
      cout << s.top();
      s.pop();
      i ++;
    }
    cout << " ]" << endl;

    cin >> input;
  }

}
