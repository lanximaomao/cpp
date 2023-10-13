#ifndef PMERGEME_JPP
# define PMERGEME_JPP
#define MIN_SIZE 5

#include <iostream>
#include <vector>
#include <list>


class PmergeMe
{
	private:

		std::vector<int>		_vector;
		std::list<int>			_list;

		int				_size;

		bool					_readDataToVector(char** argv);
		bool 					_readDataToList(char** argv);


		void	_sortInList(int start, int end);
		void	_listMerge(int start, int mid, int end);
		void	_listInsert(int start, int end);

		void	_sortInVector(int start, int end);
		void	_vectorMerge(int start, int mid, int end);
		void	_vectorInsert(int start, int end);




	public:

		PmergeMe();
		PmergeMe(PmergeMe & other);
		PmergeMe& operator=(PmergeMe & other);

		void action(char** argv);
};

# endif
