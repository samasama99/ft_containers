#pragma once
#include <ft_pair.hpp>
#include <includes.hpp>

// #include <cstddef>
// #include <iostream>
// #include <map>
// #include <queue>
// #include <vector>

typedef enum { RED, BLACK } Color;
typedef enum { LEFT, RIGHT, END } Position;

template <class T>
struct tree_node {
    typedef T value_type;

    T data;
    tree_node* left;
    tree_node* right;
    tree_node* parent;
    Color col;
    Position pos;
    tree_node* _end;

    tree_node(tree_node* p) : left(NULL), right(p), parent(NULL), pos(END) {}

    tree_node(T data)
        : data(data),
          left(NULL),
          right(NULL),
          parent(NULL),
          col(RED),
          pos(RIGHT) {}

    static tree_node* Leftest(tree_node* current) {
        if (current->left == NULL)
            return current;
        return Leftest(current->left);
    }

    static tree_node* Rightest(tree_node* current) {
        if (current->right == NULL)
            return current;
        return Rightest(current->right);
    }

    static tree_node* TopRight(tree_node* current, tree_node* prev) {
        if (current == NULL)
            return prev->_end;
        if (prev == current->right)
            return TopRight(current->parent, current);
        return current;
    }

    static tree_node* TopLeft(tree_node* current, tree_node* prev) {
        if (prev != current->left)
            return current;
        return TopLeft(current->parent, current);
    }

    static tree_node* Next(tree_node* current) {
        if (current->right) {
            return Leftest(current->right);
        }
        return TopRight(current->parent, current);
    }

    static tree_node* Previous(tree_node* current) {
        if (current->left)
            return Rightest(current->left);
        return TopLeft(current->parent, current);
    };
};

template <class T, class Comp = std::less<T>, class Alloc = std::allocator<T> >
class red_black_tree {
   public:
    typedef tree_node<T>* node;
    typedef tree_node<T>* ROOT;
    typedef T value_type;
    typedef typename Alloc::template rebind<tree_node<value_type> >::other
        allocator_type;

   private:
    // checker { made by : jalalium }
    // bool check(node n, std::map<node, std::vector<int> >& mp) {
    //     bool ok = true;
    //     if (n->left != NULL) {
    //         if (n->data <= n->left->data) {
    //             std::cout << "LEFT CHILD LARGER OR EQUAL TO PARENT " <<
    //             n->data
    //                       << " " << n->left->data << std::endl;
    //             return false;
    //         }
    //         if (n->col == RED && n->left->col == RED) {
    //             std::cout << "RED PARENT WITH RED CHILD: " << n->data << " "
    //                       << n->left->data << std::endl;
    //             return false;
    //         }
    //         ok &= check(n->left, mp);
    //     }
    //     if (n->right != NULL) {
    //         if (n->data >= n->right->data) {
    //             std::cout << "RIGHT CHILD SMALLER OR EQUAL TO PARENT "
    //                       << n->data << " " << n->left->data << std::endl;
    //             return false;
    //         }
    //         if (n->col == RED && n->right->col == RED) {
    //             std::cout << "RED PARENT WITH RED CHILD: " << n->data << " "
    //                       << n->right->data << std::endl;
    //             return false;
    //         }
    //         ok &= check(n->right, mp);
    //     }
    //     std::vector<int> tmp;
    //     if (n->left != NULL) {
    //         for (int z : mp[n->left])
    //             tmp.push_back(z);
    //     } else
    //         tmp.push_back(0);
    //     if (n->right != NULL) {
    //         for (int z : mp[n->right])
    //             tmp.push_back(z);
    //     } else
    //         tmp.push_back(0);
    //     std::sort(tmp.begin(), tmp.end());
    //     for (int& z : tmp)
    //         z += (n->col == BLACK);
    //     mp[n] = tmp;
    //     if (tmp[0] != tmp.back()) {
    //         std::cout << "NODE " << n->data << std::endl;
    //         for (int z : tmp)
    //             std::cout << z << " ";
    //         std::cout << std::endl;
    //     }
    //     return (ok & (tmp[0] == tmp.back()));
    // }
    // end of checker !

