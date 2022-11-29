#include "ArgumentManager.h"
#include "bst.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream out(am.get("output"));
  
  // ifstream input("input1.txt");
  // ofstream out("output1.txt");

  string inStr; // input string
  BST my_bst, *root = NULL; //BST
  vector<string> list_of_numbers;
  string temp = "";
  //first get all the commands in the priority queue
   while (getline(input, inStr)) {
      for (int i =0; i<inStr.size();i++){
        if (inStr[i]==' '){
          list_of_numbers.push_back(temp);
          temp= "";
        }
        else{
          temp += inStr[i];
        }
        if(i ==inStr.size()-1){        
          list_of_numbers.push_back(temp);        
        }
      }
    }

  for (int i=0;i< list_of_numbers.size();i++){
    root = my_bst.Insert(root,list_of_numbers[i]);
  }
  
  my_bst.Preorder(root,out,"[x");

  return 0;
 
}