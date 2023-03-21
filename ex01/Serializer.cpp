/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:42:50 by mmidon            #+#    #+#             */
/*   Updated: 2023/03/21 09:50:35 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer constuctor called" << std::endl;
}

Serializer::Serializer(const Serializer& cpy)
{
	*this = cpy;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destuctor called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& a)
{
	(void) a;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}
