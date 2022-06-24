#ifndef MAP_HPP
#define MAP_HPP

#include "iterator.hpp"
#include "tree.hpp"
#include "utility.hpp"

namespace ft
{

template <class Key, class T, class Compare = std::less<Key>, class A = std::allocator<ft::pair<const Key, T> > >
class map {
public:
	typedef Key										key_type;
	typedef T										mapped_type;
	typedef ft::pair<const Key, T>					value_type;
	typedef std::size_t								size_type;
	typedef std::ptrdiff_t							difference_type;
	typedef Compare									key_compare;
	typedef A										allocator_type;
	typedef value_type&								reference;
	typedef const value_type&						const_reference;
	typedef typename allocator_type::pointer		pointer;
	typedef typename allocator_type::const_pointer	const_pointer;

	typedef ft::node_iterator<tree_node<value_type>*, value_type>			iterator;
	typedef ft::node_iterator<const tree_node<value_type>*, value_type>		const_iterator;
	typedef ft::reverse_iterator<iterator>									reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;

	typedef typename allocator_type::template rebind<tree_node<value_type> >::other		allocator_rebind_node;
	typedef typename allocator_type::template rebind<tree<value_type> >::other			allocator_rebind_tree;

	class value_compare : public std::binary_function<value_type, value_type, bool>
	{
	friend class map;
	protected:
		key_compare comp;
		value_compare(key_compare c) : comp(c) {}
		public:
		bool operator()(const value_type& __x, const value_type& __y) const
		{
			return comp(__x.first, __y.first);
		}
	};

private:
	allocator_type 				_allocator;
	allocator_rebind_tree		_allocator_rebind_tree;
	allocator_rebind_node		_allocator_rebind_node;
	Compare		 				_comp;
	tree<value_type >*			_tree;

public:
	map()
	{
		_tree = _allocator_rebind_tree.allocate(1);
		_allocator_rebind_tree.construct(_tree);
	}

	explicit map(const Compare& comp, const A& alloc = A()) : _comp(comp), _allocator(alloc)
	{
		_tree = _allocator_rebind_tree.allocate(1);
		_allocator_rebind_tree.construct(_tree);
	}

	template <class InputIt>
	map(InputIt first, InputIt last, const Compare& comp = Compare(), const A& alloc = A())
	: _allocator(alloc), _comp(comp)
	{
		_tree = _allocator_rebind_tree.allocate(1);
		_allocator_rebind_tree.construct(_tree);
		for (; first != last; first++)
		{
			insert(ft::make_pair(first->first, first->second));
		}
	}

	map(const map &other) : _allocator(other._allocator), _comp(other._comp)
	{
		_tree = _allocator_rebind_tree.allocate(1);
		_allocator_rebind_tree.construct(_tree, *(other._tree));
		fillTree(other._tree->_root);
	}

	map& operator=(const map& other)
	{
		if (this == &other)
			return *this;
		_comp = other._comp;
		_allocator = other._allocator;
		clearMap();
		_tree = _allocator_rebind_tree.allocate(1);
		_allocator_rebind_tree.construct(_tree, *other._tree);
		fillTree(other._tree->_root);
		return *this;
	}

	~map()
	{
		clearMap();
	}

	allocator_type get_allocator() const { return _allocator; }
	const T& at(const Key& key) const { return static_cast<const T>(at(key)); }
	T& operator[](const Key& key) { return insert(ft::make_pair(key, T())).first->second; }
	iterator begin() { return _tree->getBegin(); }
	const_iterator begin() const { return _tree->getBegin(); }
	iterator end() { return _tree->getEnd(); }
	const_iterator end() const { return _tree->getEnd(); }
	reverse_iterator rbegin() { return reverse_iterator(iterator(_tree->getLast())); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(const_iterator(_tree->getLast())); }
	reverse_iterator rend() { return reverse_iterator(iterator(_tree->getEnd())); }
	const_reverse_iterator rend() const { return const_reverse_iterator(const_iterator(_tree->getEnd())); }
	bool empty() const { return size() == 0; }
	size_type size() const { return _tree->_size; }
	size_type max_size() const
	{
		return (std::min((size_type) std::numeric_limits<difference_type>::max(),
				std::numeric_limits<size_type>::max() / (sizeof(tree_node<value_type>) + sizeof(T*))));
	}

