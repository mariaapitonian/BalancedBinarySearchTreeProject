#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int element_type;
typedef unsigned int size_type;

struct node
{
	element_type key;
	struct node* left;
	struct node* right;

}

struct tree
{
/*	element_type data;*/
	struct node* left;/* start*/
	struct node* right;/*end*/
}

struct node* node_create(element_type key, struct node* left, struct node* righ)
{
	struct node* n= (struct node*)malloc(sizeof(struct node);
                n->key = key;
                n->left = l;
                n->right = r;
               return n  
}

struct tree* tree_create(element_type data, struct node* left, struct node* right)
{   
    struct node* t = (struct node*)malloc(sizeof(struct node));
   /* t->data = data;*/
    t->left = NULL;
    t->right = NULL;
}
int tree_emty(struct tree* t)
{
    assert(NULL !=t);
    return t->right == NULL;
}
void inorder (struct tree* t)
/*inorder tree traversal*/
{
    if(t != NULL ){
        inorder( t->left);
        printf(%d,t->data);
        inorder(t ->right):
    }

}
void tree_insert(struct tree* t)
{
    if(node == NULL)
        return(T

}

void tree_delete()
{
}
int tree_height(struct tree* t)
{
	if(t->start == NULL){
		return 0;
	}

	int maxleft = 1;
	int maxright = 1;
	struct node* leftsub = node_create(1, NULL, NULL);
	struct node* rightsub = node_create(1, NULL, NULL);
	leftsub = t->start;
	rightsub = t->start;
	
	while(true){
		if(leftsub->left !== NULL){
			leftsub = leftsub->left;
			maxleft++;
		}
		else if(leftsub->right !== NULL){
			leftsub = leftsub->right;
			maxleft++;
		}
		else{
			break;
		}
	}
	while(true){
		if(rightsub->right !== NULL){
			rightsub = rightsub->right;
			maxright++;
		}
		else if(rightsub->left !== NULL){
			rightsub = rightsub->left;
			maxright++;
		}
		else{
			break;
		}
	}

	if(maxleft>maxright){
		return maxleft;
	
	else{
		return maxright;
	}
	
}


bool search_tree(struct tree* t, element_type value)
{
	root = t->start;
	char path[tree_height(t)] = {};
	int steps = 0;

	while(int i=0; i<tree_height(t); i++) {			//write function for height
		temp=root;
		if(root==value){
			if(steps=0){
				printf("The values exists at the root position");
			}
			else{
				printf("The value exists at position %s", path);
			}
			return 1;
		}
		else if((root<value) && (temp->left !== NULL)){
			root=root->left;
			path[steps]="left ";
			steps++;
		}
		else if((root<value) && (temp->right !== NULL)){
			root=root->right;
			path[steps]="right ";
			steps++;
		}
		else{
			printf("The value does not exist in the binary search tree");
			return 0;
		}
	}

}

