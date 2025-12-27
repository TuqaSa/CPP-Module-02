/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed < tsaeed@student.42amman.com >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 04:57:00 by tsaeed            #+#    #+#             */
/*   Updated: 2025/12/22 04:40:56 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void)
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    std::cout << "Triangle vertices:" << std::endl;
    std::cout << "A: (0, 0)" << std::endl;
    std::cout << "B: (10, 0)" << std::endl;
    std::cout << "C: (5, 10)" << std::endl;
    std::cout << std::endl;

    Point inside(5.0f, 5.0f);
    Point outside(15.0f, 5.0f);
    Point onVertex(0.0f, 0.0f);
    Point onEdge(5.0f, 0.0f);
    Point nearInside(5.0f, 4.0f);

    std::cout << "Testing BSP (Binary Space Partitioning):" << std::endl;
    std::cout << "Point (5, 5) inside triangle: " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
    std::cout << "Point (15, 5) inside triangle: " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
    std::cout << "Point (0, 0) on vertex: " << (bsp(a, b, c, onVertex) ? "true" : "false") << std::endl;
    std::cout << "Point (5, 0) on edge: " << (bsp(a, b, c, onEdge) ? "true" : "false") << std::endl;
    std::cout << "Point (5, 4) near center: " << (bsp(a, b, c, nearInside) ? "true" : "false") << std::endl;

    return 0;
}