    // size_t height() {
    //     if (_root == NULL)
    //         return 0;
    //     return height(_root) - 1;
    // }

    // size_t height(node& current) {
    //     if (current == NULL)
    //         return 0;
    //     size_t l = height(current->left) + 1;
    //     size_t r = height(current->right) + 1;
    //     return std::max(l, r);
    // }

    // size_t black_nodes(node& current) {
    //     if (current == NULL)
    //         return 1;
    //     size_t l = black_nodes(current->left);
    //     size_t r = black_nodes(current->right);
    //     if (l != r) {
    //         // throw error
    //         // or fix the tree
    //     }
    //     if (current->col == BLACK) {
    //         l = l + 1;
    //     }
    //     return l;
    // }

    void left_rotate(node current) {
        node tmp = current->right;
        current->right = tmp->left;
        if (current->right) {
            current->right->parent = current;
            current->right->pos = RIGHT;
        }
        if (current->parent == NULL) {
            _root = tmp;
            _root->col = BLACK;
            tmp->parent = NULL;
        } else {
            tmp->parent = current->parent;
            if (current->pos == LEFT) {
                tmp->pos = LEFT;
                tmp->parent->left = tmp;
            } else {
                tmp->pos = RIGHT;
                tmp->parent->right = tmp;
            }
        }
        tmp->left = current;
        current->pos = LEFT;
        current->parent = tmp;
    }

    void right_rotate(node current) {
        node tmp = current->left;
        current->left = tmp->right;
        if (current->left) {
            current->left->parent = current;
            current->left->pos = LEFT;
        }
        if (current->parent == NULL) {
            _root = tmp;
            _root->col = BLACK;
            tmp->parent = NULL;
        } else {
            tmp->parent = current->parent;
            if (current->pos == RIGHT) {
                tmp->pos = RIGHT;
                tmp->parent->right = tmp;
            } else {
                tmp->pos = LEFT;
                tmp->parent->left = tmp;
            }
        }
        tmp->right = current;
        current->pos = RIGHT;
        current->parent = tmp;
    }

    void left_right_rotate(node current) {
        left_rotate(current->left);
        right_rotate(current);
    }

    void right_left_rotate(node current) {
        right_rotate(current->right);
        left_rotate(current);
    }

    void rotate(node current) {
        if (current->pos == LEFT) {
            if (current->parent->pos == LEFT) {
                right_rotate(current->parent->parent);
                current->col = RED;
                current->parent->col = BLACK;
                if (current->parent->right)
                    current->parent->right->col = RED;
                return;
            }
            right_left_rotate(current->parent->parent);
            current->col = BLACK;
            current->right->col = RED;
            current->left->col = RED;
            return;
        }

        if (current->parent->pos == RIGHT) {
            left_rotate(current->parent->parent);
            current->col = RED;
            current->parent->col = BLACK;
            if (current->parent->left)
                current->parent->left->col = RED;
            return;
        }
        left_right_rotate(current->parent->parent);
        current->col = BLACK;
        current->right->col = RED;
        current->left->col = RED;
        return;
    }

    void correct_tree(node& current) {
        if (current->parent->pos == LEFT) {
            if (current->parent->parent->right == NULL ||
                current->parent->parent->right->col == BLACK) {
                return rotate(current);
            }
            if (current->parent->parent->right)
                current->parent->parent->right->col = BLACK;
            current->parent->parent->col = RED;
            current->parent->col = BLACK;
            return;
        }
        if (current->parent->parent->left == NULL ||
            current->parent->parent->left->col == BLACK) {
            return rotate(current);
        }
        if (current->parent->parent->left)
            current->parent->parent->left->col = BLACK;
        current->parent->parent->col = RED;
        current->parent->col = BLACK;
    }

    void check_color(node current) {
        if (current == NULL)
            return;
        if (current == _root)
            return;
        if (current->col == RED && current->parent->col == RED)
            correct_tree(current);
        check_color(current->parent);
    }

