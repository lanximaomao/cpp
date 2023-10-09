#ifndef PMERGEME_JPP
# define PMERGEME_JPP

#include <iostream>
#include <vector>
#include <list>


class PmergeMe
{
	private:

	public:
		static std::vector<int>		_vbefore;
		static std::vector<int>		_vafter;
		static std::list<int>		_lbefore;
		static std::list<int>		_lafter;

		PmergeMe();
		PmergeMe(PmergeMe & other);
		PmergeMe& operator=(PmergeMe & other);

		static bool readDataToVector(char** argv);
		static bool readDataToList(char** argv);

		static void MergeInsertionSortVector();
		static void MergeInsertionSortList();

		static void printResult(double t_vector, double t_list);
};

#include "MergeSort.tpp"

# endif
