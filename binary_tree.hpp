
/*******************************************************

 ----------Binary Search tree class-----------
   
 
   Coder      =  Nahit Pawar
		 MTech - Electronic Systems - Electrical Dept.	
		 Indian Institute of Technology Bombay 
   
   Class name  =  tree
      
   Last modified  = 16/Sept/2012
   


*******************************************************/


#include <iostream>

using namespace std;

template <typename T>
struct node
{
 T info;
 node *father;
 node *left;
 node *right;

 node()
 {
  this->father = NULL;
  this->left = NULL;
  this->right = NULL;
 }

 node(const T& info)
 {
  this->info = info;
  this->father = NULL;
  this->left = NULL;
  this->right = NULL;
 }

};


template <typename T>
class tree
{

 protected:
 
 node<T>* root;


// preorder traversal
 void pre_trav(node<T>* tree) const;
 
// inorder traversal
 void in_trav(node<T>* tree) const;
 
// postorder traversal
 void post_trav(node<T>* tree) const;
 
 



 public:

 tree();
 node<T> *create_node(const T info);        // create new tree node 
 void setleft(node<T>* p, const T info);    // create left child of father p
 void setright(node<T>* p, const T info);   // create right child of father p
 
 node<T> *left(node<T>* p);           // return pointer of left son of father p
 node<T> *right(node<T>* p);          // return pointer of right son of father p
 node<T> *father(node<T>* q);         // return pointer of father of son q 

 bool isleft(node<T>* q);             // is q the left son of its father node(nd)
 bool isright(node<T>* q);            // is q the right son of its father node(nd)

 void insert(const T& info);          // insert element into tree
 void remove(const T& info);          // remove element from tree
 node<T>* search(const T& info);      // search element and return its address, if not found return NULL
  
 void preorder();                     // preorder traversal
 void inorder();                      // inorder traversal
 void postorder();                    // postorder traversal

};


// PRIVATE MEMBER FUNCTIONS DEFINITIONS


// preorder traversal
template <typename T>
void tree<T>::pre_trav(node<T>* tree) const
  {
   if(tree != NULL)
    {
     cout<<tree->info<<",";
     pre_trav(tree->left);
     pre_trav(tree->right);     
    }
  }

// inorder traversal
template <typename T>
void tree<T>::in_trav(node<T>* tree) const
  {
   if(tree != NULL)
    {
     in_trav(tree->left);
     cout<<tree->info<<",";
     in_trav(tree->right);
    }
  }

//postorder traversal
template <typename T>
void tree<T>::post_trav(node<T>* tree) const
  {
   if(tree != NULL)
    {
     post_trav(tree->left);
     post_trav(tree->right);
     cout<<tree->info<<",";
    }
  }

// search element and return its address, if not found return NULL
template <typename T>
node<T>* tree<T>::search(const T& info)
{
  node<T>* temp = root;
  
  if(root == NULL)
  {
    cout<<"Tree is empty"<<endl;
  }
  else
  {
    while(temp != NULL)
    {
      if(info == temp->info)
      {
	return temp;
      }
      else if(info > temp->info)
      {
	temp = right(temp);
      }
      else
      {
	temp = left(temp);
      }
    }
  }
  
  return NULL;
}
  
  
// PUBLIC MEMBER FUNCTIONS DEFINITIONS


// constructor
template <typename T>
tree<T>::tree()
{
 root = NULL;
}

// create single node for tree
template <typename T>
node<T> *tree<T>::create_node(const T info)
{
 node<T>* p;
  
 p = new node<T>(info);

 return p;
}

// creates a new left son of father p
template <typename T>
void tree<T>::setleft(node<T>* p, const T info)
{
 node<T>* left;
 
 left = new node<T>(info);
 
 if(p == NULL)
 {
  cout<<endl<<"Error : Void Insertion "<<endl;
 }
 else if(p->left != NULL)
  {
   cout<<endl<<"Error: Invalid Insertion "<<endl;
  }
 else
  {
   p->left = left;
   left->father = p;
  }

}

// creates a new right son of father p
template <typename T>
void tree<T>::setright(node<T>* p, const T info)
{
 node<T>* right;
 
 right = new node<T>(info);

 if(p == NULL)
  {
   cout<<"Error: Void insertion";
  }

 else if(p->right != NULL)
  {
   cout<<"Error: Invalid insertion";
  }

 else
  {
   p->right = right;
   right->father = p; 
  }
}

// return pointer of left son of father p
template <typename T>
node<T> *tree<T>::left(node<T>* p)
{
 return p->left;
}

// return pointer of right son of father p
template <typename T>
node<T> *tree<T>::right(node<T>* p)
{
 return p->right;
}

// return pointer of father of son q
template <typename T>
node<T> *tree<T>::father(node<T>* q)
{
  if(q == root) return NULL;
  else
  {
   return q->father;
  }
}

