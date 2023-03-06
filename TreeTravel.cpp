#include <iostream>
using namespace std;

template <class T> class Stack {
private:
  T *data;
  int top;
  int capacity;

public:
  Stack(int capacity = 2) {
    if (capacity < 0)
      throw "capacity must > 0";
    data = new T[capacity];
    this->capacity = capacity;
    top = -1;
  }
  ~Stack() {
    delete[] data;
    top = -1;
  }
  bool isEmpty() { return top == -1 ? true : false; }
  void push(T input) {
    if (top == capacity - 1) {
      cout << "\n<Stack is full... trying to load bigger Stack>\n";
      T *temp = new T[capacity + 10];
      for (int i = 0; i < capacity; i++) {
        temp[i] = data[i];
      }
      capacity += 10;
      delete[] data;
      data = temp;
    }
    top += 1;
    data[top] = input;
  };
  T pop() {
    if (isEmpty())
      throw "Stack is empty";
    return data[top--];
  };
};

template <class T> class Tree;
template <class T> class TreeNode {
  friend class Tree<T>;

private:
  TreeNode<T> *leftchild;
  TreeNode<T> *rightchild;
  T data;
  TreeNode<T>(T data, TreeNode<T> *leftchild = NULL,
              TreeNode<T> *rightchild = NULL) {
    this->leftchild = leftchild;
    this->rightchild = rightchild;
    this->data = data;
  }
};

template <class T> class Tree {
private:
  TreeNode<T> *root;
  void recurInorder(TreeNode<T> *node);
  void stackInorder(TreeNode<T> *node);

public:
  void buildTestTree();
  void recurInorder();
  void stackInorder();
  void nonStackInorder();
};

template <class T> void Tree<T>::recurInorder() { recurInorder(root); }

template <class T> void Tree<T>::recurInorder(TreeNode<T> *node) {
  if (!node)
    return;
  recurInorder(node->leftchild);
  cout << node->data << "   ";
  recurInorder(node->rightchild);
}

template <class T> void Tree<T>::buildTestTree() {
  this->root = new TreeNode<T>(
      6, new TreeNode<T>(4, new TreeNode<T>(3), new TreeNode<T>(5)),
      new TreeNode<T>(8, new TreeNode<T>(7), new TreeNode<T>(9)));
}

template <class T> void Tree<T>::stackInorder() { stackInorder(root); }

template <class T> void Tree<T>::stackInorder(TreeNode<T> *node) {
  Stack<TreeNode<T> *> nodeStack;
  TreeNode<T> *currentNode = root;
  while (1) {
    while (currentNode) {
      nodeStack.push(currentNode);
      currentNode = currentNode->leftchild;
    }
    if (nodeStack.isEmpty())
      return;
    currentNode = nodeStack.pop();
    cout << currentNode->data << "   ";
    currentNode = currentNode->rightchild;
  }
}
int main() {
  Tree<int> *tree = new Tree<int>;
  cout << "building test tree...\n";
  tree->buildTestTree();
  cout << "\nrecursive Inorder...\n";
  tree->recurInorder();
  cout << "\nstack Inorder...\n";
  tree->stackInorder();
}
