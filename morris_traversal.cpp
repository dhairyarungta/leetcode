#include <bits/stdc++.h>
using namespace std;
//inorder morris traversal

class tNode
{
public :
    tNode*left = nullptr;
    tNode*right= nullptr;
    int data ;

    tNode(int data):data(data)
    {}
}

void MorrisTraversalInorder(tNode* root)
{
    tNode* current ;
    tNode* pre;

    if(root==nullptr)
        return;
    
    current = root;
    while(current!=nullptr)
    {
        if(current->left==nullptr)
        {
            cout<<current->data<<" ";
            current = current->right;
        }
        else
        {
            pre = current->left;
            //finding the rightmost element in the left subtree of current
            // or node wiht link back to current
            while(pre->right!=nullptr && pre->right ==current)
            {
                pre = pre->right;
            }

            if(pre->right ==nullptr)
            {
                pre->right = current;
                current = current->left;

            } 
            else            
            {
                pre->right = nullptr;
                cout<<current->data<<" ";
                current = current->right;
            }
        }
    }
}

int main(){

}


