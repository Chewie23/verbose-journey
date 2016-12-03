#pragma once

#include <iostream>
#include <algorithm>

template <typename Key, typename Value>
struct AVLTreeNode {
  AVLTreeNode *parent, *left, *right;
  Key key;
  Value value;
  int height;
  int balance;

  AVLTreeNode(const Key& key, const Value& value)
    : parent(nullptr), left(nullptr), right(nullptr),
      key(key), value(value), height(1), balance(0) {}

  ~AVLTreeNode() {
      delete left;
      delete right;
  }
};

template <typename Key, typename Value>
class AVLTree {
public:
  AVLTreeNode<Key, Value> *root;

  AVLTree() : root(nullptr) {}

  ~AVLTree() {
      delete root;
  }

  void print_tree(AVLTreeNode <Key, Value> *node) {
       std::cout << "Printing tree" << std::endl;
       if (!node) {
            return;
        }
       if (node) {
           std::cout << "Printing node" << std::endl;
            std::cout << "Key:\t" << node->key <<
            "\tHeight:\t" << node->height << "\tBalance:\t" <<
            node->balance << std::endl;
        } 
        if (node->left){
            print_tree(node->left);
        }
        if (node->right){
            print_tree(node->right);
        }
      
  }
  //The following 7 methods are organized in progressive use (going from basic get_height to balancing the tree).
  int get_height(AVLTreeNode <Key, Value> *&node) {
        if (!node) {
            return 0;
        }
        return node->height;
  }
    int balance_factor(AVLTreeNode <Key, Value> *&node) { //balance factor = height left - height right
        if (!node) {
            return 0;
        }
        return get_height(node->left) - get_height(node->right);
    }
    bool node_is_unbalanced(AVLTreeNode <Key, Value> *&node) {
        return (balance_factor(node) > 1 || balance_factor(node) < -1);
    }
    
    void set_height_and_balance_factor(AVLTreeNode <Key, Value> *&node){
        if (!node) {
            return;
        }
        node->height = std::max(get_height(node->left), get_height(node->right)) + 1; 
        node->balance = balance_factor(node);
    }
    AVLTreeNode <Key, Value> *rotate_left(AVLTreeNode <Key, Value> *node){ 
        AVLTreeNode <Key, Value> *child_node      = node->right;
        AVLTreeNode <Key, Value> *grandchild_node = nullptr;
        if (child_node->left){
            grandchild_node = child_node->left;
        }

        //rotation and re-setting the pointers
        child_node->left = node;
        node->right      = grandchild_node;
        
        if (grandchild_node) {
            grandchild_node->parent = node; 
        }
        if(node == root){
            child_node->parent = nullptr;
            root               = child_node;
            node->parent       = child_node;
        } else {
            if (node->parent->left == node){
                node->parent->left = child_node;
            } else {
                node->parent->right = child_node;
            }
            child_node->parent = node->parent;
            node->parent       = child_node;
        }
        
        //updating height and balance
        set_height_and_balance_factor(node);
        set_height_and_balance_factor(child_node);
        set_height_and_balance_factor(root);
        return child_node;
    }
    
    AVLTreeNode <Key, Value> *rotate_right(AVLTreeNode <Key, Value> *node) {
        AVLTreeNode <Key, Value> *child_node      = node->left;
        AVLTreeNode <Key, Value> *grandchild_node = nullptr;
        if (child_node->right){
            grandchild_node = child_node->right;
        }
        //rotation and re-setting the pointers
        child_node->right = node;
        node->left        = grandchild_node;
        if (grandchild_node) {
            grandchild_node->parent = node; 
        }
        if(node == root){
            child_node->parent = nullptr;
            root               = child_node;
            node->parent       = child_node;
        } else { 
            
            if (node->parent->left == node){
                node->parent->left = child_node;
            } 
            else {
                node->parent->right = child_node;
            }
             child_node->parent = node->parent;
             node->parent       = child_node;
        }
        //updating height and balance
        set_height_and_balance_factor(node);
        set_height_and_balance_factor(child_node);
        set_height_and_balance_factor(root);
        return child_node;
    }
    
    void balance_tree_at(AVLTreeNode <Key, Value> *&node, const Key& key) {
        //note on logic: node is the "root" of a three node sub-tree, specifically where the tree starts becoming unbalanced
        //Left-Left case
        if (node->balance > 1 && node->left->balance >= 0){ 
            //std::cout << "Left-Left" << std::endl;
            node = rotate_right(node);
        }
        //Left-Right case
        if (node->balance > 1 && node->left->balance < 0){
            //std::cout << "Left-Right" << std::endl;
            node->left = rotate_left(node->left); //turns this into a LL case
            node = rotate_right(node);
        } 
        //Right-Right case
        if (node->balance < -1 && node->right->balance <= 0){
            //std::cout << "Right-Right" << std::endl;
            node = rotate_left(node);
        } 
        //Right-Left case
        if (node->balance < -1 && node->right->balance > 0) {
            //std::cout << "Right-Left" << std::endl;
            node->right = rotate_right(node->right); //turns into a RR case
            node = rotate_left(node);
        }
    }
    void check_height_and_balance(AVLTreeNode <Key, Value> *&node, const Key& key){
        while (node->parent){ //same logic as node->parent != nullptr
            set_height_and_balance_factor(node);
            if (node_is_unbalanced(node)){
                balance_tree_at(node, key);
            }
            node = node->parent;
        } //end while loop
        set_height_and_balance_factor(root);
        if (node_is_unbalanced(root)){
            balance_tree_at(root, key);
        }
    }
  
