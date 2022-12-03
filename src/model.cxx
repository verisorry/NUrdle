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
    for (int i = 0; i < end_width; i++) {
        for (int j = 0; j < end_height; j++) {
            end_text[i][j] = ' ';
        }
    }
    for (int i = 0; i < grid_width; i++) {
        guess_grid_[i] = ' ';
    }

}

char Model::end_at(int i, int j) const {
    return end_text[i][j];
}

char Model::square_at(int i, int j) const {
    return squares_[i][j];
}
char Model::guess_grid_at(int i) const {
    return guess_grid_[i];
}
char Model::get_guess_outcome(int i) {
    return guess_outcome[i];
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
            invalid_guess = false;
            check_guess();
            // insert guess into grid
            for (int i = 0; i < grid_width; i++) {
                squares_[i][num_guesses_used] = user_guess_[i];
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
                end_text[5][0] = 'E'; end_text[6][0] = 'L'; end_text[7][0] = 'D'; end_text[8][0] = 'E';
                end_text[9][0] = 'R'; end_text[5][1] = 'O'; end_text[6][1] = 'F'; end_text[5][2] = 'A';
                end_text[5][3] = 'G'; end_text[6][3] = 'R'; end_text[7][3] = 'E'; end_text[8][3] = 'A';
                end_text[9][3] = 'T'; end_text[5][4] = 'E'; end_text[6][4] = 'R'; end_text[5][5] = 'A';
                end_text[6][5] = 'G'; end_text[7][5] = 'E';
                won = true;
            }
            update_num_guesses();
            reset_num_letters();
            reset_guess();

            //grid_start++;
            //reset_outcome();
            // If lose
            if (num_guesses_used == 6 && strcmp(guess_outcome, cor_guess_outcome) != 0) {
                update_used_all_guesses();
                for (int i = 0; i < grid_width; i++) {
                    for (int j = 0; j < grid_height; j++) {
                        squares_[i][j] = ' ';
                    }
                }
                end_text[5][0] = 'Y'; end_text[6][0] = 'O'; end_text[7][0] = 'U'; end_text[5][1] = 'L';
                end_text[6][1] = 'O'; end_text[7][1] = 'S'; end_text[8][1] = 'T'; end_text[9][1] = '!';
                end_text[5][2] = 'T'; end_text[6][2] = 'R'; end_text[7][2] = 'Y'; end_text[5][3] = 'A';
                end_text[6][3] = 'G'; end_text[7][3] = 'A'; end_text[8][3] = 'I'; end_text[9][3] = 'N';
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

//void Model::on_frame(double dt) {
//    if (invalid_guess) {
//
//    }
//    if (key_pressed_ == 'q') {
//        pokemon_ = pokemon_.next(dt);
//    }
//
//    if (key_pressed_ == 'k') {
//        //handle each frame of jumping
//        jump(dt);
//    }
//}
