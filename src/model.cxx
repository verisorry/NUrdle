#include <utility>

#include "model.hxx"
<<<<<<< Updated upstream
=======

using namespace std;

using namespace std;
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
    if (letter == 13) {
=======
    if (letter == 13 && num_letters_in_guess == 5) {
>>>>>>> Stashed changes
        valid_guess();
    }
    if (num_letters_in_guess < 5) {
        squares_[num_letters_in_guess][0] = letter;
        update_guess(num_letters_in_guess, letter);
    }
}

void
Model::load_word()
{
    correct_word_.clear();

    while (correct_word_.empty()) {
        correct_word_ = dictionary_[next_word_index_++ % dictionary_.size()];
    }
    
    // while (next_word_index_ < dictionary_.size() && correct_word_.empty()) {
    //     correct_word_ = dictionary_[next_word_index_++];
    // }
}
