/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <orahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:10:09 by orahmoun          #+#    #+#             */
/*   Updated: 2022/10/04 11:10:10 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ft_pair.hpp>
#include <iostream>

enum { RIGHT, LEFT, ROOT };

template <typename T>
struct avlNode {
    typedef T value_type;
    T data;
    size_t height;
    avlNode* left;
    avlNode* right;
    avlNode* parent;

    static avlNode* Leftest(avlNode* current) {
        if (current->left == NULL)
            return current;
        return Leftest(current->left);
    }

    static avlNode* Rightest(avlNode* current) {
        if (current->right == NULL)
            return current;
        return Rightest(current->right);
    }

    static avlNode* TopRight(avlNode* current, avlNode* prev) {
        if (prev == current->right)
            return TopRight(current->parent, current);
        return current;
    }

    static avlNode* TopLeft(avlNode* current, avlNode* prev) {
        if (prev != current->left)
            return current;
        return TopLeft(current->parent, current);
    }

   public:
    avlNode() : height(0), left(NULL), right(NULL), parent(NULL) {}
    avlNode(const T& data)
        : data(data), height(1), left(NULL), right(NULL), parent(NULL) {}

    static avlNode* Next(avlNode* current) {
        if (current->right) {
            return Leftest(current->right);
        }
        return TopRight(current->parent, current);
    }

    static avlNode* Previous(avlNode* current) {
        if (current->left)
            return Rightest(current->left);
        return TopLeft(current->parent, current);
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

    void print(node head, size_t depth = 0) const {
        if (head == NULL) {
            return;
        }
        print(head->right, depth + 1);
        std::cout << std::string(depth, '\t') << '[' << head->data << ']' << " "
                  << "\n\n";
        print(head->left, depth + 1);
    }

    node left_rotate(node head) {
        node tmp = head->parent;
        head->parent = head->right;
        head->right->parent = tmp;
        if (head->right->left)
            head->right->left->parent = head;
        node temp = head->right;
        head->right = temp->left;
        temp->left = head;

        return temp;
    }

    node right_rotate(node head) {
        node tmp = head->parent;
        head->parent = head->left;
        head->left->parent = tmp;
        if (head->left->right)
            head->left->right->parent = head;
        node temp = head->left;
        head->left = temp->right;
        temp->right = head;

        return temp;
    }

    node right_left_rotate(node head) {
        head->right = right_rotate(head->right);  // parent
        return left_rotate(head);                 // grandparent
    }

    node left_right_rotate(node head) {
        head->left = left_rotate(head->left);  // parent
        return right_rotate(head);             // grandparent
    }

    size_type getMaxLen(const node head) const {
        if (head == NULL || head == _end)
            return 0;
        return 1 + std::max(getMaxLen(head->left), getMaxLen(head->right));
    }

    node theLeftest(node head) {
        if (head == NULL)
            return NULL;
        if (head == _end)
            return head;
        if (head->left == NULL)
            return head;
        return theLeftest(head->left);
    }

    const node theLeftest(node head) const {
        if (head == NULL)
            return NULL;
        if (head == _end)
            return head;
        if (head->left == NULL)
            return head;
        return theLeftest(head->left);
    }

    node theRightest(node head) {
        if (head == NULL)
            return NULL;
        if (head == _end)
            return head;
        if (head->right == NULL)
            return head;
        return theRightest(head->right);
    }

    const node theRightest(node head) const {
        if (head == NULL)
            return NULL;
        if (head == _end)
            return head;
        if (head->right == NULL)
            return head;
        return theRightest(head->right);
    }

    size_t get_size(node n) {
        if (n == NULL)
            return 0;
        return n->height;
    }

    size_t get_max_size(node n) {
        return std::max(get_size(n->left), get_size(n->right)) + 1;
    }

    node balance(node& head) {
        int left = get_size(head->left), right = get_size(head->right);
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
            head = _alloc.allocate(1);
            _alloc.construct(head, el);
            ++_size;
            return ft::make_pair(head, true);
        }

        ft::pair<node, bool> ret;
        if (_comp(el, head->data))
            ret = insert(head->left, el);
        else if (_comp(head->data, el))
            ret = insert(head->right, el);
        else
            return ft::make_pair(head, false);

        if (head->right)
            head->right->parent = head;

        if (head->left)
            head->left->parent = head;

        head->height = get_max_size(head);
        head = balance(head);
        if (head->left)
            head->left->height = get_max_size(head->left);
        if (head->right)
            head->right->height = get_max_size(head->right);
        head->height = get_max_size(head);
        return ret;
    }

   public:
    node inOrderSuccessor(node head) {
        if (head == _end)
            return _end;
        return theRightest(head->left);
    }

    node inOrderPredecessor(node head) {
        if (head == _end)
            return _end;
        return theLeftest(head->right);
    }

    size_type getMaxLen() const { return getMaxLen(_root); }

    size_t size() const { return _size; }

    ft::pair<node, bool> insert(const T& data) {
        if (_root == _end) {
            _root = _alloc.allocate(1);
            _alloc.construct(_root, data);
            _root->parent = _end;
            ++_size;
            _end->left = _root;
            return ft::make_pair(_root, true);
        }
        ft::pair<node, bool> t = insert(_root, data);
        _root->parent = _end;
        _end->left = _root;
        return t;
    }

    node find(node head, T elem) const {
        if (head == NULL)
            return NULL;
        if (head == _end)
            return _end;
        if (!_comp(head->data, elem) && !_comp(elem, head->data))
            return head;
        if (_comp(elem, head->data))
            return find(head->left, elem);
        return find(head->right, elem);
    }

    void remove(node& head, const T& el) {
        if (head == NULL || head == _end)
            return;

        if (_comp(head->data, el)) {
            remove(head->right, el);
        } else if (_comp(el, head->data)) {
            remove(head->left, el);
        } else {
            if (!head->left && !head->right) {
                --_size;
                _alloc.destroy(head);
                _alloc.deallocate(head, 1);
                head = NULL;
                return;
            } else if (head->left == NULL) {
                node tmp = head->right;
                node tmp2 = head->parent;
                --_size;
                _alloc.destroy(head);
                _alloc.deallocate(head, 1);
                head = tmp;
                head->parent = tmp2;
                return;
            } else if (head->right == NULL) {
                node tmp = head->left;
                node tmp2 = head->parent;
                _alloc.destroy(head);
                _alloc.deallocate(head, 1);
                --_size;
                head = tmp;
                head->parent = tmp2;
                return;
            }
            node tmp = inOrderPredecessor(head);
            node r = head->right;
            node l = head->left;
            node p = head->parent;
            _alloc.construct(head, tmp->data);
            head->right = r;
            head->left = l;
            head->parent = p;
            remove(head->right, tmp->data);
        }
        head->height = get_max_size(head);
        head = balance(head);
        if (head->left)
            head->left->height = get_max_size(head->left);
        if (head->right)
            head->right->height = get_max_size(head->right);
        head->height = get_max_size(head);
    }

    void remove(const T& el) {
        remove(_root, el);
        if (_size == 0)
            _root = _end;
        else
            _root->parent = _end;
    }

    node find(T elem) const { return find(_root, elem); }

    void print() { print(_root); }

    node theLeftest() { return theLeftest(_root); }

    const node theLeftest() const { return theLeftest(_root); }

    node theRightest() { return theRightest(_root); }

    const node theRightest() const { return theRightest(_root); }

    void clear() {
        while (_root && _root != _end && _size != 0) {
            remove(_root, _root->data);
        }
        _root = _end;
        _size = 0;
    }

    AVL() : _root(NULL), _end(NULL), _size(0), _comp(Cmp()), _alloc(Alloc()) {
        _end = _alloc.allocate(1);
        _alloc.construct(_end);
        _root = _end;
    }

    explicit AVL(const Cmp& comp, const Alloc& alloc = Alloc())
        : _alloc(alloc), _comp(comp), _root(NULL), _end(NULL), _size(0) {
        _end = _alloc.allocate(1);
        _alloc.construct(_end);
        _root = _end;
    };

    ~AVL() {
        clear();
        _alloc.deallocate(_end, 1);
    }
    // travel ::

   public:
    Alloc _alloc;
    Cmp _comp;
    node _root;
    node _end;
    size_type _size;
};
