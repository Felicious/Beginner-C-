#ifndef BTNODE_H
#define BTNODE_H
#include <cassert>

template <class T>
class btnode
{
public:
    //pre: none
    //post: a btnode has been created with given initial data
    btnode(const T & init_data = T(),
           btnode * init_left = nullptr,
           btnode * init_right = nullptr){
        _data = init_data;
        _left = init_left;
        _right = init_right;
    }
    // pre: none
    // post: returns a reference to data stored in this btnode
    T & data(){
        return _data;
    }
    const T & data() const{
        return _data;
    }
    // pre: none
    // post: returns a reference to left/right pointers
    btnode * & left(){
        return _left;
    }
    btnode * & right(){
        return _right;
    }
    const btnode * left() const{
        return _left;
    }
    const btnode * right() const{
        return _right;
    }
    bool is_leaf() const{
        return (_left == nullptr && _right == nullptr);
    }
private:
    T _data;
    btnode * _left;
    btnode * _right;

    // class invariants:
    // _data contains data item stored in this binary tree node
    // _left/_right points to the left and right child
};

// pre: none
// post: returns the number of nodes with exactly two children in the given binary tree
template <class T>
size_t n2(const btnode<T> * root){
    size_t count = 0;
    if(root == nullptr)
        return 0;
    if((root->left() != nullptr)&&(root->right() != nullptr))
        count = 1;
    count += n2(root->left());
    count += n2(root->right());
    return count;
}
// pre: root points to the root of a binary tree
// post: all dynamically allocated memory has returned to heap
//       root is set to nullptr

template <class T>
void bt_clear(btnode<T> * & root){
   if (root == nullptr)
       return;
   bt_clear(root->left());
   bt_clear(root->right());
   delete root;
   root = nullptr;
}
#endif // BTNODE_H
