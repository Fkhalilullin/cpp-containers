#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <iterator>
#include <exception>
#include "../utility/pair.hpp"
#include "../utility/tree.hpp"
#include "../iterator/bidirectional_iterator.hpp"
#include "../iterator/reverse_iterator.hpp"
#include "../iterator/is_input_iterator_tag.hpp"


namespace ft
{
	template <class Arg1, class Arg2, class Result>
  	struct binary_function
	{
    	typedef Arg1 	first_argument_type;
    	typedef Arg2 	second_argument_type;
    	typedef Result 	result_type;
  	};

	template <class T> 
	struct less : binary_function <T,T,bool>
	{
  		bool operator() (const T& x, const T& y) const
		{
			return (x < y);
		}
	};
} 


namespace ft 
{
	template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > > 
	class map {
	public:
		typedef Key																						key_type;
		typedef T																						mapped_type;
		typedef typename ft::pair<const key_type, mapped_type>											value_type;

	private:

		class value_compare
		{  
			friend class map;
		protected:
			Compare _comp;
			value_compare(Compare c) : _comp(c) {}

		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator()(const value_type& x, const value_type& y) const {
				return _comp(x.first, y.first);
			}
		};

	public:

		typedef Compare																					key_compare;
		typedef Alloc																					allocator_type;
		typedef typename allocator_type::reference														reference;
		typedef typename allocator_type::const_reference												const_reference;
		typedef typename allocator_type::pointer														pointer;
		typedef typename allocator_type::const_pointer													const_pointer;

		typedef typename ft::bidirectional_iterator<value_type, value_type*, value_type&>				iterator;
		typedef typename ft::bidirectional_iterator<value_type, const value_type*, const value_type&>	const_iterator;

		typedef typename ft::reverse_iterator<iterator>													reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>											const_reverse_iterator;

		typedef typename std::size_t																	size_type;
		typedef typename std::ptrdiff_t																	difference_type;

		///////////////////////MEMBER FUNCTION///////////////////////

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
		_tree(RBTree<value_type, value_compare, allocator_type>(value_compare(comp), alloc)) {}

		template <class InputIterator>
  		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), 
	  	typename ft::enable_if<ft::is_input_iterator_tag<typename InputIterator::iterator_category>::value>::type* = NULL) :
		_tree(RBTree<value_type, value_compare, allocator_type>(value_compare(comp), alloc)) 
		{ 
			insert(first, last); 
		}

		map(const map& x) :
		_tree(RBTree<value_type, value_compare, allocator_type>(value_compare(Compare()), Alloc())) 
		{
			_tree.insert(x._tree.begin(), x._tree.end());
		}

		~map() {}

		map& operator=(const map& x) 
		{
			_tree.clear();
			_tree.insert(x._tree.begin(), x._tree.end());
			return(*this);
		}

		/////////////////////////////////////////////////////////////

		/////////////////////////ITERATORS///////////////////////////

		iterator				begin() { return _tree.begin(); }
		const_iterator			begin() const { return _tree.begin(); }

		iterator				end() { return _tree.end(); }
		const_iterator			end() const { return _tree.end(); }

		reverse_iterator		rbegin() { return _tree.rbegin(); }
		const_reverse_iterator	rbegin() const { return _tree.rbegin(); }

		reverse_iterator		rend() { return _tree.rend(); }
		const_reverse_iterator	rend() const { return _tree.rend(); }

		/////////////////////////////////////////////////////////////

		//////////////////////////CAPACITY///////////////////////////

		bool		empty() const { return _tree.empty(); }

		size_type	size() const { return _tree.size(); }

		size_type	max_size() const { return _tree.max_size();}

		/////////////////////////////////////////////////////////////

		///////////////////////ELEMENT ACCESS////////////////////////

		mapped_type& operator[] (const key_type& k) {
			return((*((this->insert(ft::make_pair(k, mapped_type()))).first)).second);
		}

		/////////////////////////////////////////////////////////////

		//////////////////////////MODIFIERS//////////////////////////

		pair<iterator,bool>	insert (const value_type& val) { return _tree.insert(val) ; }

		iterator			insert (iterator position, const value_type& val) { return _tree.insert(position, val); }

		template <class InputIterator>
  		void				insert (InputIterator first, InputIterator last,
		typename ft::enable_if<ft::is_input_iterator_tag<typename InputIterator::iterator_category>::value>::type* = NULL) {
			return _tree.insert(first, last); 
		}

		void		erase (iterator position) { _tree.erase(position); }

		size_type	erase (const key_type& k) { return _tree.erase(ft::make_pair(k, mapped_type())); }

     	void		erase (iterator first, iterator last) { _tree.erase(first, last); }

		void		swap(map& x) { _tree.swap(x._tree); }

		void		clear() { _tree.clear(); }

		/////////////////////////////////////////////////////////////
		
		//////////////////////////OBSERVERS//////////////////////////

		key_compare		key_comp() const { return _tree.value_comp()._comp; }

		value_compare	value_comp() const { return _tree.value_comp(); }

		/////////////////////////////////////////////////////////////
		
		//////////////////////////OPERATION//////////////////////////

		iterator		find (const key_type& k) { return _tree.find(ft::make_pair(k, mapped_type())); }
		const_iterator	find (const key_type& k) const { return _tree.find(ft::make_pair(k, mapped_type())); }

		size_type 		count (const key_type& k) const { return _tree.count(ft::make_pair(k, mapped_type())); }

		iterator		lower_bound (const key_type& k) { return _tree.lower_bound(ft::make_pair(k, mapped_type())); }
		const_iterator	lower_bound (const key_type& k) const { return _tree.lower_bound(ft::make_pair(k, mapped_type())); }

		iterator		upper_bound (const key_type& k) { return _tree.upper_bound(ft::make_pair(k, mapped_type())); }
		const_iterator	upper_bound (const key_type& k) const { return _tree.upper_bound(ft::make_pair(k, mapped_type())); }

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const {	return _tree.equal_range(ft::make_pair(k, mapped_type()));}
		pair<iterator,iterator>             equal_range (const key_type& k) { return  _tree.equal_range(ft::make_pair(k, mapped_type()));}

		/////////////////////////////////////////////////////////////
		
		//////////////////////////ALLOCATOR//////////////////////////

		allocator_type get_allocator() const { return allocator_type(); }

		/////////////////////////////////////////////////////////////
	private:
		RBTree<value_type, value_compare, allocator_type>				_tree;
	};
}

#endif