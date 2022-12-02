#include "model.hxx"

Model::Model() 
{
    for (int i = 0; i < grid_width; i++) {
        for (int j = 0; j < grid_height; j++) {
            squares_[i][j] = ' ';
        }
    }

}

Model::Model(const std::vector<std::string>& words)
        : dictionary_(words)
{
    load_word();
}

Model::Model(std::initializer_list<std::string> words)
        : Model(std::vector<std::string>(words))
{ }

char Model::square_at(int i, int j) const {
    return squares_[i][j];
}

void
Model::hit_key(char letter)
{
    if (letter == 13 && num_letters_in_guess == 5) {
        submit_guess();
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
    
    while (next_word_index_ < dictionary_.size() && correct_word_.empty()) {
        correct_word_ = dictionary_[next_word_index_++];
    }
}