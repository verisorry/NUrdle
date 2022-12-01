#include "model.hxx"

Model::Model() 
{
    for (int i = 0; i < grid_width; i++) {
        for (int j = 0; j < grid_height; j++) {
            squares_[i][j] = ' ';
        }
    }

}

char Model::square_at(int i, int j) const {
    return squares_[i][j];
}

void
Model::hit_key(char letter)
{
    if (num_letters_in_guess < 5) {
        squares_[num_letters_in_guess][0] = letter;
        update_guess(num_letters_in_guess, letter);
    }

}