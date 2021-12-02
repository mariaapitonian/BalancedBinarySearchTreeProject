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
};

struct tree
{
/*	element_type data;*/
	struct node* left;/* start*/
	struct node* right;/*end*/
};

struct node* node_create(element_type key, struct node* l, struct node* r)
{
	struct node* n= (struct node*)malloc(sizeof(struct node));
	n->key = key;
        n->left = l;
	n->right = r;
        return n;
}

struct tree* tree_create(element_type data, struct node* left, struct node* right)
{
	struct node* t = (struct node*)malloc(sizeof(struct node)); //should we pass the size n to the function?
	/* t->data = data;*/
	t->left = NULL; //= left; (or remove left and right from function definition
	t->right = NULL; 
	return t;
}

int tree_empty(struct tree* t)
{
	assert(NULL !=t);
	return t->right == NULL;
}

int is_empty(struct tree* t)
{
	if(t->data == NULL){
		printf("The tree is empty");
		return 1;
	}
	else{
		printf("The tree is not empty");
		return 0;
	}
}

void inorder (struct tree* t) //(struct node* n)
/*inorder tree traversal*/
{
	if(t != NULL ){
		inorder(t->left);
		printf("%d \n",t->data);
		inorder(t->right):
    	}

}

int tree_height(struct tree* t)
{
	if(t->data == NULL){
		return 0;
	}

	int maxleft = 1;
	int maxright = 1;
	struct node* leftsub = node_create(1, NULL, NULL);
	struct node* rightsub = node_create(1, NULL, NULL);
	leftsub = t->left;
	rightsub = t->right;
	
	while(true){
		if(leftsub->left != NULL){
			leftsub = leftsub->left;
			maxleft++;
		}
		else if(leftsub->right != NULL){
			leftsub = leftsub->right;
			maxleft++;
		}
		else{
			break;
		}
	}
	while(true){
		if(rightsub->right != NULL){
			rightsub = rightsub->right;
			maxright++;
		}
		else if(rightsub->left != NULL){
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

element_type minimum_node(struct tree* t)
{
	struct node* min = t->left;
/*	for(int i=0; i<tree_height(t); i++){
 *		if(min->left !== NULL) {......}}*/
	while(min->left != NULL){ 
		min = min->left;
	}
	return min->key;
}

element_type tree_maximum(struct tree* t)
{
	struct node* max = t->right;
	while(max->right != NULL){
		max = max->right;
	}
	return max->key;
}

char node_isleft_or_isright(struct tree* t, struct node* n)
{
	//To do
	//if....
		//return "left";
	//else....
		return "right";
}

char search_value_path(struct tree* t, element_type value)
{
	struct node* root = t->start; //???t->left?
	char path[tree_height(t)] = {};
	int steps = 0;

	for(int i=0; i<tree_height(t); i++) {
		temp=root;
		if(root==value){
			if(steps=0){
				printf("The values exists at the root position");
				path[steps]="root";
			}
			else{
				printf("The value exists at position %s", path);
			}
			return path;
		}
		else if((root>value) && (temp->left !== NULL)){
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
			return path*;
		}
	}
}

bool search_value(struct tree* t, element_type value)
{
	char path[] = search_value_path(t, value);
	if(path==NULL){
		return 0;
	}
	else{
		assert(path!=NULL);
		return 1;
	}
}

void tree_insert(struct tree* t, element_type value)
{
	if(node == NULL){
	
	}
	return(T

}

int tree_delete(struct tree* t, element_type value)
{
	char path[] = search_value_path(struct tree* t, element_type value);
	if(path[0] == NULL){
		printf("The value cannot be removed as it does not exist");
		return 0;
	}
	
	for(int i=0; i<sizeof(path); i++){
		if(path[i]=="root"){
			//delete root and perform appropriate rotation
		}
		//else if (cover all cases and relate appropriate rotation to position)
	}

	return 1;
	//To do
}


