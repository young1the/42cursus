#ifndef TREE_HPP
#define TREE_HPP

#define BLACK 0
#define RED 1

namespace ft {

/* #tree_node */
template <typename T, typename Alloc = std::allocator<T> >
struct tree_node
{
	public:
	bool				_color;
	struct tree_node*	_begin;
	struct tree_node*	_left;
	struct tree_node*	_right;
	struct tree_node*	_parent;
	bool				_nil;
	T*					_data;
	tree_node()
	: _color(BLACK), _begin(this), _left(this), _right(this), _parent(0), _nil(1)
	{
		newNode();
	}
	tree_node(const T& x)
	: _color(BLACK), _begin(this), _left(this), _right(this), _parent(0), _nil(0)
	{
		newNode(x);
	}
	~tree_node() { delNode(); }
	void newNode(T x = T())
	{
		Alloc allocator = Alloc();
		_data = allocator.allocate(1);
		allocator.construct(_data, x);
	}
	void delNode()
	{
		Alloc allocator = Alloc();
		allocator.destroy(_data);
		allocator.deallocate(_data, 1);
	}
};
/* tree_node */

/* #tree */
template <typename T>
class tree
{
	public:
	tree_node<T> _node;
	tree_node<T> *_root;
	size_t _size;
	tree() : _node(), _root(&_node), _size(0) { }
	tree(tree<T> &other) : _node() , _root(&_node), _size(&other != &other) { }
	tree& operator=(const tree& other)
	{
		if (this == &other)
			return *this;
		_root = other._root;
		_node = other._node;
		_size = other._size;
		return *this;
	};

	tree_node<T>* getBegin()
	{
		tree_node<T>* tmp = _root;
		while (!tmp->_left->_nil)
		{
			tmp = tmp->_left;
		}
		return tmp;
	}

	tree_node<T>* getLast()
	{
		tree_node<T>* tmp = _root;
		while (!tmp->_right->_nil)
		{
			tmp = tmp->_right;
		}
		return tmp;
	}

	tree_node<T>* getEnd()
	{
		tree_node<T>* tmp = _root;
		while (!tmp->_right->_nil)
		{
			tmp = tmp->_right;
		}
		return tmp->_right;
	}

	tree_node<T> *grandparent(tree_node<T> *n)
	{
		if ((!n->_nil) && (n->_parent != _nullptr))
		{
			return n->_parent->_parent;
		}
		else
		{
			return _nullptr;
		}
	}

	tree_node<T> *uncle(tree_node<T> *n)
	{
		tree_node<T> *g = grandparent(n);
		if (g == _nullptr)
			return _nullptr;
		if (n->_parent == g->_left)
			return g->_right;
		else
			return g->_left;
	}
	

	void rotateLeft(tree_node<T> *n)
	{
		if (n->_nil)
			return ; // can remove
		tree_node<T>* c = n->_right;
		tree_node<T>* p = n->_parent;
		if (!c->_left->_nil)
			c->_left->_parent = n;
		n->_right = c->_left;
		n->_parent = c;
		c->_left = n;
		c->_parent = p;
		if (p != _nullptr)
		{
			if (p->_left == n)
				p->_left = c;
			else
				p->_right = c;
		}
		else
		{
			_root = c;
		}
	}

	void rotateRight(tree_node<T>* n)
	{
		if (n->_nil)
			return ;
		tree_node<T>* c = n->_left;
		tree_node<T>* p = n->_parent;
		if (!c->_right->_nil)
			c->_right->_parent = n;
		n->_left = c->_right;
		n->_parent = c;
		c->_right = n;
		c->_parent = p;
		if (p != _nullptr)
		{
			if (p->_right == n)
			{
				p->_right = c;
			}
			else
			{
				p->_left = c;
			}
		}
		else
		{
			_root = c;
		}
	}

	void insertCase1(tree_node<T>*n)
	{
		if (n->_parent == _nullptr)
			n->_color = BLACK;
		else
			insertCase2(n);
	}

