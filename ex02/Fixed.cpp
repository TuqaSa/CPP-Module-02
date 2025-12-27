/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed < tsaeed@student.42amman.com >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 04:56:00 by tsaeed            #+#    #+#             */
/*   Updated: 2025/12/20 05:06:08 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed(0) {}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->fixed = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int value)
{
    this->fixed = value << fract;
}

Fixed::Fixed(const float value)
{
    this->fixed = roundf(value * (1 << fract));
}

float Fixed::toFloat(void) const
{
    return (float)this->fixed / (1 << fract);
}

int Fixed::toInt(void) const
{
    return this->fixed >> fract;
}

int Fixed::getRawBits(void) const
{
    return this->fixed;
}

void Fixed::setRawBits(int const raw)
{
    this->fixed = raw;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->fixed > other.fixed;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->fixed < other.fixed;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->fixed >= other.fixed;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->fixed <= other.fixed;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->fixed == other.fixed;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->fixed != other.fixed;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->fixed + other.fixed);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->fixed - other.fixed);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->fixed * other.fixed) >> fract);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->fixed << fract) / other.fixed);
    return result;
}

Fixed &Fixed::operator++(void)
{
    this->fixed++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->fixed++;
    return temp;
}

Fixed &Fixed::operator--(void)
{
    this->fixed--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->fixed--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
