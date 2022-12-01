#include "model.hxx"

Model::Model() 
{
    for (int i = 0; i < grid_width; i++) {
        for (int j = 0; j < grid_height; j++) {
            squares_[i][j] = 'A';
        }
    }

}

char Model::square_at(int i, int j) const {
    return squares_[i][j];
}