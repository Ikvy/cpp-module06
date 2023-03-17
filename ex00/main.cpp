/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:27:23 by mmidon            #+#    #+#             */
/*   Updated: 2023/03/17 10:22:43 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

#include "Convert.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error : bad arguments" << std::endl;
		return (1);
	}
	try
	{
		ScalarConverter::convert((const std::string &)av[1]);
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught : " << e.what() << std::endl;
	}
}
