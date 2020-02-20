#include <vector>
using namespace std;
class TreeNode{
    public:
        TreeNode* LeftChild;
        TreeNode* RightChild;
        TreeNode* ancester;
      
        int data;
        TreeNode(int data):data(data){};
};
class Tree{
    public:
        TreeNode* root;
        
        
        Tree():root(0),arry({}){};
        ~Tree(){
            deleteTree();
        }
        
        int insertNode(TreeNode **start,int data,TreeNode *ancester);
        int insertNode(TreeNode **start,TreeNode** data,TreeNode *ancester);
        void LeftRotation(int data);
        void RightRotation(int data);

        void preorder();
        void inorder();
        void postorder();
       
        Tree& operator+(int data);
        void operator-(int data);
        TreeNode& operator[](int number);
		TreeNode& operator*(Tree& operand);
        TreeNode& operator/(Tree& operand);

        TreeNode* search(int data);
        void remove(int data);
        void deleteTree();
        
        TreeNode& GetNumber(int number);
		vector<int>& getArray(Tree &operand);
		vector<int>& ReturnArray();
         
    private:
        void preorderVector(TreeNode *start);
        void inorderVector(TreeNode *start);
        void postorderVector(TreeNode *start);
        void RefreshArry(int s);
		vector<int> arry;
};