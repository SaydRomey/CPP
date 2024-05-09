/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:30:13 by cemenjiv          #+#    #+#             */
/*   Updated: 2024/04/22 16:19:11 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template < typename T >
void iter(T* tab, std::size_t size, void (*f)(T &))
{
    for (size_t i = 0; i < size; i++)
    {
        f(tab[i]);
    }
}

template < typename T >
void    print_content(T & element)
{
    std::cout << element << std::endl;
}

