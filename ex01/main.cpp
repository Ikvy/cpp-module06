/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:55:19 by mmidon            #+#    #+#             */
/*   Updated: 2023/03/17 17:01:30 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Serializer Serializer;
	Data	*test;
	uintptr_t ret;

	test->my_int = 42;
	test->my_float= 42.42;
	test->my_string = "_4_2_";

	ret = Serializer.serialize(test);
	std::cout << "result : " << Serializer.deserialize(ret)->my_int << std::endl;
}
