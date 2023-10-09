template <typename T>
void printSeq(T const & seq)
{
	//typename T::const_iterator it = seq.cbegin();
	//while (it != seq.end())
	//{
	//	std::cout << *it << " ";
	//	it++;
	//}
	//std::cout << std::endl;
}

template <typename T>
void mergeTwoSeq(T & intSeq, T & left, T & right)
{
	std::cout << "mergin" << std::endl;
	std::cout << "intSeq size: " << intSeq.size()  << std::endl;
	typename T::iterator lit = left.begin();
	typename T::iterator lite = left.end();

	typename T::iterator rit = right.begin();
	typename T::iterator rite = right.end();

	typename T::iterator it = intSeq.begin();

	while (lit != lite && rit != rite)
	{
		if (*lit < *rit)
		{
			*it = *lit;
			lit++;
		}
		else
		{
			*it = *rit;
			rit++;
		}
		it++;
	}

	while (lit != lite)
	{
		*it = *lit;
		lit++;
		it++;
	}

	while (rit != rite)
	{
		*it = *rit;
		rit++;
		it++;
	}

}

template <typename T>
void mergeSort(T & intSeq)
{
	//std::cout << "-----Start-----" << std::endl;
	for(typename T::iterator it = intSeq.begin(); it != intSeq.end(); ++it)
		std::cout << *it << std::endl;
	//std::cout << "-----end-----" << std::endl;
	typename T::iterator it = intSeq.begin();
	for(size_t i = 0; i < intSeq.size() / 2; i++)
		it++;
	typename T::iterator mid = it;
	typename T::iterator ite = intSeq.end();

	if (intSeq.size() <= 2)
	{
		std::cout << "Returning now" << std::endl;
		return;
	}
	T leftSeq(intSeq.begin(), mid);
	T rightSeq(mid, ite);

	//printSeq(leftSeq);
	//printSeq(rightSeq);

	std::cout << "left side" << std::endl;
	mergeSort(leftSeq);
	std::cout << "right side" << std::endl;
	mergeSort(rightSeq);

	mergeTwoSeq(intSeq, leftSeq, rightSeq);
}
