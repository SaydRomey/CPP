/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templateTesting.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:41:03 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/07 18:44:44 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */ // Function Templates

template <typename T>
T max(T a, T b)
{
	return ((a > b)? a : b);
}

int	main(void)
{
	int	i = max(1, 2);			// max<int>
	double	d = max(1.1, 2.2);	// max<double>
}

/* ************************************************************************** */ // Class Templates

template <typename T>
class Container
{
	private:
		T	_value;
	
	public:
		Container(T val) : _value(val) {}
		T	getValue(void) { return (_value) };
};

int	main(void)
{
	Container<int>		intContainer(42);
	Container<double>	doubleContainer(3.14);
}
