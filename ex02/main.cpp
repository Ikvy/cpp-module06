/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:54:21 by mmidon            #+#    #+#             */
/*   Updated: 2023/03/20 11:39:39 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

#include "Base.hpp"

void	basic_identify()
{
	A* A = new(class A);
	B* B = new(class B);
	C* C = new(class C);

	identify(A);
	identify(B);
	identify(C);

	delete A;
	delete B;
	delete C;
	std::cout << "\n\n\n";
}

int main()
{
	////basic identify
	basic_identify();

	//ref identify
	A A;
	B B;
	C C;

	identify(&A);
	identify(&B);
	identify(&C);
	std::cout << "\n\n\n";

	//generate && identify
	Base *Base;
	Base = generate();
	identify(Base);
}
