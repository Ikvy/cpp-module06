/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:25:12 by mmidon            #+#    #+#             */
/*   Updated: 2023/03/14 14:38:42 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception> 

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& cpy);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& a);
		static void convert(const std::string &litteral);
		class UnknownTypeException : public std::exception
		{
			public:
				 const char *what() const throw(){ return "unknown type";};
		};
};
