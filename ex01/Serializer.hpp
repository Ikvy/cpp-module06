/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:35:25 by mmidon            #+#    #+#             */
/*   Updated: 2023/03/17 16:59:39 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer& cpy);
		~Serializer();
		Serializer& operator=(Serializer const& cpy);

		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};
