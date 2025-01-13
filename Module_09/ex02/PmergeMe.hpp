/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#	define PMERGEME_H 202402

/* **************************** [v] INCLUDES [v] **************************** */
#	include <vector> /*
#	   T <> vector;
#	        */
#	include <deque> /*
#	  class std::deque;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::vector;
using std::deque;
/* ***************************** [^] USINGS [^] ***************************** */

class PmergeMe
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	PmergeMe(void);
	PmergeMe(const PmergeMe &origin);
	~PmergeMe(void);
	PmergeMe	&operator = (const PmergeMe &origin);
	void		sort(char **tab);
	void		printVector(void);
	void		printDeque(void);
	void		isalnum(char *arr);

	template <typename T>
	void
		merge_sort(T &deque_, int beg, int end)
	{
		int	mid;

		if (beg < end)
		{
			mid = (beg + end) / 2;
			merge_sort(deque_, beg, mid);
			merge_sort(deque_, mid + 1, end);
			merge_insert(deque_, beg, mid, end);
		}
	}

	template <typename T>
	void
		merge_insert(T &deque_, int left, int mid, int right)
	{
		int				p;
		int				i;
		vector <int>	temp(right - left + 1);

		i = left, j = mid + 1, k = 0;

		while (i <= mid && j <= right)
		{
			if (deque_[i] <= deque_[j])
				temp[k++] = deque_[i++];
			else
				temp[k++] = deque_[j++];
		}

		while (i <= mid)
			temp[k++] = deque_[i++];

		while (j <= right)
			temp[k++] = deque_[j++];

		for (p = 0; p < k; p++)
			deque_[left + p] = temp[p];
	}
/* ***************************** [^] PUBLIC [^] ***************************** */
private: /* ************************ [v] PRIVATE [v] ************************ */
	vector<int> _vector;
	deque<int>	_deque;
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* PMERGEME_H */
