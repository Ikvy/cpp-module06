/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:35:25 by mmidon            #+#    #+#             */
/*   Updated: 2023/03/21 09:50:05 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Data.hpp"

class Serializer
{
	private :
		Serializer();
		Serializer(const Serializer& cpy);
	public:
		~Serializer();
		Serializer& operator=(Serializer const& cpy);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