	void clear()
	{
		clearMap();
		_tree = _allocator_rebind_tree.allocate(1);
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
			if (hint->first > value.first)
			{
				iterator prev = hint;
				--prev;
				while (prev != end() && prev->first >= value.first)
				{
					--hint;
					--prev;
				}
			}
			else if (hint->first < value.first)
			{
				iterator next = hint;
				++next;
				while (next != end() && next->first <= value.first)
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
			insert(ft::make_pair(first->first, first->second));
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

	size_type erase(const key_type& key)
	{
		return _tree->deleteNode(find(key).base());
	}

	void swap(map& other)
	{
		std::swap(_tree, other._tree);
	}

	size_type count(const Key& key) const
	{
		return (find(key) == end()) ? 0 : 1;
	}

	iterator find(const Key& key)
	{
		tree_node<value_type> *current = _tree->_root;
		while (!current->_nil)
		{
			if (key == current->_data->first)
			{
				return (current);
			}
			else
			{
				current = _comp(key, current->_data->first) ? current->_left : current->_right;
			}
		}
		return end();
	}

	const_iterator find( const Key& key ) const
	{
		tree_node<value_type> *current = _tree->_root;
		while (!current->_nil)
		{
			if (key == current->_data->first)
			{
				return (current);
			}
			else
			{
				current = _comp(key, current->_data->first) ? current->_left : current->_right;
			}
		}
		return end();
	}

	iterator lower_bound(const Key& key)
	{
		tree_node<value_type> *current = _tree->_root;
		while (!current->_nil)
		{
			if (key == current->_data->first)
			{
				return iterator(current);
			}
			else
			{
				if (_comp(key, current->_data->first))
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

	const_iterator lower_bound( const Key& key ) const
	{
		tree_node<value_type> *current = _tree->_root;
		while (!current->_nil)
		{
			if (key == current->_data.first)
			{
				return const_iterator(current);
			}
			else
			{
				if (_comp(key, current->_data.first))
				{
					if (!current->_left->_nil)
					{
						current = current->_left;
					}
					else
					{
						return const_iterator(current);
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
						return ++const_iterator(current);
					}
				}
			}
		}
		return end();
	}

	iterator upper_bound(const Key& key)
	{
		iterator tmp = lower_bound(key);
		return (tmp == end()) ? tmp : (_comp(key, tmp->first)) ? tmp : ++tmp;
	}

	const_iterator upper_bound( const Key& key) const
	{
		const_iterator tmp = lower_bound(key);
		return (tmp == end()) ? tmp : (_comp(key, tmp->first)) ? tmp : ++tmp;
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

	ft::map<Key, T, Compare, A>::value_compare value_comp() const
	{
		return value_compare(key_comp());
	}

	friend bool operator== (const map &lhs, const map &rhs)
	{
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	friend bool operator!= (const map &lhs, const map &rhs)
	{
		return !(lhs == rhs);
	}

	friend bool operator< (const map &lhs, const map &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	friend bool operator> (const map &lhs, const map &rhs)
	{
		return rhs < lhs;
	}

	friend bool operator>= (const map &lhs, const map &rhs)
	{
		return !(lhs < rhs);
	}

	friend bool operator<= (const map &lhs, const map &rhs)
	{
		return !(rhs < lhs);
	}

private:

	void fillTree(tree_node<value_type> *t)
	{
		if (!t->_left->_nil)
		{
			fillTree(t->_left);
		}
		if (!t->_nil)
		{
			insert(*t->_data);
		}
		if (!t->_right->_nil)
		{
			fillTree(t->_right);
		}
	}

	void clearTree(tree_node<value_type> *tmp)
	{
		if (tmp->_nil)
		{
			return;
		}
		if (!tmp->_left->_nil)
		{
			clearTree(tmp->_left);
		}
		if (!tmp->_right->_nil)
		{
			clearTree(tmp->_right);
		}
		_allocator_rebind_node.destroy(tmp);
		_allocator_rebind_node.deallocate(tmp, sizeof(tree_node<value_type>));
	}

	void clearMap()
	{
		clearTree(_tree->_root);
		_allocator_rebind_tree.destroy(_tree);
		_allocator_rebind_tree.deallocate(_tree, 1);
	}

	ft::pair<iterator, bool> insertNode(tree_node<value_type> *hint, const value_type& value)
	{
		tree_node<value_type> *current = hint;
		tree_node<value_type> *new_parent = 0;
		tree_node<value_type> *x;

		while (!current->_nil)
		{
			if (value.first == current->_data->first)
			{
				return ft::make_pair(current, false);
			}
			new_parent = current;
			current = _comp(value.first, current->_data->first) ?
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
			if (_comp(value.first, new_parent->_data->first))
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

} /* namespace ft end */

#endif
