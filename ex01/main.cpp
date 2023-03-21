/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:55:19 by mmidon            #+#    #+#             */
/*   Updated: 2023/03/21 09:50:18 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

int main()
{
	Data	test;
	uintptr_t ret;

	test.my_int = 42;
	test.my_float= 42.42;
	test.my_string = "_4_2_";

	ret = Serializer::serialize(&test);
	std::cout << "int : " << Serializer::deserialize(ret)->my_int << std::endl;
	std::cout << "float : " << Serializer::deserialize(ret)->my_float << std::endl;
	std::cout << "string : " << Serializer::deserialize(ret)->my_string << std::endl;
}
