#include <stdio.h>
#include <stdlib.h>

typedef struct tree {

	int value;
	struct tree *left;
	struct tree *right;

} tree;

void print_tree(tree *root){
	if (!root) return;
	if (root->left && root->right){
		printf("(");
		print_tree(root->left);
		printf(" %d ",root->value);
		print_tree(root->right);
		printf(")");
	}else if (root->left){
		printf("(");
		print_tree(root->left);
		printf(" %d .)",root->value);
	}else if (root->right){
		printf("(. %d ",root->value);
		print_tree(root->right);
		printf(")");
	}else{
		printf("%d",root->value);
	}
}

tree *reverse_binary_tree(tree *root) {
	if (!root) return root;
	tree *r = root->right;
	tree *l = root->left;
	root->left = reverse_binary_tree(r);
	root->right = reverse_binary_tree(l);
	return root;
}

int main(void){
	tree t1 = {1, NULL, NULL};
	tree t0 = {0, NULL, &t1};
	tree t3 = {3, NULL, NULL};
	tree t2 = {2, &t0, &t3};
	tree t6 = {6, NULL, NULL};
	tree t5 = {5, NULL, &t6};
	tree t4 = {4, &t2, &t5};

	print_tree(&t4);
	printf("\n");
	tree *new_tree = reverse_binary_tree(&t4);
	print_tree(new_tree);
	printf("\n");
}
