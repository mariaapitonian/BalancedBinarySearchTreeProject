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
	struct node* parent;

}

struct tree
{
	element_type data;
	struct node* left;
	struct node* right;
}

struct node* node_create(element_type key, struct node* left, struct node* right, struct node* parent)
{
	//To do
}

struct tree* tree_create(element_type data, struct node* left, struct node* right)
{
	//To do
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
	}
	else{
		return maxright;
	}
	
}

void tree_insert()
{
	//To do
}

void tree_delete()
{
	//To do
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