	void insertCase2(tree_node<T>*n)
	{
		if (n->_parent->_color == BLACK)
			return; /* Tree is still valid */
		else
			insertCase3(n);
	}

	void insertCase3(tree_node<T>*n)
	{
		tree_node<T>*u = uncle(n), *g;

		if ((u != _nullptr) && (u->_color == RED)) {
			n->_parent->_color = BLACK;
			u->_color = BLACK;
			g = grandparent(n);
			g->_color = RED;
			insertCase1(g);
		} else {
			insertCase4(n);
		}
	}

	void insertCase4(tree_node<T>*n)
	{
		tree_node<T>*g = grandparent(n);

		if ((n == n->_parent->_right) && (n->_parent == g->_left)) {
			rotateLeft(n->_parent);
			n = n->_left;
		} else if ((n == n->_parent->_left) && (n->_parent == g->_right)) {
			rotateRight(n->_parent);
			n = n->_right;
		}
		insertCase5(n);
	}

	void insertCase5(tree_node<T>*n)
	{
		tree_node<T>*g = grandparent(n);

		n->_parent->_color = BLACK;
		g->_color = RED;
		if (n == n->_parent->_left)
			rotateRight(g);
		else
			rotateLeft(g);
	}

	int deleteNode(tree_node<T> *z)
	{
		tree_node<T> *x, *y;
		if (!z || z->_nil)
		{
			return 0;
		}
		if (z->_left->_nil || z->_right->_nil)
		{
			y = z;
		}
		else
		{
			y = z->_right;
			while (!y->_left->_nil)
			{
				y = y->_left;
			} // successor
		}
		if (!y->_left->_nil)
		{
			x = y->_left;
		}
		else
		{
			x = y->_right; // replace
		}
		x->_parent = y->_parent;
		if (y->_parent)
		{
			if (y == y->_parent->_left)
			{
				y->_parent->_left = x;
			}
			else
			{
				y->_parent->_right = x;
			}
		}
		else
		{
			_root = x;
		}
		if (y != z)
		{
			z->delNode();
			z->newNode(*(y->_data));
		}
		if (y->_color == BLACK)
		{
			deleteFixup (x);
		}
		_node._parent = getLast();
		_node._begin = getBegin();
		_size--;
		delete y;
		return 1;
	}

	void deleteFixup(tree_node<T> *x)
	{
		while (x != _root && x->_color == BLACK)
		{
			if (x == x->_parent->_left)
			{
				tree_node<T> *w = x->_parent->_right;
				if (w->_color == RED)
				{
					w->_color = BLACK;
					x->_parent->_color = RED;
					rotateLeft(x->_parent);
					w = x->_parent->_right;
				}
				if (w->_left->_color == BLACK && w->_right->_color == BLACK)
				{
					w->_color = RED;
					x = x->_parent;
				}
				else
				{
					if (w->_right->_color == BLACK)
					{
						w->_left->_color = BLACK;
						w->_color = RED;
						rotateRight(w);
						w = x->_parent->_right;
					}
					w->_color = x->_parent->_color;
					x->_parent->_color = BLACK;
					w->_right->_color = BLACK;
					rotateLeft(x->_parent);
					x = _root;
				}
			}
			else
			{
				tree_node<T> *w = x->_parent->_left;
				if (w->_color == RED)
				{
					w->_color = BLACK;
					x->_parent->_color = RED;
					rotateRight (x->_parent);
					w = x->_parent->_left;
				}
				if (w->_right->_color == BLACK && w->_left->_color == BLACK)
				{
					w->_color = RED;
					x = x->_parent;
				}
				else
				{
					if (w->_left->_color == BLACK)
					{
						w->_right->_color = BLACK;
						w->_color = RED;
						rotateLeft(w);
						w = x->_parent->_left;
					}
					w->_color = x->_parent->_color;
					x->_parent->_color = BLACK;
					w->_left->_color = BLACK;
					rotateRight(x->_parent);
					x = _root;
				}
			}
		}
		x->_color = BLACK;
	}

};
/* tree */

} /* namespace ft end */

#endif