  // PART 1
  // Insert a value, while making sure the tree is still a AVL tree (meaning balanced!).
  // This assumes that the key does not exist in the tree.

  void insert(const Key& key, const Value& value){
        AVLTreeNode <Key, Value> *new_node = new AVLTreeNode <Key, Value> (key, value);
        if (!root) {
            root = new_node;
            return;
        }
        AVLTreeNode <Key, Value> *cur = root;
        while (cur) { //same logic as cur != nullptr
            if (!cur->left && new_node->key < cur->key){
                cur->left = new_node;
                new_node->parent = cur;
                break;
            } else if (!cur->right && new_node->key >= cur->key){
                cur->right = new_node;
                new_node->parent = cur;
                break;
            } else if (cur->left && new_node->key < cur->key) { //checks if there is a left node and if new_node key < current key
                cur = cur->left;
            } else if (cur->right && new_node->key >= cur->key) { //same, but for right side
                cur = cur->right;
            } 
        } //end while loop
        check_height_and_balance(cur, key); //climbs up to parent, and updates the node height and balance based on children
  }
  
  //helper recursive function for get() and remove()
  bool found_key(AVLTreeNode <Key, Value> *&cur, const Key& key) const{ 
        if (key == cur->key) {
            return true;
        } else if (cur->left && key < cur->key) {
            cur = cur->left;
            return found_key(cur, key);
        } else if (cur->right && key >= cur->key) {
            cur = cur->right;
            return found_key(cur, key);
        } else {
            return false;
        }
  }
  
  
  // PART 1
  // Given a key, find the corresponding value.
  // This assumes that the key exists.
  Value& get(const Key& key) const{
      AVLTreeNode <Key, Value> *cur = root;
      AVLTreeNode <Key, Value> *could_not_find = nullptr;
      if (found_key(cur, key)){
        return cur->value;
      }
      return could_not_find->value;
      
  }

  // PART 1
  // Given a callable, that takes a Key and Value, call that callable
  // for every key/value pair in the tree in sorted order.
  // e.g. callable(Key(), Value()

   template <typename Callable>
   void helper_fxn(const AVLTreeNode<Key, Value> *cur, const Callable& callable) {
      if (!cur) {
         return;
      }
         helper_fxn(cur->left, callable); 
         callable(cur->key, cur->value);
         helper_fxn(cur->right, callable);
   }
   template <typename Callable>
   void for_each_key_val(const Callable& callable) {
      helper_fxn(root, callable);
   }


  // PART 2
  // Remove the value associated with key,
  // while making sure the tree is still a AVL tree.
  // This assumes that the key exists.
  
  void remove_leaf(AVLTreeNode <Key, Value> *&node){
        if (node == root){
            delete node;
            root = nullptr;
            return;
        }
        if (node->parent->left == node){
            node->parent->left = nullptr;
        } else {
            node->parent->right = nullptr;
        }
        node->parent = nullptr;
        delete node;
        node = nullptr;
  }
  
//Only gets a leaf node. Works only for removing node with 1 child
  AVLTreeNode <Key, Value> *get_single_child(AVLTreeNode <Key, Value> *cur){
      AVLTreeNode <Key, Value> *node = cur;
      if (!node->left && !node->right) {
            return node;
      } else if(node->left) {
            return get_single_child(node->left);
      }
      return get_single_child(node->right);
  }
  
  //only works with removing node with 2 children
  AVLTreeNode <Key, Value> *get_valid_leaf(AVLTreeNode <Key, Value> *node) { //assuming we are given cur->right as argument
      if (!node->left) { //the left most node on the right half. We have to check which case it actually is in the remove()
          return node;
      }
      return get_valid_leaf(node->left); //keeps going down to the left
  }
  
  void remove(const Key& key) {
      AVLTreeNode <Key, Value> *cur = root; 
      AVLTreeNode <Key, Value> *cur_parent = nullptr;
      //logic to find the node in question
      if (!found_key(cur, key)) {
        return; //could not find node
      }
      if (cur->parent){
         cur_parent = cur->parent;
      }
      if (!cur->left && !cur->right){ //cur = leaf node
          if (cur == root) {
            remove_leaf(cur);
            return;
          }
          remove_leaf(cur);
          check_height_and_balance(cur_parent, key); 
      } else if ((cur->left && !cur->right) || (!cur->left && cur->right)) { //cur is parent to 1 node. That 1 node will always be a leaf (as long as AVL applies)
            AVLTreeNode <Key, Value> *cur_child =  get_single_child(cur); //this temp will hold the value of the leaf
            cur->value = cur_child->value;
            cur->key    = cur_child->key;
            remove_leaf(cur_child);
      } else if (cur->left && cur->right) { //cur is parent to 2 nodes
            //Repeating logic for single child "cur" node. Need to make a function or something
            AVLTreeNode <Key, Value> *temp =  get_valid_leaf(cur->right);  
            AVLTreeNode <Key, Value> *temp_parent = temp->parent;
            cur->value = temp->value;
            cur->key    = temp->key;
            if ((temp->left && !temp->right) || (!temp->left && temp->right)) { //the node we want to replace cur with is a parent of 1 child!
                AVLTreeNode <Key, Value> *temp_child =  get_single_child(temp);
                temp->value = temp_child->value;
                temp->key    = temp_child->key;
                remove_leaf(temp_child);
                check_height_and_balance(temp, key);
            } else if (!temp->left && !temp->right) { // the node we chose to replace cur with is a leaf! easy case!
                remove_leaf(temp);
                check_height_and_balance(temp_parent, key);
            }
    }
    if (cur) {
        check_height_and_balance(cur, key);
    }
  }    
};

