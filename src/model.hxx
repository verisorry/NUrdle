#pragma once

#include <ge211.hxx>

class Model
{
    public:
    Model();

    const int grid_width = 5;
    const int grid_height = 6;

    char square_at(int i, int j) const;

};
