#include <algorithm>
#include <iostream>
#include <vector>

#include "avl_tree.h"

void test_print(int key, std::string val){
    std::cout << key << "\t" << val << std::endl;
}


int main() {
  // 2014 Total Pay for some Foothill CS faculty from
  // http://transparentcalifornia.com/export/2014-community-colleges.csv
  // and
  // http://www.foothill.edu/cs/schedule.php?act=1&dept=C%20S
  
    //Following 4 vectors are the 4 cases of AVL:
    //Left-Right
    //Left-Left
    //Right-Left
    //Right-Right
  std::vector<std::pair<int, std::string> > professors = {
    {20468, "Hadeel Ammari"},
    {21617, "Viet Trinh"},
    {130809, "Elaine Haight"},
    
    {36983, "Bita Mazloom"},
    
    {144740, "Michael Loceff"},
    
    {97262, "Ladawn Meade"},
    
    {52952, "Anand Venkataraman"},
    
    {38966, "David Harden"},
    
     {49732, "Jesse Cecil"},
     
   {46862, "Rula Khayrallah"}, 
  
    {180789, "William Murphy"},
    
    {5089, "Rahul Agarwal"}, //goes haywire here
    
  };
  
  /*
.insert(49732, "Jesse Cecil")
.insert(5089, "Rahul Agarwal")
.insert(144740, "Michael Loceff")
.insert(36983, "Bita Mazloom")
.insert(52952, "Anand Venkataraman")
.insert(21617, "Viet Trinh")
.insert(97262, "Ladawn Meade")
.insert(46862, "Rula Khayrallah")
.insert(38966, "David Harden")
.insert(180789, "William Murphy")
.insert(15351, "Thomas Riordan")
.insert(20468, "Hadeel Ammari")
.insert(130809, "Elaine Haight")
*/
  std::vector<std::pair<int, std::string> > test_professors = {
    {49732, "Jesse Cecil"},
    /*
    {5089, "Rahul Agarwal"},
    {144740, "Michael Loceff"},
    {36983, "Bita Mazloom"},
    {52952, "Anand Venkataraman"},
    {21617, "Viet Trinh"},
    {97262, "Ladawn Meade"},
    {46862, "Rula Khayrallah"},
    {38966, "David Harden"},
    {180789, "William Murphy"},
    {15351, "Thomas Riordan"},  
    {20468, "Hadeel Ammari"},
    {130809, "Elaine Haight"},    
    */
  };
  
  AVLTree<int, std::string> tree;

  //std::random_shuffle(LR_professors.begin(), LR_professors.end());
  for (const auto& pay_name_pair : test_professors) {
    std::cout << "insert(" << pay_name_pair.first << ", "
              << pay_name_pair.second << ")" << std::endl;
    tree.insert(pay_name_pair.first, pay_name_pair.second);
  }
  std::cout << std::endl;
  
  tree.print_tree(tree.root);

  for (const auto& pay_name_pair : test_professors) {
    const auto& key = pay_name_pair.first;
    std::cout << "get(" << key << ") == " << tree.get(key) << std::endl;
  }
    std::cout << std::endl;
  tree.print_tree(tree.root);
  // TODO: Check that heights are correct ...

  std::cout << std::endl;
  tree.remove(49732);
  tree.for_each_key_val(test_print);
  //tree.print_tree(tree.root);
  std::cout << "done printing tree" << std::endl;
/*
  std::cout << std::endl;
  tree.remove(52952);
  tree.print_tree(tree.root);
  
  std::cout << std::endl;
  tree.remove(144740);
  tree.print_tree(tree.root); 
  
  std::cout << std::endl;
  tree.remove(38966);
  tree.print_tree(tree.root);
  
  std::cout << std::endl;
  tree.remove(46862);
  tree.print_tree(tree.root); 
  
  std::cout << std::endl;
  tree.remove(97262);
  tree.print_tree(tree.root); 
  
  std::cout << std::endl;
  tree.remove(36983);
  tree.print_tree(tree.root); 
  
  std::cout << std::endl;
  tree.remove(20468);
  tree.print_tree(tree.root); 
  
  std::cout << std::endl;
  tree.remove(5089);
  tree.print_tree(tree.root); 
  
  std::cout << std::endl;
  std::cout << "remove(15351)" << std::endl;
  tree.remove(15351); //segFaults!
  tree.print_tree(tree.root); 
*/
 return 0;
}
/*
$ clang -pedantic -Wall -lm -lstdc++ -lpthread -std=c++11 -o example avl_tree_manual_test.cpp
$ ./example

insert(36983, Bita Mazloom)
insert(130809, Elaine Haight)
insert(144740, Michael Loceff)
insert(180789, William Murphy)
insert(5089, Rahul Agarwal)
insert(38966, David Harden)
insert(20468, Hadeel Ammari)
insert(15351, Thomas Riordan)
insert(46862, Rula Khayrallah)
insert(97262, Ladawn Meade)
insert(21617, Viet Trinh)
insert(49732, Jesse Cecil)
insert(52952, Anand Venkataraman)

get(36983) == Bita Mazloom
get(130809) == Elaine Haight
get(144740) == Michael Loceff
get(180789) == William Murphy
get(5089) == Rahul Agarwal
get(38966) == David Harden
get(20468) == Hadeel Ammari
get(15351) == Thomas Riordan
get(46862) == Rula Khayrallah
get(97262) == Ladawn Meade
get(21617) == Viet Trinh
get(49732) == Jesse Cecil
get(52952) == Anand Venkataraman
*/