    ft::pair<node, bool> add(node head, const value_type& t) {
        if (_comp(head->data, t)) {
            if (head->right == NULL) {
                head->right = _alloc.allocate(1);
                _alloc.construct(head->right, t);
                head->right->pos = RIGHT;
                head->right->parent = head;
                head->right->_end = _end;
                return ft::make_pair(head->right, true);
            }
            return add(head->right, t);
        }
        if (_comp(t, head->data)) {
            if (head->left == NULL) {
                head->left = _alloc.allocate(1);
                _alloc.construct(head->left, t);
                head->left->pos = LEFT;
                head->left->parent = head;
                head->left->_end = _end;
                return ft::make_pair(head->left, true);
            }
            return add(head->left, t);
        }
        return ft::make_pair(head, false);
    }

    void print(const node& head, size_t depth = 0) const {
        if (head == NULL) {
            return;
        }
        print(head->right, depth + 1);
        std::cout << std::string(depth, '\t') << '[' << head->data << " "
                  << ((head->pos == RIGHT) ? "right" : "left")
                  << ((head->col == RED) ? " red" : " black")
                  // << " parent == " << head->parent
                  << ']' << " "
                  << "\n\n";
        // std::cout << std::string(depth, '\t') << '[' << head->data << ']'
        //           << "\n\n";
        print(head->left, depth + 1);
    }

    node find(node head, T elem) const {
        if (head == NULL)
            return NULL;
        if (head == NULL)
            return NULL;
        if (!_comp(head->data, elem) && !_comp(elem, head->data))
            return head;
        if (_comp(elem, head->data))
            return find(head->left, elem);
        return find(head->right, elem);
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

   public:
    void print() { print(_root); }

    const node& getEnd() { return _end; }
    node& getRoot() { return _root; }

    ft::pair<node, bool> add(const value_type& t) {
        if (_root == NULL) {
            _root = _alloc.allocate(1);
            _alloc.construct(_root, t);
            _root->col = BLACK;
            _root->_end = _end;
            _end->left = theRightest(_root);
            _size += 1;
            // // checking time !
            // std::map<node, std::vector<int> > mp;
            // assert(check(_root, mp));
            // std::cout << "INSERTED " << t << " SUCCESSFULLY" << std::endl;
            return ft::make_pair(_root, true);
        }

        ft::pair<node, bool> ret = add(_root, t);
        if (ret.second) {
            check_color(ret.first);
            _size += 1;
        }
        _root->col = BLACK;
        _end->left = theRightest(_root);
        // checking time !
        // std::map<node, std::vector<int> > mp;
        // assert(check(_root, mp));
        // std::cout << "INSERTED " << t << " SUCCESSFULLY" << std::endl;
        return ret;
    };

    node find(T elem) const { return find(_root, elem); }

    size_t size() const { return _size; }

    node theLeftest() { return theLeftest(_root); }

    const node theLeftest() const { return theLeftest(_root); }

    node theRightest() { return theRightest(_root); }

    const node theRightest() const { return theRightest(_root); }

    // void clear() {
    //     while (_root && _root != _end && _size != 0) {
    //         remove(_root, _root->data);
    //     }
    //     _root = _end;
    //     _size = 0;
    // }

    red_black_tree(Comp comp, Alloc alloc)
        : _root(NULL),
          _end(_alloc.allocate(1)),
          _size(0),
          _alloc(alloc),
          _comp(comp) {}

    red_black_tree(Comp comp)
        : _root(NULL),
          _end(_alloc.allocate(1)),
          _size(0),
          _alloc(Alloc()),
          _comp(comp) {}

    red_black_tree()
        : _root(NULL),
          _end(_alloc.allocate(1)),
          _size(0),
          _alloc(allocator_type()),
          _comp(Comp()) {
        _alloc.construct(_end, _root);
    }

   private:
    Comp _comp;
    allocator_type _alloc;
    node _root;
    node const _end;
    size_t _size;
};
