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

struct tree* tree_create(element_type rootval)
{
	struct tree* t = (struct tree*)malloc(sizeof(struct tree));
	t->start = NULL;
	return t;
}

int is_empty(struct tree* t)
/*returns a statement on whether or not the tree is empty*/
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


int tree_height(struct node* root)
/*function that calculates the tree's/subtree's height starting from passed node*/
{
	if(root == NULL){
		return 0;
	}

	int maxleft = 1;
	int maxright = 1;
	struct node* leftsub = node_create(1, NULL, NULL);
	struct node* rightsub = node_create(1, NULL, NULL);
	leftsub = root;
	rightsub = root;
	
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

element_type tree_minimum(struct node* n)
/*function that locates the minimum value in the tree/subtree*/
{
	struct node* min = n;
	while(min->left != NULL){ 
		min = min->left;
	}
	return min->key;
}

element_type tree_maximum(struct node* n)
/*function that locates the maximum value in the tree/subtree*/
{
	struct node* max = n;
	while(max->right != NULL){
		max = max->right;
	}
	return max->key;
}

char search_value_path(struct tree* t, element_type value)
/*returns the path to any node in the tree. Useful for other functions like boolean search, delete, find parent, etc*/
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
/*returns a boolean statement on whether a value exists in the tree*/
{
	char path[] = search_value_path(t, value);
	if(path==NULL){
		return false;
	}
	else{
		assert(path!=NULL);
		return true;
	}
}

struct node* find_parent(struct tree* t, struct node* n)
{
	char path[] == search_value_path(t, n->key);
	if(path[0]=="root" || path[0]==NULL){
		printf("The node has no parent");
		return 0;
	}

	for(int i=0; i<(sizeof(path)-1); i++){
		if(path[i]=="left "){
			parent = parent->left;
		}
		else if(path[i]=="right "){
			parent = parent->right;
		}
	}
	return parent;

}

void inorder_helper (struct node* n ) //(struct node* n)
/*inorder tree traversal*/
{
	printf("print tree \n");
	assert(NULL != n);
	if(n != NULL ){
		inorder(n->left);
		printf("%d \n",n->key);
		inorder(n->right);
    	}
}

void tree_inorder(struct tree* t)
{
	assert (NULL !=t);
	inorder_helper(t->root);
}


/*void preorder(struct tree* root)//preorder traversal
{
    assert(NULL != t)
    if( root != NULL){
        printf("%d",root->key);
        preorder(root->left);
        preorder(root->right);
       }
} 

void postorder(struct tree* root) //postorder traversal 
{
    assert(NULL != t)
    if(root !=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->key);
    }
} */

void single_rotation_lhelper(struct node* n)/* a single rotation from right to left at the root of T*/
{
	struct node* r  = n->right;
	n->right = r->left;
    
	r->left  = n;
	n = r;
}

void single_rotation_left(struct tree* t)
{
	assert (NULL !=t);
	single_rotation_left(t->root);
}

void single_rotation_rhelper(struct node* n)
/* singleRotateRight(T) performs a singlerotation from left to right at the root of T*/
{
	struct tree* l  = n->left;
	n->left  = l->right;

	l->right = n;
	n = r;
}

void single_rotation_right(struct tree* t)
{
	assert (NULL !=t);
	single_rotation_right(t->root);
}

/*Double rotation*/
void double_rotate_left(struct node* n)
{
	single_rotation_right(n->right);
	single_rotation_left(n);
}

void double_rotate_right(struct node* n)
{
	single_rotation_left(n->right);
	single_rotation_right(n);
}

//choosing a single or double rotation.
void rotate_left(struct tree* t)
{
	struct tree* r = t->right;
	int  h1 = tree_height(r->left);
	int  h2 = tree_height(r->right);

	if(h1 > h2){
      		single_rotation_left(struct tree* t);
    	}
    	else
    	{
      		double_rotate_left(struct tree* t);
   	}
	return;
}

void rotate_left(struct tree* t)
{
	struct tree* l = t->right;
	int  h1 = tree_height(l->left);
	int  h2 = tree_height(l->right);

    	if(h1 > h2)
    	{
      		single_rotation_right(t);
    	}
    	else
    	{
      		double_rotate_right(t);
    	}
	return;
}

void rebalance(struct tree* t)
{
	int maxleft = tree_height(t->left);
	int maxright = tree_height(t->right);

	if(maxright > (maxleft+1)){
      		rotate_left(t);
    	}
    	else if(maxleft > (maxright+1)) {
      		rotate_right(t);
    	}
    	/*else{
      		installHeight(t);
	}*/	
	return;
}

void tree_insert(struct tree* t, element_type value)
{
	if(search_value(value) == 1){
		printf("Value cannot be inserted as it already exists.");
		return 0;
	}
	
	struct node* insertpos = t->start;
	struct node* newnode = node_create(value, NULL, NULL);

	for(int i=0; i<tree_height(t); i++) {
		temp=insertpos;
		if(insertpos->key > value){
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
	rebalance(t);
	return;
}

int tree_delete(struct tree* t, element_type value)
{
	if(search_value(struct tree* t, element_type value) == false){
		printf("The value cannot be removed as it does not exist");
		return 0;
	}
	
	if(path[0] == "root"){
		int hl = tree_height(t->start->left);
		int hr = tree_height(t->start->right);
		struct node* newrootparent = NULL;
		if(hr>hl){
			newroot = tree_minimum(t->start->left);
			newrootparent = find_parent(newroot->key);
			newrootparent->left = NULL;
			struct node* rightsubtree = t->start->right;
			t->start = newroot;
			t->start->right = rightsubtree;
		}
		else{
			newroot = tree_maximum(t->start->right);
			newrootparent = find_parent(newroot->key);
			newrootparent->right = NULL;
			struct node* leftsubtree = t->start->left;
			t->start = newroot;
			t->start->left = leftsubtree;
		}
		rebalance(t);//root replaced, old leaf deleted, rebalanced
		return 1;
	}
	
	struct node* parent = find_parent(t, value);
	if(path[(sizeof(path)-1)] =="left "){
	//	parent->left... replace
	}
	else if(path[(sizeof(path)-1)]=="right "){
	//	parent->right... replace with new subtree
	}
	return 1;
}

int main()
{
    struct tree* a = tree_create();
    
}

