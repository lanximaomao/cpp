#ifndef PMERGEME_JPP
# define PMERGEME_JPP
#define MIN_SIZE 2

#include <iostream>
#include <vector>
#include <deque>


class PmergeMe
{
	private:

		std::vector<int>	_vector;
		std::deque<int>		_deque;

		int					_size;

		bool				_readDataToVector(char** argv);
		bool 				_readDataToDeque(char** argv);


		void				_sortInDeque(int start, int end);
		void				_dequeMerge(int start, int mid, int end);
		void				_dequeInsert(int start, int end);

		void				_sortInVector(int start, int end);
		void				_vectorMerge(int start, int mid, int end);
		void				_vectorInsert(int start, int end);

	public:

		PmergeMe();
		PmergeMe(PmergeMe & other);
		PmergeMe& operator=(PmergeMe & other);

		void action(char** argv);
};

# endif
