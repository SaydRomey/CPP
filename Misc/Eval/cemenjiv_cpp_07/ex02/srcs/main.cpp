/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2024/04/22 19:52:32 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main( void ) {

    {
        Array<int> array1;
        Array<int> array2(5);
        
        // Testing index and thrown exception 
        try{
            array1[0] = 15;
        }catch (const std::exception & e){
            std::cerr << e.what() << std::endl;
        }

        try {
            array2[5] = 15;
        }catch (const std::exception & e){
            std::cerr << e.what() << std::endl;
        }
        
        try {
            array2[-125] = 15;
        }catch (const std::exception & e){
            std::cerr << e.what() << std::endl;
        }

        try {
            array2[2147483647] = 15;
        }catch (const std::exception & e){
            std::cerr << e.what() << std::endl;
        }

        try {
            array2[-2147483648] = 15;
        }catch (const std::exception & e){
            std::cerr << e.what() << std::endl;
        }


        // Test to prove deep copy. Each array are independent.
        Array<int> array3 = array2;

        array2.print_array();
        array3.print_array();
        
        try{
            array2[0] = 1;
            array2[1] = 2;
            array2[2] = 3;
            array2[3] = 4;
            array2[4] = 5;
        }catch (const std::exception & e){
            std::cerr << e.what() << std::endl;
        }

        array2.print_array();
        array3.print_array();
    }

    return 0;
}