// check if q is left son of its father node(nd)
template <typename T>
bool tree<T>::isleft(node<T>* q)
{
 node<T>* p;
 p = father(q);
 if(p == NULL) return false;          // if q is root
 else if(left(p) == q) return true;  
 else return false; 
}

// check if q is right son of its father node(nd)
template <typename T>
bool tree<T>::isright(node<T>* q)
{
 node<T>* p;
 p = father(q);
 if(p == NULL) return false;          // if q is root
 else if(right(p) == q) return true;
 else return false;
}


// insert element into tree
template <typename T>
void tree<T>::insert(const T& info)
{
 node<T>* temp = root;                 // intialize temp to root value
 node<T>* leaf;

 if(root == NULL)                      // what if tree is empty ?
  {
   root = create_node(info);     
  }
 else
  {
   while(temp != NULL)
    {
     if(info == temp->info)
     {
       cout<<"Dublicate entry not allowed"<<endl;
       break;
     }
     if(info > temp->info)            //  Go to right
      {
       leaf = temp;
       temp = right(temp); 
       if(temp == NULL)
        {
         setright(leaf,info);
        }          
      }
     else                              // Go to left
      {
       leaf = temp;
       temp = left(temp);
       if(temp == NULL)
        {
         setleft(leaf,info);
        }
      }

    }
  }
}

// remove element into tree
template <typename T>
void tree<T>::remove(const T& info)
{
  node<T>* temp = search(info);
  node<T>* s_n = temp;
  
  if(temp == NULL)
  {
    cout<<"Element not found"<<endl;
  }
  else
  {
    
    if(temp->left == NULL && temp->right == NULL)            // deleting victim of degree 0 (leaf node)
    {
      s_n = temp->father;
      if(s_n == NULL)
      {
	delete temp;
	root = NULL;
      }
      else if(isleft(temp))                                       // victim is left son of his father
      {
	s_n->left = NULL;
	delete temp;
      }
      else                                                   // victim is right son of his father
      {
	s_n->right = NULL;
	delete temp;
      }      
    }
    
    
    
    else if(temp->left == NULL || temp->right == NULL)      // deleting victim of degree 1
    {
      if(temp->left == NULL)                                // victim has no left son
      {
	s_n = temp->right;
	if(temp->father == NULL)                            // victim is root node    
	{
	  root = s_n;
	  root->father = NULL;
	  delete temp;
	}
	else if(isleft(temp))                                    // victim is left son of his father
	{
	  father(temp)->left = s_n;
	  s_n->father = father(temp);
	  delete temp;
	}
	else                                                // victim is right son of his father
	{
	 father(temp)->right = s_n; 
	 s_n->father = father(temp);
	 delete temp;
	}
      }
      else                                                  // victim has no right son
      {
	s_n = temp->left;
	if(temp->father == NULL)                            // victim is root node
	{
	  root = s_n;
	  root->father = NULL;
	  delete temp;
	}
	else if(isleft(temp))                                    // victim is left son of his father
	{
	  father(temp)->left = s_n;
	  s_n->father = father(temp);
	  delete temp;
	}
	else                                                // victim is right son of his father
	{
	  father(temp)->right = s_n;
	  s_n->father = father(temp);
	  delete temp;
	}
      }
    }
    
    
    
    else                     // deleting victim of degree 2 by replacing it with smallest element in right subtree
     {
      s_n = s_n->right;                                     // go to right son
      
      while(left(s_n) != NULL)                              // go left until smallest element found            
      {
	s_n = s_n->left;
      }
      
       if(s_n->right == NULL)                               // reached leaf node
	{
	  temp->info = s_n->info;
	  if(isleft(s_n))                                   // leaf node is left son
	  {
	    father(s_n)->left = NULL;
	    delete s_n; 
	  }
	  else                                              // leaf node is right son
	  {
	    father(s_n)->right = NULL;
	    delete s_n;
	  }
	}
	
	else                                                // reached node having right son
	{
	  temp->info = s_n->info;
	  if(isleft(s_n))                                   // node is left son
	  {
	    father(s_n)->left = right(s_n);
	    right(s_n)->father = father(s_n);
	    delete s_n;
	  }
          else                                              // node is right son
	  {
	    father(s_n)->right = right(s_n);
	    right(s_n)->father = father(s_n);
	    delete s_n;
	  }
	}           
      
     }
    
  }
   
}


// preorder traversal
template <typename T>
void tree<T>::preorder()
{
 node<T>* temp = root;
 cout<<"Pre order path = ";
 pre_trav(temp);
 cout<<endl;
}

// inorder traveral
template <typename T>
void tree<T>::inorder()
{
 node<T>* temp = root;
 cout<<"In order path = ";
 in_trav(temp);
 cout<<endl;
}

// posorder traversal 
template <typename T>
void tree<T>::postorder()
{
 node<T>* temp = root;
 cout<<"Post order path = ";
 post_trav(temp);
 cout<<endl;
}


