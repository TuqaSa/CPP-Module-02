/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed < tsaeed@student.42amman.com >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 04:57:00 by tsaeed            #+#    #+#             */
/*   Updated: 2025/12/22 04:57:58 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


static Fixed abs(Fixed x)
{
    if (x < Fixed(0))
        return x * Fixed(-1);
    return x;
}

static Fixed calculateArea(Point const p1, Point const p2, Point const p3)
{
    Fixed area = (p1.getX() * (p2.getY() - p3.getY()) +
                  p2.getX() * (p3.getY() - p1.getY()) +
                  p3.getX() * (p1.getY() - p2.getY())) / Fixed(2);
    return abs(area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = calculateArea(a, b, c);

    Fixed areaPBC = calculateArea(point, b, c);
    Fixed areaAPC = calculateArea(a, point, c);
    Fixed areaABP = calculateArea(a, b, point);

    if (areaPBC == Fixed(0) || areaAPC == Fixed(0) || areaABP == Fixed(0))
        return false;

    Fixed sum = areaPBC + areaAPC + areaABP;
    Fixed epsilon = Fixed(0.01f);

    if (abs(sum - areaABC) < epsilon)
        return true;

    return false;
}
