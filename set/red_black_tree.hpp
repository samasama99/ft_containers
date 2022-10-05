#pragma once
#include <ft_pair.hpp>
#include <includes.hpp>

typedef enum { RED, BLACK } Color;
typedef enum { LEFT, RIGHT } Position;

template <class T>
struct tree_node {
    T data;
    tree_node* left;
    tree_node* right;
    tree_node* parent;
    Color col;
    Position pos;

    tree_node(T data)
        : data(data),
          left(NULL),
          right(NULL),
          parent(NULL),
          col(RED),
          pos(RIGHT) {}
};

template <class T,
          class Comp = std::less<T>,
          class Alloc = std::allocator<tree_node<T> > >
class red_black_tree {
   public:
    typedef tree_node<T>* node;
    typedef T value_type;

   private:
    size_t height() {
        if (_root == NULL)
            return 0;
        return height(_root) - 1;
    }

    size_t height(node& current) {
        if (current == NULL)
            return 0;
        size_t l = height(current->left) + 1;
        size_t r = height(current->right) + 1;
        return std::max(l, r);
    }

    size_t black_nodes(node& current) {
        if (current == NULL)
            return 1;
        size_t l = black_nodes(current->left);
        size_t r = black_nodes(current->right);
        if (l != r) {
            // throw error
            // or fix the tree
        }
        if (current->col == BLACK) {
            l = l + 1;
        }
        return l;
    }

    void left_rotate(node current) {
        node tmp = current->right;
        current->right = tmp->left;
        if (current->right) {
            current->right->parent = current;
            current->right->pos = RIGHT;
        }
        if (current->parent == NULL) {
            _root = tmp;
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
        assert(current != NULL);
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
            tmp->parent = NULL;
        } else {
            tmp->parent = current->parent;
            if (current->pos == LEFT) {
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

    void rotate(node& current) {
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
            // uncle is current.parent.parent.right
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
        // uncle is in the left of the parent->parent
        // uncle is current.parent.parent.right
        if (current->parent->parent->left == NULL ||
            current->parent->parent->left->col == BLACK) {
            return rotate(current);
        }
        if (current->parent->parent->left)
            current->parent->parent->left->col = BLACK;
        current->parent->parent->col = RED;
        current->parent->col = BLACK;
    }

    void check_color(node& current) {
        if (current == _root)
            return;
        if (current->col == RED && current->parent->col == RED)
            correct_tree(current);
        check_color(current->parent);
    }

    ft::pair<node, bool> add(node& head, const value_type& t) {
        if (_comp(head->data, t)) {
            if (head->right == NULL) {
                head->right = _alloc.allocate(1);
                _alloc.construct(head->right, t);
                head->right->pos = RIGHT;
                head->right->parent = head;
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
                return ft::make_pair(head->left, true);
            }
            return add(head->left, t);
        }
        assert(true);
        return ft::make_pair(head, false);
    }

    void print(const node& head, size_t depth = 0) const {
        if (head == NULL) {
            return;
        }
        print(head->right, depth + 1);
        // std::cout << std::string(depth, '\t') << '[' << head->data << " "
        //           << ((head->pos == RIGHT) ? "right" : "left")
        //           << ((head->col == RED) ? " red" : " black")
        //           << " parent == " << head->parent << ']' << " "
        //           << "\n\n";
        std::cout << std::string(depth, '\t') << '[' << head->data << ']'
                  << "\n\n";
        print(head->left, depth + 1);
    }

   public:
    void print() { print(_root); }

    ft::pair<node, bool> add(const value_type& t) {
        if (_root == NULL) {
            _root = _alloc.allocate(1);
            _alloc.construct(_root, t);
            _root->col = BLACK;
            _size += 1;
            return ft::make_pair(_root, true);
        }
        ft::pair<node, bool> ret = add(_root, t);
        if (ret.second)
            check_color(ret.first);
        return ret;
    };

    red_black_tree() : _root(NULL), _size(0), _alloc(Alloc()), _comp(Comp()) {}

   private:
    Comp _comp;
    Alloc _alloc;
    node _root;
    size_t _size;
};
