#ifndef SET_HPP
#define SET_HPP

#include "iterator.hpp"
#include "tree.hpp"
#include "utility.hpp"
#include <functional>
#include <iostream>

namespace ft {

template <class Key, class Compare = std::less<Key>, class Alloc = std::allocator<Key > >
class set {
public:
	typedef Key					key_type;
	typedef Key					value_type;
	typedef std::size_t			size_type;
	typedef std::ptrdiff_t		difference_type;
	typedef Compare				key_compare;
	typedef Compare				value_compare;
	typedef Alloc				allocator_type;
	typedef value_type&			reference;
	typedef const value_type&	const_reference;
	typedef typename allocator_type::pointer										pointer;
	typedef typename allocator_type::const_pointer									const_pointer;
	typedef ft::node_iterator<tree_node<value_type>*, value_type>					iterator;
	typedef ft::node_iterator<const tree_node<value_type>*, value_type>				const_iterator;
	typedef ft::reverse_iterator<iterator>											reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>									const_reverse_iterator;
	typedef typename allocator_type::template rebind<tree_node<value_type> >::other	allocator_rebind_node;
	typedef typename allocator_type::template rebind<tree<value_type> >::other		allocator_rebind_tree;

private:
	Alloc			 		_allocator;
	allocator_rebind_tree	_allocator_rebind_tree;
	allocator_rebind_node	_allocator_rebind_node;
	Compare		 			_comp;
	tree<value_type>*		_tree;

	void _fillTree(tree_node<value_type> *t)
	{
		if (!t->_left->_nil)
		{
			_fillTree(t->_left);
		}
		if (!t->_nil)
		{
			insert(*t->_data);
		}
		if (!t->_right->_nil)
			_fillTree(t->_right);
	}

	void _clearTree(tree_node<value_type> *tmp)
	{
		if (tmp->_nil)
		{
			return;
		}
		if (!tmp->_left->_nil)
		{
			_clearTree(tmp->_left);
		}
		if (!tmp->_right->_nil)
		{
			_clearTree(tmp->_right);
		}
		_allocator_rebind_node.destroy(tmp);
		_allocator_rebind_node.deallocate(tmp, sizeof(tree_node<value_type>));
	}

	void _clearSet()
	{
		_clearTree(_tree->_root);
		_allocator_rebind_tree.destroy(_tree);
		_allocator_rebind_tree.deallocate(_tree, sizeof(tree<value_type>));
	}

public:

	set()
	{
		_tree = _allocator_rebind_tree.allocate(sizeof(tree<value_type>));
		_allocator_rebind_tree.construct(_tree);
	}

	set(const Compare& comp, const Alloc& alloc = Alloc()) : _allocator(alloc), _comp(comp)
	{
		_tree = _allocator_rebind_tree.allocate(sizeof(tree<value_type>));
		_allocator_rebind_tree.construct(_tree);
	}

	template< class InputIt >
	set(InputIt first, InputIt last, const Compare& comp = Compare(), const Alloc& alloc = Alloc())
	: _allocator(alloc), _comp(comp)
	{
		_tree = _allocator_rebind_tree.allocate(sizeof(tree<value_type>));
		_allocator_rebind_tree.construct(_tree);
		for (; first != last; first++)
		{
			insert(*first);
		}
	}

	set(const set& other)
	{
		_tree = _allocator_rebind_tree.allocate(sizeof(tree<value_type>));
		_allocator_rebind_tree.construct(_tree, *(other._tree));
		_fillTree(other._tree->_root);
	}


	set& operator=( const set& other )
	{
		if (this == &other)
			return *this;
		_comp = other._comp;
		_allocator = other._allocator;
		_clearSet();
		_tree = _allocator_rebind_tree.allocate(sizeof(tree<value_type>));
		_allocator_rebind_tree.construct(_tree, *other._tree);
		_fillTree(other._tree->_root);
		return *this;
	}

	~set()
	{
		_clearSet();
	}

	allocator_type get_allocator() const { return _allocator; }
	iterator begin() { return _tree->getBegin(); }
	const_iterator begin() const { return _tree->getBegin(); }
	iterator end() { return _tree->getEnd(); }
	const_iterator end() const { return _tree->getEnd(); }
	reverse_iterator rbegin() { return iterator(_tree->getLast()); }
	const_reverse_iterator rbegin() const { return const_iterator(_tree->getLast()); }
	reverse_iterator rend() { return iterator(_tree->getEnd()); }
	const_reverse_iterator rend() const { return const_iterator(_tree->getEnd()); }
	bool empty() const { return size() == 0; }
	size_type size() const { return _tree->_size; }
	size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(tree_node<value_type>);}

	void clear()
	{
		_clearSet();
		_tree = _allocator_rebind_tree.allocate(sizeof(tree<value_type>));
		_allocator_rebind_tree.construct(_tree);
	}

	ft::pair<iterator, bool> insert(const value_type& value)
	{
		return insertNode(_tree->_root, value);
	}

