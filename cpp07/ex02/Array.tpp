/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:19:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/10 03:11:55 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
Array<T>::Array(): _data(NULL), _size(0) {
	std::cout << "empty Array created" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n): _data(new T[n]()), _size(n) {
	std::cout << "Array created with size " << n << std::endl;
}

template<typename T>
Array<T>::~Array() {
	delete[] _data;
	std::cout << "Array destroyed" << std::endl;
}

template<typename T>
Array<T>::Array(const Array & other) : _data(new T[other._size]), _size(other._size) {
	for (unsigned int i = 0; i < other._size; ++i) {
		_data[i] = other._data[i];
	}
	std::cout << "Array copy constructor called" << std::endl;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array & rhs) {
	if (this != rhs) {
		delete[] _data; // delete previous elements in this array
		
		this._size = rhs._size;
		this._data = new T[this._size];
            for (unsigned int i = 0; i < this._size; ++i) {
                _data[i] = rhs._data[i];
            }
	}
	std::cout << "Array assignment operator (=) overload called" << std::endl;
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int idx) {
	if (idx >= this->_size) {
		throw std::exception();
	}
	return _data[idx];
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return _size;
}
