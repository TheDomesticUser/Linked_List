#include <iostream>
#include <vector>
#include <map>

template<class T>
struct Node
{
	T value;
	Node* next;

	Node() {
		next = nullptr;
	}
};

template<class T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	unsigned int length;

	Node<T>* traverseToIndex(const unsigned short& index);
public:
	LinkedList();
	~LinkedList();
	void append(const T& value);
	void prepend(const T& value);
	void insert(const unsigned short& index, const T& value);
	void remove(const unsigned short& index);
};

int main()
{
	LinkedList<int> nums;
	nums.append(5);
	nums.append(1);
	nums.append(3);
	nums.append(4);
	nums.remove(2);

	return 0;
}

template<class T>
LinkedList<T>::LinkedList()
{
	this->length = 0;
	head = new Node<T>;
	tail = head;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* bufferNode = head;
	Node<T>* nextNode = bufferNode->next;

	while (nextNode != nullptr) {
		delete bufferNode;
		bufferNode = nextNode;
		nextNode = nextNode->next;
	}
	delete bufferNode;
}

template<class T>
Node<T>* LinkedList<T>::traverseToIndex(const unsigned short& index)
{
	if (index >= this->length) return tail;

	Node<T>* currentNode = head;
	for (unsigned short i = 0; i < index; i++) {
		currentNode = currentNode->next;
	}
	return currentNode;
}

template<class T>
void LinkedList<T>::append(const T& value)
{
	if (length == 0) {
		head->value = value;
	} else {
		Node<T>* newNode = new Node<T>;
		newNode->value = value;
		tail->next = newNode;
		tail = newNode;
	}
	length++;
}

template<class T>
void LinkedList<T>::prepend(const T& value)
{
	Node<T>* newNode = new Node<T>;
	newNode->value = value;
	newNode->next = head;
	head = newNode;
}

template<class T>
void LinkedList<T>::insert(const unsigned short& index, const T& value)
{
	if (index >= this->length || index <= 0) return;

	Node<T>* before = this->traverseToIndex(index - 1);
	Node<T>* after = before->next;

	Node<T>* newNode = new Node<T>;
	newNode->value = value;
	newNode->next = after;

	before->next = newNode;

	this->length++;
}

template<class T>
void LinkedList<T>::remove(const unsigned short& index)
{
	Node<T>* before = this->traverseToIndex(index - 1);
	Node<T>* deletedNode = before->next;
	Node<T>* after = deletedNode->next;
	before->next = after;
	
	this->length--;
	delete deletedNode;
}
