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

struct tree* tree_create()
{
	//To do
}

void tree_insert()
{
	//To do
}

void tree_delete()
{
	//To do
}
