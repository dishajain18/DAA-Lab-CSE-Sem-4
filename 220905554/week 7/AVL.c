    #include <stdio.h>  
    #include <stdlib.h>  
       
    struct Node  
    {  
        int key;  
        struct Node *left;  
        struct Node *right;  
        int height;  
    };  
       
    int getHeight(struct Node *n){  
        if(n==NULL)  
            return 0;  
        return n->height;  
    }  
       
    struct Node *createNode(int key){  
        struct Node* node = (struct Node *) malloc(sizeof(struct Node));  
        node->key = key;  
        node->left = NULL;  
        node->right = NULL;  
        node->height = 1;  
        return node;  
    }  
       
    int max (int a, int b){  
        return (a>b)?a:b;  
    }  
       
    int getBalanceFactor(struct Node * n){  
        if(n==NULL){  
            return 0;  
        }  
        return getHeight(n->left) - getHeight(n->right);  
    }  
       
    struct Node* rightRotate(struct Node* y){  
        struct Node* x = y->left;  
        struct Node* T2 = x->right;  
       
        x->right = y;  
        y->left = T2;  
       
        x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
        y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  
       
        return x;  
    }  
       
    struct Node* leftRotate(struct Node* x){  
        struct Node* y = x->right;  
        struct Node* T2 = y->left;  
       
        y->left = x;  
        x->right = T2;  
       
        x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
        y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  
       
        return y;  
    }  
       
    struct Node *insert(struct Node* node, int key){  
        if (node == NULL)  
            return  createNode(key);  
       
        if (key < node->key)  
            node->left  = insert(node->left, key);  
        else if (key > node->key)  
            node->right = insert(node->right, key);  
       
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));  
        int bf = getBalanceFactor(node);  
       
        // Left Left Case  
            if(bf>1 && key < node->left->key){  
                return rightRotate(node);  
            }  
        // Right Right Case  
            if(bf<-1 && key > node->right->key){  
                return leftRotate(node);  
            }  
        // Left Right Case  
        if(bf>1 && key > node->left->key){  
                node->left = leftRotate(node->left);  
                return rightRotate(node);  
            }  
        // Right Left Case  
        if(bf<-1 && key < node->right->key){  
                node->right = rightRotate(node->right);  
                return leftRotate(node);  
            }  
        return node;  
    }  
       
    void search(struct Node* root,int key)
    {
    // set pre and suc as NULL initially
    struct Node* pre = NULL;
    struct Node* suc = NULL;
 
    // set temp node as root
    struct Node* temp1 = root;
    while (temp1) {
        // the maximum value in left subtree is successor
        if (temp1->key > key) {
            suc = temp1;
            temp1 = temp1->left;
        }
        else
            temp1 = temp1->right;
    }
    struct Node* temp2 = root;
    while (temp2) {
        // the minimum value in right subtree is predecessor
        if (temp2->key < key) {
            pre = temp2;
            temp2 = temp2->right;
        }
        else
            temp2 = temp2->left;
    }
    
      if(pre)
        printf("Predecessor: %d\n",pre->key);
      else
        printf("No Predecessor\n");
        
      if(suc)
        printf("Successor: %d\n",suc->key);
      else
        printf("No Successor\n");
    }
    void preOrder(struct Node *root)  
    {  
        if(root != NULL)  
        {  
            printf("%d ", root->key);  
            preOrder(root->left);  
            preOrder(root->right);  
        }  
    }  
       
    int main(){  
        struct Node * root = NULL;  
        int x;
        printf("Enter the elements: (-99 to exit)\n");
        while(1)
        { 
          scanf("%d",&x);
          if(x==-99)
           break;
          root = insert(root,x);
        }
        
        printf("Preorder: ");
        preOrder(root);
        printf("\nFind? ");
        scanf("%d",&x);
        search(root,x);
        return 0;  
    }  
