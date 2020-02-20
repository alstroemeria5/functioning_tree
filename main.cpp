#include <iostream>
#include <vector>
#include "Tree.hpp"
using namespace std;

int main()
{
    Tree tree;
    tree+50+40+20+45+10+25;
    Tree *tree2=new Tree();
    (*tree2)+30+15;
   
    /*tree-45;
    tree.postorder();
    tree.inorder();
    cout<<tree.GetNumber(2).data<<endl;
    cout<<tree.root->LeftChild<<endl;*/
    tree*(*tree2);
    tree.RightRotation(20);
    /*Tree tree;
    tree+50+40+20+45+10+25+30+15;*/
    tree.inorder();
    tree.postorder();
    return 0;
}

 /*tree.preorder();
    cout<<tree.search(40)->ancester->data<<endl;
    tree.remove(40);*/