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
    if (num_letters_in_guess < 5 && !won) {
        guess_grid_[num_letters_in_guess] = letter;
        update_guess(num_letters_in_guess, tolower(letter));
        update_num_letters();
    }

    if (letter == 13) {
        if (valid_guess()) {
            // Call check the guess
            invalid_guess = false;
            //update_num_guesses();
            check_guess();
            // insert guess into grid
            for (int i = 0; i < grid_width; i++) {
                squares_[i][num_guesses_used] = user_guess_[i];
            }
            for (int j = 0; j < grid_width; j++) {
                guess_grid_[j] = ' ';
            }
            // If win
            //if (strcmp(user_guess_, cor_guess) == 0) {
            if (compare(num_guesses_used)) {
//                for (int i = 0; i < grid_width; i++) {
//                    for (int j = 0; j < grid_height; j++) {
//                        squares_[i][j] = ' ';
//                    }
//                }
                end_text[5][0] = 'E'; end_text[6][0] = 'L'; end_text[7][0] = 'D'; end_text[8][0] = 'E';
                end_text[9][0] = 'R'; end_text[5][1] = 'O'; end_text[6][1] = 'F'; end_text[5][2] = 'A';
                end_text[5][3] = 'G'; end_text[6][3] = 'R'; end_text[7][3] = 'E'; end_text[8][3] = 'A';
                end_text[9][3] = 'T'; end_text[5][4] = 'E'; end_text[6][4] = 'R'; end_text[5][5] = 'A';
                end_text[6][5] = 'G'; end_text[7][5] = 'E';
                won = true;
            }

            //update_num_guesses();
            reset_num_letters();
            reset_guess();

            //grid_start++;
            //reset_outcome();
            // If lose
            if (num_guesses_used == 5 && !compare(num_guesses_used)) {
                update_used_all_guesses();
//                for (int i = 0; i < grid_width; i++) {
//                    for (int j = 0; j < grid_height; j++) {
//                        squares_[i][j] = ' ';
//                    }
//                }
                end_text[5][0] = 'Y'; end_text[6][0] = 'O'; end_text[7][0] = 'U'; end_text[5][1] = 'L';
                end_text[6][1] = 'O'; end_text[7][1] = 'S'; end_text[8][1] = 'T'; end_text[9][1] = '!';
                end_text[5][2] = 'T'; end_text[6][2] = 'R'; end_text[7][2] = 'Y'; end_text[5][3] = 'A';
                end_text[6][3] = 'G'; end_text[7][3] = 'A'; end_text[8][3] = 'I'; end_text[9][3] = 'N';
                won = true;
                //invalid_guess = true;
            }
            update_num_guesses();
        }
        else {
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
    //reset_outcome();
    if (num_guesses_used == 0) {
        for (int i = 0; i < 5; i++) {
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
    else if (num_guesses_used == 1) {
        for (int i = 5; i < 10; i++) {
            if (user_guess_[i-5] == correct_word_[i-5]) {
                guess_outcome[i] = 'c';
            }
            else if (correct_word_.find(user_guess_[i-5]) != std::string::npos) {
                guess_outcome[i] = 'p';
            }
            else {
                guess_outcome[i] = 'a';
            }
        }

    }
    else if (num_guesses_used == 2) {
        for (int i = 10; i < 15; i++) {
            if (user_guess_[i-10] == correct_word_[i-10]) {
                guess_outcome[i] = 'c';
            }
            else if (correct_word_.find(user_guess_[i-10]) != std::string::npos) {
                guess_outcome[i] = 'p';
            }
            else {
                guess_outcome[i] = 'a';
            }
        }
    }
    else if (num_guesses_used == 3) {
        for (int i = 15; i < 20; i++) {
            if (user_guess_[i-15] == correct_word_[i-15]) {
                guess_outcome[i] = 'c';
            }
            else if (correct_word_.find(user_guess_[i-15]) != std::string::npos) {
                guess_outcome[i] = 'p';
            }
            else {
                guess_outcome[i] = 'a';
            }
        }
    }
    else if (num_guesses_used == 4) {
        for (int i = 20; i < 25; i++) {
            if (user_guess_[i-20] == correct_word_[i-20]) {
                guess_outcome[i] = 'c';
            }
            else if (correct_word_.find(user_guess_[i-20]) != std::string::npos) {
                guess_outcome[i] = 'p';
            }
            else {
                guess_outcome[i] = 'a';
            }
        }
    }
    else if (num_guesses_used == 5) {
        for (int i = 25; i < 30; i++) {
            if (user_guess_[i-25] == correct_word_[i-25]) {
                guess_outcome[i] = 'c';
            }
            else if (correct_word_.find(user_guess_[i-25]) != std::string::npos) {
                guess_outcome[i] = 'p';
            }
            else {
                guess_outcome[i] = 'a';
            }
        }
    }


//    for (int i = 0; i < grid_width; i++) {
//        if (user_guess_[i] == correct_word_[i]) {
//            guess_outcome[i] = 'c';
//        }
//        else if (correct_word_.find(user_guess_[i]) != std::string::npos) {
//            guess_outcome[i] = 'p';
//        }
//        else {
//            guess_outcome[i] = 'a';
//        }
//    }
}


bool
Model::compare(int i) {
    int counter = 0;
    if (i == 0) {
        for (int j = 0; j < 5; j ++) {
            if (guess_outcome[j] == cor_guess[j]) {
                counter++;
            }
        }
        if (counter == 5) {
            counter = 0;
            return true;
        }
    }
    if (i == 1) {
        for (int j = 5; j < 10; j ++) {
            if (guess_outcome[j] == cor_guess[j-5]) {
                counter++;
            }
        }
        if (counter == 5) {
            counter = 0;
            return true;
        }

    }
    if (i == 2) {
        for (int j = 10; j < 15; j ++) {
            if (guess_outcome[j] == cor_guess[j-10]) {
                counter++;
            }
        }
        if (counter == 5) {
            counter = 0;
            return true;
        }
    }
    if (i == 3) {
        for (int j = 15; j < 20; j ++) {
            if (guess_outcome[j] == cor_guess[j-15]) {
                counter++;
            }
        }
        if (counter == 5) {
            counter = 0;
            return true;
        }
    }
    if (i == 4) {
        for (int j = 20; j < 25; j ++) {
            if (guess_outcome[j] == cor_guess[j-20]) {
                counter++;
            }
        }
        if (counter == 5) {
            counter = 0;
            return true;
        }
    }
    if (i == 5) {
        for (int j = 25; j < 30; j ++) {
            if (guess_outcome[j] == cor_guess[j-25]) {
                counter++;
            }
        }
        if (counter == 5) {
            counter = 0;
            return true;
        }
    }
    counter = 0;
    return false;
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



