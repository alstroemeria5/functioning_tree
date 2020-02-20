#include <vector>
#include <iostream>
#include "Tree.hpp"
using namespace std;
int Tree::insertNode(TreeNode **start,int data,TreeNode *ancester){

    if(*start==nullptr){
        *start=new TreeNode(data);
        (*start)->ancester=ancester;
        return 0;
    }
    if(data<=(*start)->data){
        insertNode(&(*start)->LeftChild,data,*start);
    }
    if(data>(*start)->data)
        insertNode(&(*start)->RightChild,data,*start);
}
int Tree::insertNode(TreeNode **start,TreeNode** data,TreeNode *ancester){

    if(*start==nullptr){
        *start=*data;
        (*start)->ancester=ancester;
        return 0;
    }
    if((*data)->data<=(*start)->data){
        insertNode(&(*start)->LeftChild,data,*start);
    }
    if((*data)->data>(*start)->data)
        insertNode(&(*start)->RightChild,data,*start);
}

void Tree::preorder(){
    RefreshArry(1);
    int n=arry.size();
    for(int i=0;i<n;i++)
        cout<<arry[i]<<' ';
    cout<<endl;
}
void Tree::inorder(){
    RefreshArry(2);
    int n=arry.size();
    for(int i=0;i<n;i++)
        cout<<arry[i]<<' ';
    cout<<endl;
}
void Tree::postorder(){
    RefreshArry(3);
    int n=arry.size();
    for(int i=0;i<n;i++)
        cout<<arry[i]<<' ';
    cout<<endl;
}
void Tree::preorderVector(TreeNode *start){
    if(start){
        arry.push_back(start->data);
        preorderVector(start->LeftChild);
        preorderVector(start->RightChild); 
    }
}
void Tree::inorderVector(TreeNode *start){
    if(start){
        inorderVector(start->LeftChild);
        arry.push_back(start->data);
        inorderVector(start->RightChild); 
    }
}
void Tree::postorderVector(TreeNode *start){
    if(start){
        postorderVector(start->LeftChild);
        postorderVector(start->RightChild);
        arry.push_back(start->data); 
    }
}
TreeNode* Tree::search(int data){
    TreeNode *tmp=root;
    while(tmp!=nullptr){
        if(data>tmp->data)
            tmp=tmp->RightChild;
        else if(data<tmp->data)
            tmp=tmp->LeftChild;
        else
            return tmp;
    }
}
void Tree::remove(int data){
    TreeNode *tmp=search(data);
    if(tmp->ancester==nullptr){
        if(tmp->RightChild!=nullptr&&tmp->LeftChild==nullptr){
            root=tmp->RightChild;
            delete tmp;
        }
        if(tmp->RightChild==nullptr&&tmp->LeftChild!=nullptr){
            root=tmp->LeftChild;
            delete tmp;
        }
        if(tmp->RightChild!=nullptr&&tmp->LeftChild!=nullptr){
            root=tmp->RightChild;
            insertNode(&root,tmp->data,nullptr);   
            delete tmp;
        }
        if(tmp->RightChild==nullptr&&tmp->LeftChild==nullptr){
            root=nullptr;
        }
    }
    else{
        if(tmp==tmp->ancester->LeftChild){
            if(tmp->LeftChild==nullptr&&tmp->RightChild==nullptr){
                tmp->ancester->LeftChild=nullptr;
                delete tmp;
            }
            else if(tmp->LeftChild!=nullptr&&tmp->RightChild==nullptr){
                tmp->ancester->LeftChild=tmp->LeftChild;
                tmp->LeftChild->ancester=tmp->ancester;
                delete tmp;
            }
            else if(tmp->LeftChild==nullptr&&tmp->RightChild!=nullptr){
                tmp->ancester->LeftChild=tmp->RightChild;
                tmp->RightChild->ancester=tmp->ancester;
                delete tmp;
            }
            else{
                tmp->ancester->LeftChild=tmp->RightChild;
                tmp->ancester->LeftChild->ancester=tmp->ancester;
                insertNode(&(tmp->RightChild),&(tmp->LeftChild),tmp->ancester);
                delete tmp;
            }
        }
        else{
            if(tmp->LeftChild==nullptr&&tmp->RightChild==nullptr){
                tmp->ancester->RightChild=nullptr;
                delete tmp;
            }
            else if(tmp->LeftChild!=nullptr&&tmp->RightChild==nullptr){
                tmp->ancester->RightChild=tmp->LeftChild;
                tmp->LeftChild->ancester=tmp->ancester;
                delete tmp;
            }
            else if(tmp->LeftChild==nullptr&&tmp->RightChild!=nullptr){
                tmp->ancester->RightChild=tmp->RightChild;
                tmp->RightChild->ancester=tmp->ancester;
                delete tmp;
            }
            else{
                tmp->ancester->RightChild=tmp->LeftChild;
                tmp->ancester->RightChild->ancester=tmp->ancester;
                insertNode(&(tmp->RightChild),&(tmp->LeftChild),tmp->ancester);
                delete tmp;
            }
        }
    }
        
}
Tree& Tree::operator+(int data){
    insertNode(&root,data,nullptr);
    return *this;
}
void Tree::operator-(int data){
    remove(data);
}
TreeNode& Tree::operator[](int number){
    return GetNumber(number);
    
}
TreeNode& Tree::operator*(Tree& operand){
    vector<int> arry;
    arry=getArray(operand);
    int n=arry.size();
    for(int i=0;i<n;i++){
        *this+arry[i];
    }
}
TreeNode& Tree::operator/(Tree& operand){
    vector<int> arry;
    arry=getArray(operand);
    int n=arry.size();
    for(int i=0;i<n;i++){
        *this-arry[i];
    }
}
TreeNode& Tree::GetNumber(int number){
    RefreshArry(2);
    return *search(arry[number]);
}

