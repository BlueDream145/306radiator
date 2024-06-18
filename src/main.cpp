/*
** EPITECH PROJECT, 2019
** Work
** File description:
** main
*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <list>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>

int len;
int n;
int ir;
int jr;
int i;
int j;

typedef std::vector<int>            MatrixLine;
typedef std::vector<MatrixLine>     Matrix;


Matrix data;

bool vectorContain(MatrixLine m, int val)
{
    for (int y = 0; y < m.size(); y++)
        if (val == m[y])
            return (true);
    return (false);
}

void setZero(int s, int t)
{
    for (int i = s; i < t; i++) {
        data[i][i] = 1;
    }
}

int setMatrix(int offset_y)
{
    int y = 0;
    for (int i = n + 1 + offset_y; i < 2 * n - 1 + offset_y; i++) {
        int x, xn = 0;
        MatrixLine p = { 1 + y + offset_y, n + y + offset_y, n + y + 1 + offset_y,
            n + y + 2 + offset_y, 2 * n + y + 1 + offset_y };
        MatrixLine coef = { 1, 1, -4, 1, 1 };
        for (int index = 0; index < data[i].size(); index++) {
            if (vectorContain(p, x)) {
                data[i][x] = (int)((1 / 0.5 * 0.5) * (coef[xn]));
                xn++;
            }
            x++;
        }
    }
    setZero(2 * n - 1 + offset_y, 2 * n + 1 + offset_y);
    return (y + 2);
}

void createMatrix()
{
    for (int y = 0; y < n * n; y++) {
        MatrixLine tmp;
        for (int x = 0; x < n * n; x++) {
            tmp.push_back(0);
        }
        data.push_back(tmp);
    }
    setZero(0, n + 1);
    int offset_y = 0;
    while (offset_y + n < n * n -1 - n)
        offset_y += setMatrix(offset_y);
    setZero(n + offset_y, n * n);

}

void displayMatrix(Matrix m)
{
    for (int y = 0; y < m.size(); y++) {
        for (int x = 0; x < m[y].size(); x++) {
            std::cout << std::to_string(m[y][x]);
            if (x + 1 < m[y].size())
                std::cout << "\t";
        }
        std::cout << std::endl;
    }
}

Matrix setN(Matrix m)
{

    return (m);
}

bool process()
{
    createMatrix();
    displayMatrix(data);
    if (len == 3) {

    } else if (len == 5) {

    }
    return (true);
}

bool is_number(const std::string& s)
{
    for (int i = 0; i < s.size(); i++)
        if (!(s[i] >= '0' && s[i] <= '9'))
            return (false);
    return (true);
}

void    apply_transvection()
{

}

int main(int ac, char **av)
{
    std::string line;
    len = ac;
    try {
        // Help
        if (ac >= 2 && (!strcmp(av[1], "-h") || !strcmp(av[1], "-help"))) {
            std::cout << "USAGE" << std::endl;
            std::cout << "\t" << av[0] << " n ir jr [i j]" << std::endl;
            std::cout << "DESCRIPTION" << std::endl;
            std::cout << "\tn\t\tsize of the room" << std::endl;
            std::cout << "\t(ir, jr)\tcoordinates of the radiator" << std::endl;
            std::cout << "\t(i, j)\t\tcoordinates of a point in the room" << std::endl;
            return (0);
        }
        // ErrorHandling
        if (ac != 4 && ac != 6) {
            std::cerr << "Bad usage." << std::endl;
            return (84);
        }
    } catch (...) { return (84); }
    try {
        if (ac >= 3) {
            if (is_number(std::string(av[1])) == false ||
                is_number(std::string(av[2])) == false ||
                is_number(std::string(av[3])) == false) {
                    std::cerr << "Bad input." << std::endl;
                    return (84);
                }
            n = std::stoi(av[1]);
            ir = std::stoi(av[2]);
            jr = std::stoi(av[3]);
            if (n < 1 || (ir * n + jr) > n * n) {
                std::cerr << "Invalid data." << std::endl;
                return (84);
            }
        }
        if (ac == 5) {
            if (is_number(std::string(av[4])) == false ||
                is_number(std::string(av[5])) == false) {
                    std::cerr << "Bad input." << std::endl;
                    return (84);
                }
            i = std::stoi(av[4]);
            j = std::stoi(av[5]);
            if ((n * i + j) > n * n) {
                std::cerr << "Invalid data." << std::endl;
                return (84);
            }
        }
        if (!process()) {
            std::cerr << "Error during the process of the construction." << std::endl;
            return (84);
        }
    } catch (...) { return (84); }
    return (0);
}