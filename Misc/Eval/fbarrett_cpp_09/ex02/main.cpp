/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrett <fbarrett@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:06:29 by fbarrett          #+#    #+#             */
/*   Updated: 2024/05/08 11:09:50 by fbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

using std::cout;
using std::endl;

template <typename T>
bool  fill_container(int argc, char** argv, T& container) {	
	std::string temp_argv;
	int i = 1;
	try {
		while (i < argc) {
			if (argv[i][0] == '-') {
				std::cerr << "Provided number: " << argv[i] << " is negative.";
				std::cerr << " Please provide only positive numbers." << endl;
				return (true);
			}
			temp_argv = argv[i];
			if (temp_argv.find('.') != std::string::npos
				|| temp_argv.find(',') != std::string::npos) {	
				std::cerr << "Provided number: " << argv[i] << " is not an integer.";
				std::cerr << " Please provide only whole numbers." << endl;
				return (true);
			}
			container.push_back(std::stoul(temp_argv));
			i++;
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << endl;
		return (true);
	}
	return (false);
}

template <typename T>
bool merge_sort(T& container) {
	bool selector = true;
	T temp_container;
	T temp_container2;
	if (container.size() <= 1 )
		return (false);
	for (typename T::iterator it = container.begin() ; it != container.end(); ++it) 
	{
		if (selector) 
			temp_container.push_back(*it);
		else 
			temp_container2.push_back(*it);
		selector = !selector;
	}
	while (!container.empty())
		container.pop_back();
	merge_sort(temp_container);
	merge_sort(temp_container2);
	while (!temp_container.empty() || !temp_container2.empty()) {
		if ((temp_container2.empty()) || (!temp_container.empty() && temp_container.front() <= temp_container2.front())) {			
			container.push_back(temp_container.front());
			temp_container.pop_front();		
		}
		else {
			container.push_back(temp_container2.front());
			temp_container2.pop_front();
		}
	}
	return (false);
}

template <typename T>
void	print_after(T& container) {
	cout << "After: ";
	for (typename T::iterator it = container.begin() ; it != container.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void print_before(int argc, char** argv) {
	int i = 1;
	cout << "Before: ";
	while (i < argc) {
		cout << argv[i] << " ";
		i++;
	}
	cout << endl;
}

int main(int argc, char** argv) {
	std::deque<unsigned int> deque;
	std::list<unsigned int> list;
	clock_t t1;
	clock_t deque_time;
	clock_t list_time;

	if (argc < 2) {
		cout << "Please provide numbers to sort." << endl;
		return (1);
	}
	t1 = clock();
	if (fill_container<std::deque<unsigned int> > (argc, argv, deque))
		return (1);
	merge_sort(deque);
	deque_time = clock() - t1;
	t1 = clock();
	if (fill_container<std::list<unsigned int> > (argc, argv, list))
		return (1);
	merge_sort(list);
	list_time = clock() - t1;
	print_before(argc, argv);
	print_after(deque);
	//print_after(list);
	cout << "Time to process a range of " << argc - 1 << " elements with container ";
	cout << "list: " << (double)list_time/CLOCKS_PER_SEC * 1000 << " ms." << endl;
	cout << "Time to process a range of " << argc - 1 << " elements with container ";
	cout << "deque: " << (double)deque_time/CLOCKS_PER_SEC * 1000 << " ms." << endl;

	return (0);
}