void Tree::RefreshArry(int s){
    arry={};
    switch(s){
    case 1:    
        preorderVector(root);
        break;
    case 2:
        inorderVector(root);
        break;
    case 3:
        postorderVector(root);
        break;
    }
}
void Tree::deleteTree(){
    RefreshArry(2);
    int n=arry.size();
    for(int i=0;i<n;i++)
        remove(arry[i]);
}
vector<int>& Tree::getArray(Tree &operand){
    return operand.ReturnArray();
}
vector<int>& Tree::ReturnArray(){
    RefreshArry(2);
    return arry;
}
void Tree::LeftRotation(int data){
    TreeNode *tmp=search(data);
    if(tmp->ancester==tmp->ancester->ancester->LeftChild){
        if(tmp!=nullptr && tmp==tmp->ancester->RightChild){
            TreeNode* regi=tmp->ancester->ancester;
            tmp->ancester->RightChild=nullptr;
            insertNode(&(tmp->LeftChild),&(tmp->ancester),tmp);
            tmp->ancester=regi;
            tmp->ancester->LeftChild=tmp;
            
        }
    }
    else if(tmp->ancester==tmp->ancester->ancester->RightChild)
    {
        if(tmp!=nullptr && tmp==tmp->ancester->RightChild){
            TreeNode* regi=tmp->ancester->ancester;
            tmp->ancester->RightChild=nullptr;
            insertNode(&(tmp->LeftChild),&(tmp->ancester),tmp);
            tmp->ancester=regi;
            tmp->ancester->RightChild=tmp;
            
        }
    }
}
void Tree::RightRotation(int data){
    TreeNode *tmp=search(data);
    if(tmp->ancester==tmp->ancester->ancester->LeftChild){
        if(tmp!=nullptr && tmp==tmp->ancester->LeftChild){
            TreeNode* regi=tmp->ancester->ancester;
            tmp->ancester->LeftChild=nullptr;
            insertNode(&(tmp->RightChild),&(tmp->ancester),tmp);
            tmp->ancester=regi;
            tmp->ancester->LeftChild=tmp;
            
        }
    }
    else if(tmp->ancester==tmp->ancester->ancester->RightChild)
    {
        if(tmp!=nullptr && tmp==tmp->ancester->LeftChild){
            TreeNode* regi=tmp->ancester->ancester;
            tmp->ancester->LeftChild=nullptr;
            insertNode(&(tmp->RightChild),&(tmp->ancester),tmp);
            tmp->ancester=regi;
            tmp->ancester->RightChild=tmp;
            
        }
    }
}