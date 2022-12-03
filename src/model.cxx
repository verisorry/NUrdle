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
    if (num_letters_in_guess < 5) {
        guess_grid_[num_letters_in_guess] = letter;
        update_guess(num_letters_in_guess, tolower(letter));
        update_num_letters();
    }

    if (letter == 13) {
        if (valid_guess()) {
            // Call check the guess
            check_guess();
            // insert guess into grid
            for (int i = 0; i < grid_width; i++) {
                squares_[i][num_guesses_used] = user_guess_[i];
                cout << guess_outcome[i];
            }
            for (int j = 0; j < grid_width; j++) {
                guess_grid_[j] = ' ';
            }
            // If win
            if (strcmp(guess_outcome, cor_guess_outcome) == 0) {
                for (int i = 0; i < grid_width; i++) {
                    for (int j = 0; j < grid_height; j++) {
                        squares_[i][j] = ' ';
                    }
                }
                squares_[0][0] = 'E'; squares_[1][0] = 'L'; squares_[2][0] = 'D'; squares_[3][0] = 'E';
                squares_[4][0] = 'R'; squares_[0][1] = 'O'; squares_[1][1] = 'F'; squares_[0][2] = 'A';
                squares_[0][3] = 'G'; squares_[1][3] = 'R'; squares_[2][3] = 'E'; squares_[3][3] = 'A';
                squares_[4][3] = 'T'; squares_[0][4] = 'E'; squares_[1][4] = 'R'; squares_[0][5] = 'A';
                squares_[1][5] = 'G'; squares_[2][5] = 'E';
            }
            update_num_guesses();
            reset_num_letters();
            reset_guess();
            //reset_outcome();
            // If lose
            if (num_guesses_used == 6 && strcmp(guess_outcome, cor_guess_outcome) != 0) {
                update_used_all_guesses();
                for (int i = 0; i < grid_width; i++) {
                    for (int j = 0; j < grid_height; j++) {
                        squares_[i][j] = ' ';
                    }
                }
                squares_[1][0] = 'Y';
                squares_[2][0] = 'O';
                squares_[3][0] = 'U';
                squares_[0][1] = 'L';
                squares_[1][1] = 'O';
                squares_[2][1] = 'S';
                squares_[3][1] = 'T';
                squares_[4][1] = '!';
            }
        }
        else {
            invalid_guess = true;
            for (int j = 0; j < grid_width; j++) {
                guess_grid_[j] = ' ';
            }
            reset_num_letters();
            reset_guess();
        }
    }
}
// Loads the correct answer
void
Model::load_word()
{
    correct_word_.clear();

    while (correct_word_.empty()) {
        correct_word_ = dictionary_[next_word_index_++ % dictionary_.size()];
    }
}
// Checks the guess:
void
Model::check_guess() {
    reset_outcome();
    for (int i = 0; i < grid_width; i++) {
        if (user_guess_[i] == correct_word_[i]) {
            guess_outcome[i] = 'c';
        }
        else if (correct_word_.find(user_guess_[i]) != std::string::npos) {
            guess_outcome[i] = 'p';
        }
        else {
            guess_outcome[i] = 'a';
        }
    }
}



