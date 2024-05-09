/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:16:53 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/11/06 22:31:24 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template < typename T >
void swap(T & a, T & b)
{
    T temp = a;
    a = b;
    b = temp;
}

template < typename T >
T & min (T & a, T & b)
{
    if (b <= a)
        return (b);
    return (a);
}

template < typename T >
T & max (T & a, T & b)
{
    if (b >= a)
        return (b);
    return (a);
}