	iterator insert(iterator hint, const value_type& value)
	{
		if (hint == end())
		{
			return insertNode(_tree->_root, value).first;
		}
		else
		{
			if (*hint > value)
			{
				iterator prev = hint;
				--prev;
				while (prev != end() && *prev >= value)
				{
					--hint;
					--prev;
				}
			}
			else if (*hint < value)
			{
				iterator next = hint;
				++next;
				while (next != end() && *next <= value)
				{
					++hint;
					++next;
				}
			}
		}
		return insertNode(hint.base(), value).first;
	}

	template< class InputIt >
	void insert(InputIt first, InputIt last)
	{
		for (; first != last; first++)
		{
			insert(*first);
		}
	}

	void erase(iterator pos)
	{
		iterator tmp = pos;
		_tree->deleteNode(tmp.base());
	}

	void erase(iterator first, iterator last)
	{
		iterator tmp;
		for (; first != last ;)
		{
			tmp = first++;
			_tree->deleteNode(tmp.base());
		}
	}

	size_type erase( const key_type& key )
	{
		return _tree->deleteNode(find(key).base());
	}

	void swap(set& other)
	{
		std::swap(_tree, other._tree);
	}

	size_type count( const Key& key ) const
	{
		return (find(key) == end()) ? 0 : 1;
	}

	iterator find( const Key& key )
	{
		tree_node<value_type> *current = _tree->_root;
		while (!current->_nil)
		{
			if (key == *current->_data)
			{
				return (current);
			}
			else
			{
				current = _comp(key, *current->_data) ? current->_left : current->_right;
			}
		}
		return end();
	}

	const_iterator find(const Key& key) const
	{
		tree_node<value_type> *current = _tree->_root;
		while (!current->_nil)
		{
			if (key == *current->_data)
			{
				return const_iterator(current);
			}
			else
			{
				current = _comp(key, *current->_data) ? current->_left : current->_right;
			}
		}
		return end();
	}

	iterator lower_bound( const Key& key )
	{
		tree_node<value_type> *current = _tree->_root;
		while (!current->_nil)
		{
			if (key == *current->_data)
			{
				return iterator(current);
			}
			else
			{
				if (_comp(key, *current->_data))
				{
					if (!current->_left->_nil)
					{
						current = current->_left;
					}
					else
					{
						return iterator(current);
					}
				}
				else
				{
					if (!current->_right->_nil)
					{
						current = current->_right;
					}
					else
					{
						return ++iterator(current);
					}
				}
			}
		}
		return end();
	}

	const_iterator lower_bound(const Key& key) const
	{
		return const_iterator(lower_bound(key));
	}

	iterator upper_bound(const Key& key)
	{
		iterator tmp = lower_bound(key);

		return (tmp == end()) ? tmp : (_comp(key, *tmp)) ? tmp : ++tmp;
	}

	const_iterator upper_bound( const Key& key ) const
	{
		return const_iterator(upper_bound(key));
	}

	ft::pair<iterator,iterator> equal_range( const Key& key )
	{
		return ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
	}

	ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
	{
		return ft::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key));
	}

	key_compare key_comp() const
	{
		return _comp;
	}

	set::value_compare value_comp() const
	{
		return _comp;
	}

	friend bool operator==(const set &lhs, const set &rhs)
	{
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	friend bool operator!=(const set &lhs, const set &rhs)
	{
		return !(lhs == rhs);
	}

	friend bool operator<(const set &lhs, const set &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	friend bool operator>(const set &lhs, const set &rhs)
	{
		return rhs < lhs;
	}

	friend bool operator>=(const set &lhs, const set &rhs)
	{
		return !(lhs < rhs);
	}

	friend bool operator<=(const set &lhs, const set &rhs)
	{
		return !(rhs < lhs);
	}

	ft::pair<iterator, bool> insertNode(tree_node<value_type> *hint, const value_type& value)
	{
		tree_node<value_type> *current = hint;
		tree_node<value_type> *new_parent = 0;
		tree_node<value_type> *x;

		while (!current->_nil)
		{
			if (value == *(current->_data))
			{
				return ft::make_pair(current, false);
			}
			new_parent = current;
			current = _comp(value, *(current->_data)) ?
					  current->_left : current->_right;
		}
		x = _allocator_rebind_node.allocate(sizeof(tree_node<value_type>));
		_allocator_rebind_node.construct(x, value);
		x->_parent = new_parent;
		x->_left = &_tree->_node;
		x->_right = &_tree->_node;
		x->_color = RED;
		if (new_parent)
		{
			if (_comp(value, *(new_parent->_data)))
			{
				new_parent->_left = x;
			}
			else
			{
				new_parent->_right = x;
			}
		}
		else
		{
			_tree->_root = x;
		}
		_tree->insertCase1(x);
		if (x == _tree->getLast())
		{
			_tree->_node._parent = x;
		}
		if (x == _tree->getBegin())
		{
			_tree->_node._begin = x;
		}
		_tree->_size++;
		return ft::make_pair(x, true);
	}

};

}

#endif
