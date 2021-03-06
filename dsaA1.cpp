#include <iostream>
using namespace std;
struct Node
{
	int key;
	struct Node *left, *right;
};

Node *newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

bool isMirror(struct Node *root1, struct Node *root2)
{
	/* If both trees are empty,
	 then they are mirror images */
	if (root1 == NULL && root2 == NULL)
		return true;

	if (root1 && root2 && root1->key == root2->key)
		return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
	return false;
}

// Returns true if a tree is
// symmetric i.e. mirror image of itself
bool isSymmetric(struct Node *root)
{

	return isMirror(root, root); // Check if tree is mirror of itself
}

int main()
{

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(4);
	root->right->right = newNode(3);

	if (isSymmetric(root))
		cout << "\n\nThe tree is Symmetric\n\n\n\n";
	else
		cout << "\n\nThe Tree is Not symmetric\n\n\n\n";
	return 0;
}
