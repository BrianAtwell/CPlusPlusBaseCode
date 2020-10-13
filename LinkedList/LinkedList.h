/*
 * Author: Brian Atwell
 * File: LinkedList.h
 * Description: A basic C++ implementation of a Linked List.
 */

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

/*
 * Description: A basic C++ implementation of a Linked List.
 */
template<typename T>
class LinkedList
{
private:
	/*
	* Description: A struct for a node for a linkedlist.
	* A node is simply a data struct that contains a data storage element and
	* a pointer that the same data structure.
	*/
	template <typename T>
	struct Node
	{
		// Data to be stored
		T data;
		// Pointer to next node
		Node<T>* next;

		Node(T lData, Node<T>* lNode)
		{
			data = lData;
			next = lNode;
		}

		Node(Node<T>* lNode)
		{
			next = lNode;
		}
	};

	// Root node, start of list
	Node<T>* root;

public:
	LinkedList() : end(nullptr), root(nullptr)
	{
	}

	/*
	 *
	 */
	void DeleteNode(Node<T>* node)
	{
		if (node != nullptr)
		{
			delete node;
		}
	}

	Node<T>* NewNode(T lData, Node<T>* lNode)
	{
		return new Node<T>(lData, lNode);
	}

	~LinkedList()
	{
		Node<T>* curNode = root;
		Node<T>* nextNode = root;

		root = nullptr;

		while (curNode != end)
		{
			nextNode = curNode.next;
			DeleteNode(curNode);
			curNode = nextNode;
		}

	}

	/*
	 * Description: Push data to front of list
	 */
	void Push(T data)
	{
		if (root == nullptr)
		{
			root = NewNode(data, nullptr);
		}
		else
		{
			Node<T>* newNode = NewNode(data, curNode);

			if (newNode != nullptr)
			{
				Node<T>* curNode = root;
				root = NewNode(data, curNode);
			}
		}
	}

	/*
	* Description: pop/remove data from back of list
	*/
	void Pop()
	{
		if (root != nullptr)
		{
			Node<T>* curNode = root;
			Node<T>* prevNode = root;
			while (curNode != nullptr)
			{
				if (curNode.next == nullptr)
				{
					break;
				}
				prevNode = curNode;
				curNode = curNode.next;
			}
			if (prevNode != nullptr)
			{
				if (prevNode == curNode)
				{
					DeleteNode(root);
					root = nullptr;
				}
				else
				{
					DeleteNode(curNode);
					curNode = nullptr;
					prevNode.next = nullptr;
				}
			}

		}
	}

};

#endif

