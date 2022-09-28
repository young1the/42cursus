#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack() : std::stack<T>(){}
	~MutantStack(){}
	MutantStack<T>(MutantStack<T> const & other) : std::stack<T>(other){}
	MutantStack<T> & operator =(MutantStack<T> const & other)
	{
		this->c = other->c;
		return *this;
	}

	iterator begin(void)
	{
		return (this->c.begin());
	}
	iterator end(void)
	{
		return (this->c.end());
	}

};