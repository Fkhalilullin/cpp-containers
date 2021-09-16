#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <iterator>
#include <exception>
#include "pair.hpp"
#include "tree.hpp"
#include "bidirectional_iterator.hpp"
#include "../vector/reverse_iterator.hpp"

namespace ft {

	template <class Key, class T, class Compare = std::less<Key>, 
			class Alloc = std::allocator<ft::pair<const Key,T> > > 
	class map {
	public:
		typedef Key															key_type;
		typedef T															mapped_type;
		typedef typename ft::pair<key_type, mapped_type>					value_type; // add const key_type
		typedef Compare														key_compare;

		typedef RBTree<value_type>											Tree;
		typedef Node<value_type>											Node;

		class value_compare : public std::binary_function<value_type, value_type, bool> {
		public:
			bool operator() (const value_type& x, const value_type& y) const {
				return comp(x.first, y.first);
			}
		protected:
			value_compare(key_compare pr) : comp(pr) {}
			key_compare comp;
		};

		typedef Alloc														allocator_type;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;


		typedef typename ft::bidirectional_iterator<value_type, Node>		iterator;
		typedef typename ft::bidirectional_iterator<const value_type, Node>	const_iterator;

		typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		typedef typename std::size_t										size_type;
		typedef typename std::ptrdiff_t										difference_type;


		///////////////////////MEMBER FUNCTION///////////////////////

		explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) : 
			  _size(0), _allocator(alloc), _comp(comp) {}

		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());

		map (const map& x);

		~map() {};

		map& operator= (const map& x);

		/////////////////////////////////////////////////////////////

		/////////////////////////ITERATORS///////////////////////////

		iterator begin() { return iterator( _tree.getBeg()); }
		const_iterator begin() const;

		iterator end();
		const_iterator end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		reverse_iterator rend();
		const_reverse_iterator rend() const;

		/////////////////////////////////////////////////////////////

		//////////////////////////CAPACITY///////////////////////////

		bool empty() const { return this->_size == 0; }

		size_type size() const { return this->_size; }

		size_type max_size() const { return _tree.max_size(); }

		/////////////////////////////////////////////////////////////

		///////////////////////ELEMENT ACCESS////////////////////////

		mapped_type& operator[] (const key_type& k);

		/////////////////////////////////////////////////////////////

		void insert(const value_type &val) { _tree.insert(val); }

		// pair<iterator,bool> insert (const value_type& val);

		// iterator insert (iterator position, const value_type& val);

		// template <class InputIterator>
  		// void insert (InputIterator first, InputIterator last);

		void erase (iterator position);

		size_type erase (const key_type& k);

     	void erase (iterator first, iterator last);

	private:
		Tree				_tree;
		size_type			_size;
		allocator_type		_allocator;
		key_compare			_comp;
	};
}
	#endif