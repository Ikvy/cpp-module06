/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:26:03 by mmidon            #+#    #+#             */
/*   Updated: 2023/03/14 17:05:04 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <iomanip>

#include "Convert.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy)
{
	*this = cpy;
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& a)
{
	(void)a;
	return (*this);
}

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
	if (i > 1 || !isdigit(litteral[i]))
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

void ScalarConverter::convert(const std::string &litteral)
{
	if (litteral.empty())
		throw ScalarConverter::UnknownTypeException();
	if (isChar(litteral)) //char
	{
		std::cout << "char : " << litteral[0] << std::endl;
		std::cout << "int : " << static_cast<int>(litteral[0]) << std::endl;
		std::cout << "float : " <<std::fixed << std::setprecision(1) << static_cast<float> (litteral[0]) << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(litteral[0]) << "" << std::endl;
	}
	else if (isInt(litteral)) //int
	{
		double trueInt;
		try
		{
			trueInt = stoi(litteral);
			if (isascii(trueInt))
				std::cout << "char : " << static_cast<char> (trueInt) << std::endl;
			else
				std::cout << "char : impossible" << std::endl;
			std::cout << "int : " << trueInt << std::endl;
		}
		catch(std::exception)
		{
			std::cout << "char : impossible" << std::endl;
			std::cout << "int : impossible" << std::endl;
		}
		try
		{
			trueInt = stof(litteral);
			std::cout << std::fixed << std::setprecision(1) << "float : " << trueInt << "f" << std::endl;
		}
		catch(std::exception)
		{
			std::cout << "float : impossible" << std::endl;
		}
		try
		{
			trueInt = stod(litteral);
			std::cout << std::fixed << std::setprecision(1) << "double : " << trueInt << std::endl;
		}
		catch(std::exception)
		{
			std::cout << "double : impossible" << std::endl;
		}
		
	}
	else if (isFloat(litteral))
	{
		double trueInt;
		try
		{
			trueInt = static_cast<int>(stof(litteral));
			std::cout << trueInt << " aled" <<std::endl; 
			if (isascii(trueInt) && trueInt != 0)
				std::cout << "char : " << static_cast<char> (trueInt) << std::endl;
			else
				std::cout << "char : impossible" << std::endl;
			std::cout << "int : " << static_cast<int>(trueInt) << std::endl;
		}
		catch(std::exception)
		{
			std::cout << "char : impossible" << std::endl;
			std::cout << "int : impossible" << std::endl;
		}
		try
		{
			trueInt = stof(litteral);
			std::cout << std::fixed << std::setprecision(1) << "float : " << trueInt << "f" << std::endl;
		}
		catch(std::exception)
		{
			std::cout << "float : impossible" << std::endl;
		}
		try
		{
			trueInt = stod(litteral);
			std::cout << std::fixed << std::setprecision(1) << "double : " << trueInt << std::endl;
		}
		catch(std::exception)
		{
			std::cout << "double : impossible" << std::endl;
		}
	}
	else if (isDouble(litteral))
	{
		std::cout << "double" << std::endl;
	}
	else
	{
		throw ScalarConverter::UnknownTypeException();
	}
}
