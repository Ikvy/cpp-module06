/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:26:03 by mmidon            #+#    #+#             */
/*   Updated: 2023/03/14 11:56:40 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <ctype.h>
#include <string.h>

#include "Convert.hpp"

int isChar(std::string const &litteral)
{
	if (litteral.length() == 1)
	{
		if (isalpha(litteral[0]))
			return (1);
	}
	return (0);
}

int isInt(std::string const &litteral)
{
	size_t i = 0;
	while (litteral[i] == '+' || litteral[i] == '-')
		i++;
	if (i > 1)
		return (0);
	while (litteral[i])
	{
		if (!isdigit(litteral[i++]))
			return (0);
	}
	return (1);
}


int isFloat(std::string const &litteral)
{
	size_t i = 0;
	std::string pseudoLitteral[] = {"-inff", "+inff", "nanf"};

	for (i = 0; i < 3; i++)
		if (litteral == pseudoLitteral[i])
			return (1);
	
	if (*(litteral.end() - 1) == 'f')
	{
		i = 0;
		while (litteral[i] == '+' || litteral[i] == '-')
			i++;
		std::cout << "test "<<litteral[i] << std::endl;
		if (i > 1 || !isdigit(litteral[i]))
			return (0);

		int count = 0;
		i = 0;
		while (litteral[i])
		{
			if (litteral[i++] == '.')
				count++;
		}
		if (count != 1)
			return (0);
	
		i = litteral.find(".");
		if (litteral[i - 1] && litteral[i + 1] && isdigit(litteral[i - 1]) && isdigit(litteral[i + 1]))
			return (1);
	}
	return (0);
}

int isDouble(const std::string &litteral)
{
	size_t i = 0;
	std::string pseudoLitteral[] = {"-inf", "+inf", "nan"};
	int count = 0;

	for (i = 0; i < 3; i++)
		if (litteral == pseudoLitteral[i])
			return (1);

	i = 0;
	while (litteral[i] == '+' || litteral[i] == '-')
		i++;
	if (i > 1 || ~isdigit(litteral[i]))
		return (0);

	i = 0;
	while (litteral[i])
	{
		if (litteral[i++] == '.')
			count++;
	}
	if (count != 1)
		return (0);

	i = litteral.find(".");
	if (litteral[i - 1] && litteral[i + 1] && isdigit(litteral[i - 1]) && isdigit(litteral[i + 1]))
		return (1);
	return (0);
	
}

void convert(const std::string &litteral)
{
	if (litteral.empty())
		std::cout << "throw exception error unknown type or smth else yn" << std::endl;
	if (isChar(litteral))
	{
		std::cout << "char" << std::endl;
	}
	else if (isInt(litteral))
	{
		std::cout << "int" << std::endl;
	}
	else if (isFloat(litteral))
	{
		std::cout << "float" << std::endl;
	}
	else if (isDouble(litteral))
	{
		std::cout << "double" << std::endl;
	}
	else
	{
		std::cout << "throw exception error unknown type or smth else yn" << std::endl;
	}
}
