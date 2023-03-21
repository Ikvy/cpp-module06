/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:26:03 by mmidon            #+#    #+#             */
/*   Updated: 2023/03/21 09:43:37 by mmidon           ###   ########.fr       */
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
		if (isprint(litteral[0]) && !isdigit(litteral[0]))
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
	std::string pseudoLitteral[] = {"-inff", "+inff", "nanf", "inff"};

	for (i = 0; i < 4; i++)
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
	std::string pseudoLitteral[] = {"-inf", "+inf", "nan","inf"};
	int count = 0;

	for (i = 0; i < 4; i++)
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

double ft_abs(double value)
{
	return (value < 0 ? -value : value);
}

void ScalarConverter::convert(const std::string &litteral)
{
	const std::string pseudoLitteral[] = {"-inf", "+inf", "nan", "inf"};
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
		double trueValue;
		try
		{
			trueValue = stoi(litteral);
			if (isprint(trueValue))
				std::cout << "char : " << static_cast<char> (trueValue) << std::endl;
			else
				std::cout << "char : impossible" << std::endl;
			std::cout << "int : " << trueValue << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "char : impossible" << std::endl;
			std::cout << "int : impossible" << std::endl;
		}
		std::cout << std::fixed << std::setprecision(1) << "float : " << static_cast<float> (trueValue) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double : " << static_cast<double> (trueValue) << std::endl;
	}
	else if (isFloat(litteral)) ///float
	{
		float trueValue;
		try
		{
			trueValue = stof(litteral);
			if (isprint(trueValue) && trueValue != 0)
				std::cout << "char : " << static_cast<char> (trueValue) << std::endl;
			else
				std::cout << "char : impossible" << std::endl;
			if (trueValue <= INT_MAX && trueValue >= INT_MIN)
				std::cout << "int : " << static_cast<int>(trueValue) << std::endl;
			else
				std::cout << "int : impossible" << std::endl;
			std::cout << "float : " << trueValue << "f" << std::endl;
			std::cout << "double : " << static_cast<double> (trueValue) << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}
	else if (isDouble(litteral)) //////double
	{
		double trueValue;
		try
		{
			trueValue = stod(litteral);
			if (isprint(trueValue) && trueValue != 0)
				std::cout << "char : " << static_cast<char> (trueValue) << std::endl;
			else
				std::cout << "char : impossible" << std::endl;
			if (trueValue <= INT_MAX && trueValue >= INT_MIN)
				std::cout << "int : " << static_cast<int>(trueValue) << std::endl;
			else
				std::cout << "int : impossible" << std::endl;
			if (ft_abs(trueValue) < 3.4028235677973366e+38 || litteral == pseudoLitteral[0] || litteral == pseudoLitteral[1] || litteral == pseudoLitteral[2] || litteral == pseudoLitteral[3])
				std::cout << "float : " << static_cast<float> (trueValue) << "f" << std::endl;
			else
				std::cout << "float : impossible" << std::endl;
			std::cout << "double : " << trueValue << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}
	else //none
	{
		throw ScalarConverter::UnknownTypeException();
	}
}
