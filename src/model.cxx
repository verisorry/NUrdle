#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "model.hxx"

using namespace std;

Model::Model() 
{
    for (int i = 0; i < grid_width; i++) {
        for (int j = 0; j < grid_height; j++) {
            squares_[i][j] = ' ';
        }
    }
    for (int i = 0; i < grid_width; i++) {
            guess_grid_[i] = ' ';
    }
}

char Model::square_at(int i, int j) const {
    return squares_[i][j];
}
char Model::guess_grid_at(int i) const {
    return guess_grid_[i];
}

bool Model::valid_guess() {
    ifstream ifs("../resources/dict.txt");
    string word = "";
    for (int i = 0; i < sizeof(user_guess_); i++) {
        word = word + user_guess_[i];
    }
    std::regex e{"\\b" + word + "\\b"};
    string line;
    while( getline(ifs, line))
    {
        if ( regex_search( line, e) )
            return true;
    }
    return false;
}

void
Model::hit_key(char letter)
{
    if (letter == 13) {
        if (valid_guess()) {
            // Call check the guess
            
            // insert guess into grid
            for (int i = 0; i < grid_width; i++) {
                squares_[i][num_guesses_used] = user_guess_[i];
            }
            update_num_guesses();
        }
//        for (int j = 0; j < grid_width; j++) {
//            squares_[j][6] = ' ';
//        }
        for (int j = 0; j < grid_width; j++) {
            guess_grid_[j] = ' ';
        }
    }
//    if (num_letters_in_guess < 5) {
//        squares_[num_letters_in_guess][6] = letter;
//        update_guess(num_letters_in_guess, letter);
//        update_num_letters();
//    }
    if (num_letters_in_guess < 5) {
        guess_grid_[num_letters_in_guess] = letter;
        update_guess(num_letters_in_guess, letter);
        update_num_letters();
    }
}

void
Model::load_word()
{
    correct_word_.clear();

    while (correct_word_.empty()) {
        correct_word_ = dictionary_[next_word_index_++ % dictionary_.size()];
    }
}


