#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data = val;
        left  = NULL;
        right = NULL;
    }
};

// The function signature is correct for reference to pointer
Node* buildBST(int val, Node* &root){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    else{
        if(val < root->data){
            root->left = buildBST(val, root->left);
        }
        else{
            root->right = buildBST(val, root->right);
        }
    }
    return root;
}
void preorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
void postorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

Node* createTree(){
    cout << "Enter the value" << endl;
    int val;
    cin >> val;
    Node* root  =  NULL;
    while(val != -1){
        buildBST(val, root);
        cout << "Enter the value" << endl;
        cin >> val;
    }
    return root;
}

void levelOrder(Node* root){
    if(root == NULL) return; // Prevent printing if root is null
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front = q.front(); q.pop();
        if(front == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << front->data << " ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}
bool searchBST(Node* root,  int target){
    if( root == NULL){
        return false;
    }
    if( root->data == target){
        return true;
        
}
else{
    if( target < root->data){
    bool leftAns = searchBST(root->left,target);
    if(leftAns== true){
        return true;
    }
}
    else{
        bool rightAns = searchBST(root->right,target);
        if(rightAns == true){
            return true;
            }
}
}
return false;
}
int main(){
    Node* root = createTree();
    levelOrder(root);
    bool ans = searchBST(root,200);
    cout<<ans<<endl;
    return 0;
}
