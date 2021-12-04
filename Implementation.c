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
	size_type n;
	struct node* start;
};

struct node* node_create(element_type key, struct node* l, struct node* r)
{
	struct node* n=(struct node*)malloc(sizeof(struct node));
	n->key = key;
        n->left = l;
	n->right = r;
        return n;
}

struct tree* tree_create(element_type defval, size_type n)
{
	struct tree* t = (struct tree*)malloc(n*(sizeof(struct tree)));
	struct node* root = create_node(defval, NULL, NULL);
	t->start = root;
	
	for(int i=0; i<(log10(n)/log10(2)-1); i++){
		struct node* current = create_node(defval, NULL, NULL); 
		root->left=current;
		
	return t;
}

int tree_empty(struct tree* t)
{
	assert(NULL !=t);
	return t->right == NULL;
}

int is_empty(struct tree* t)
{
	if(t->start == NULL){
		printf("The tree is empty");
		return 1;
	}
	else{
		printf("The tree is not empty");
		return 0;
	}
}

void inorder (struct node* root) //(struct node* n)
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
	leftsub = t->start;
	rightsub = t->start;
	
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
	
	else{
		return maxright;
	}
	
}

element_type minimum_node(struct tree* t)
{
	struct node* min = t->start;
/*	for(int i=0; i<tree_height(t); i++){
 *		if(min->left !== NULL) {......}}*/
	while(min->left != NULL){ 
		min = min->left;
	}
	return min->key;
}

element_type tree_maximum(struct tree* t)
{
	struct node* max = t->start;
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
	struct node* root = t->start;
	char path[tree_height(t)] = {};
	int steps = 0;

	for(int i=0; i<tree_height(t); i++) {
		temp=root;
		if(root->key==value){
			if(steps=0){
				printf("The values exists at the root position");
				path[steps]="root";
			}
			else{
				printf("The value exists at position %s", path);
			}
			return path;
		}
		else if((root->key>value) && (temp->left !== NULL)){
			root=root->left;
			path[steps]="left ";
			steps++;
		}
		else if((root->key<value) && (temp->right !== NULL)){
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
	struct node* insertpos = t->start;
	struct node* newnode = node_create(value, NULL, NULL);

	for(int i=0; i<tree_height(t); i++) {
		temp=insertpos;
		if(insertpos->key >= value){
			if(insertpos->right==NULL){
				insertpos->right==newnode;
				break;
			}
			else{
				insertpos=insertpos->right;
			}
		}
		else if(insertpos->key < value){
			if(insertpos->left==NULL){
				insertpos->left==newnode;
				break;
			}
			else{
				insertpos=insertpos->left;
			}
		}
	}

	//new node inserted, tree unbalanced
	//check and perform rotations
}


int tree_delete(struct tree* t, element_type value)
{
	char path[] = search_value_path(struct tree* t, element_type value);
	if(path[0] == NULL){
		printf("The value cannot be removed as it does not exist");
		return 0;
	}
	
	if(path[0] == "root"){
		struct node* templeft = t->start->left;
		struct node* tempright = t->start->right;
		struct node* newroot = node_create(0, NULL, NULL);
		struct node* previous = node_create(0, NULL, NULL);
		newroot=t->start->left;
		previous

		for(int i=1; i<(tree_height(t)-1); i++){	//finding the largest element in the left subtree to replace root
			if(newroot->right != NULL){
				previous = newroot;
				newroot->right;
			}
		}
		//root replaced, old leaf deleted, now check and perform appropriate rotation to balance the tree
		return 1;
	}

	for(int i=0; i<sizeof(path); i++){
		if(path[i]=="left "){
			current = current->left;
		}
		else if(path[i]=="right "){
			current = current->right;
		}	
		else{
			break;
		}	//else if (cover all cases and relate appropriate rotation to position)
	}

	return 1;
	//To do
}


