// AVL a self balancing binary search tree
#include <iostream>
#include "../pair/ft_pair.hpp"

template <typename T>
struct avlNode {
    typedef T value_type;
    T data;
    bool isEnd;
    bool isLeft;
    avlNode* left;
    avlNode* right;
    avlNode* parent;

   public:
    bool End() { return isEnd; }
    avlNode(avlNode* parent)
        : data(T()),
          isEnd(true),
          isLeft(false),
          left(NULL),
          right(NULL),
          parent(parent) {}
    avlNode(const T& data)
        : data(data),
          isEnd(false),
          isLeft(false),
          left(NULL),
          right(NULL),
          parent(NULL) {}

    static avlNode* Next(avlNode* current) {
        assert(current != NULL);
        if (current->left == NULL)
            return current;
        return Next(current->left);
    }

    static avlNode* Top(avlNode* current) {
        assert(current != NULL);
        if (current->parent == NULL)
            return current;
        return Top(current->parent);
    }

    static avlNode* Next(avlNode* current, avlNode* prev) {
        assert(current != NULL);
        std::cout << "current " << current->data << '\n';
        if (!current->left && !current->right && current->isLeft) {
            std::cout << "c1\n";
            return current->parent;
        }
        if (!current->left && !current->right && !current->isLeft) {
            std::cout << "c2\n";
            return Top(current->parent);
        }
        if (prev->isLeft && current->right) {
            std::cout << "c3\n";
            return Next(current->right);
        }
        if (current->right) {
            std::cout << "c4\n";
            return current->right;
        }
        std::cout << "c5\n";

        return NULL;
    }
};

template <class T,
          class Cmp = std::less<T>,
          class Alloc = std::allocator<avlNode<T> > >
class AVL {
    typedef avlNode<T> Node;

   public:
    typedef Node rebind_type;
    typedef Node* node;
    typedef size_t size_type;
    typedef T value_type;

   private:
    void print(node head, size_t depth = 0) const {
        if (head == nullptr) {
            return;
        }
        print(head->right, depth + 1);
        std::cout << std::string(depth, '\t') << head->data << " "
                  << head->isLeft << "\n\n";
        print(head->left, depth + 1);
    }

    node left_rotate(node head) {
        head->isLeft = true;
        node tmp = head->parent;
        head->parent = head->right;
        if (head->right)
            head->right->parent = tmp;
        node temp = head->right;
        head->right = temp->left;
        temp->left = head;
        return temp;
    }

    node right_rotate(node head) {
        head->isLeft = false;
        node tmp = head->parent;
        head->parent = head->left;
        if (head->left)
            head->left->parent = tmp;
        node temp = head->left;
        head->left = temp->right;
        temp->right = head;
        return temp;
    }

    node right_left_rotate(node head) {
        head->left->isLeft = false;
        head->right = right_rotate(head->right);  // parent
        return left_rotate(head);                 // grandparent
    }

    node left_right_rotate(node head) {
        head->left->isLeft = true;
        head->left = left_rotate(head->left);  // parent
        return right_rotate(head);             // grandparent
    }
    size_type getMaxLen(const node head) const {
        if (head == NULL)
            return 0;
        return 1 + std::max(getMaxLen(head->left), getMaxLen(head->right));
    }

    node theLeftest(node head) {
        if (head == NULL)
            return NULL;
        if (head->left == NULL)
            return head;
        return theLeftest(head->left);
    }

    node theRightest(node head) {
        if (head == NULL)
            return NULL;
        if (head->right == NULL)
            return head;
        return theRightest(head->right);
    }

    node inOrderSuccessor(node head) {
        if (head == NULL)
            return NULL;
        return theRightest(head->left);
    }

    node inOrderPredecessor(node head) {
        if (head == NULL)
            return NULL;
        return theLeftest(head->right);
    }

    node balance(node& head) {
        int left = getMaxLen(head->left), right = getMaxLen(head->right);
        int diff = abs(left - right);
        if (diff <= 1)
            return head;
        if (left > right) {
            node llc = head->left->left;
            if (llc)
                return right_rotate(head);
            return left_right_rotate(head);
        }
        node rrc = head->right->right;
        if (rrc)
            return left_rotate(head);
        return right_left_rotate(head);
    }

    ft::pair<node, bool> insert(node& head, const value_type& el) {
        if (head == NULL) {
            node n = _alloc.allocate(1);
            _alloc.construct(n, el);
            head = n;
            _size += 1;
            return ft::make_pair(head, true);
        }

        ft::pair<node, bool> ret;
        if (_comp(el, head->data))
            ret = insert(head->left, el);
        else if (_comp(head->data, el))
            ret = insert(head->right, el);
        else
            return ft::make_pair(head, false);

        if (head->right) {
            head->right->isLeft = false;
            head->right->parent = head;
        }
        if (head->left) {
            head->left->isLeft = true;
            head->left->parent = head;
        }
        head = balance(head);
        return ret;
    }

   public:
    size_type getMaxLen() const { return getMaxLen(_root); }

    size_t size() const { return _size; }

    ft::pair<node, bool> insert(const T data) {
        if (_root == NULL) {
            node n = _alloc.allocate(1);
            _alloc.construct(n, data);
            _root = n;
            _size += 1;
            return ft::make_pair(n, true);
        }
        return insert(_root, data);
    }

    node find(node head, T elem) const {
        if (head == NULL)
            return NULL;
        if (head->data == elem)
            return head;
        if (_comp(elem, head->data))
            return find(head->left, elem);
        return find(head->right, elem);
    }

    node remove(node head, T el) {
        if (head == NULL) {
            return NULL;
        }
        if (_comp(head->data, el)) {
            head->left = remove(head->left, el);
        } else if (_comp(el, head->data)) {
            head->right = remove(head->right, el);
        } else {
            if (!head->left && !head->right) {
                --_size;
                return NULL;
            } else if (head->left == NULL) {
                return head->right;
            } else if (head->right == NULL) {
                return head->left;
            }
            node tmp = inOrderPredecessor(head);
            // std::cerr << "in order " << tmp->data << '\n';
            head->data = tmp->data;
            head->right = remove(head->right, tmp->data);
        }
        return balance(head);
    }

    void remove(T el) { _root = remove(_root, el); }

    node find(T elem) const { return find(_root, elem); }

    void print() { print(_root); }

    node theLeftest() { return theLeftest(_root); }

    node theRightest() { return theRightest(_root); }

    AVL() : _root(NULL), _size(0), _comp(Cmp()), _alloc(Alloc()) {}

    explicit AVL(const Cmp& comp, const Alloc& alloc = Alloc())
        : _alloc(alloc), _comp(comp), _root(NULL), _size(0){};

    // travel ::

   public:
    Alloc _alloc;
    Cmp _comp;
    node _root;
    size_type _size;
};

// TODO
// insert should take a value instead of a node
// use comp && allocator
