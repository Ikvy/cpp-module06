/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:55:24 by mmidon            #+#    #+#             */
/*   Updated: 2023/03/20 11:36:49 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "Base.hpp"

Base::~Base()
{
	return ;
}

Base* generate()
{
	static int isGenerated = 0;
	if (!isGenerated)
	{
		srand(time(0));
		isGenerated = 1;
	}
	int odds = rand();

	switch(odds % 3)
	{
		case 0:
				return new(A);
		case 1:
				return new(B);
		default:
				return new(C);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "can't identify type" << std::endl;
}

void identify(Base &p)
{
	Base ptr;
	try
	{
		ptr = dynamic_cast<A&>(p);
	}
	catch (std::exception)
	{
		std::cout << "A" << std::endl;
		return;
	}
	try
	{
		ptr = dynamic_cast<B&>(p);
	}
	catch (std::exception)
	{
		std::cout << "B" << std::endl;
		return;
	}
	try
	{
		ptr = dynamic_cast<C&>(p);
	}
	catch (std::exception)
	{
		std::cout << "C" << std::endl;
		return;
	}
}
