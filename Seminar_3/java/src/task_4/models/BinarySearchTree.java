package task_4.models;

/**
 * 
 * SOURCE CODE FOR THIS FILE: https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
 * 
 */


// Java program to demonstrate
// insert operation in binary
// search tree
public class BinarySearchTree {

	/** Class containing left
	and right child of current node
	* and key value*/
	class Node {
		int key;
		Node left, right;

		public Node(int item)
		{
			key = item;
			left = right = null;
		}
	}

	// Root of BST
	public Node root;

	// Constructor
	public BinarySearchTree() { root = null; }

	BinarySearchTree(int value) { root = new Node(value); }

	// This method mainly calls insertRec()
	public void insert(int key) { root = insertRec(root, key); }

	/* A recursive function to
	insert a new key in BST */
	Node insertRec(Node root, int key)
	{

		/* If the tree is empty,
		return a new node */
		if (root == null) {
			root = new Node(key);
			return root;
		}

		/* Otherwise, recur down the tree */
		else if (key < root.key)
			root.left = insertRec(root.left, key);
		else if (key > root.key)
			root.right = insertRec(root.right, key);

		/* return the (unchanged) node pointer */
		return root;
	}

	// This method mainly calls InorderRec()
	void inorder() { inorderRec(root); }

	// A utility function to
	// do inorder traversal of BST
	void inorderRec(Node root)
	{
		if (root != null) {
			inorderRec(root.left);
			System.out.println(root.key);
			inorderRec(root.right);
		}
	}
}
// This code is contributed by Ankur Narain Verma
