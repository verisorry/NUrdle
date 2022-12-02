#pragma once

#include <ge211.hxx>
#include <initializer_list>

class Model
{
public:
    Model();

    enum class Letter_outcome
    {
        absent,
        present,
        correct,
    };

    const int grid_width = 5;
    const int grid_height = 6;

    char square_at(int i, int j) const;

    void update_guess(int i, char input) {
        user_guess_[i] = input;
        num_letters_in_guess = num_letters_in_guess + 1;
    }
    void submit_guess() {
        submit_guess_ = true;
    }

    void hit_key(char actual);



private:
    void load_word();
    char squares_[5][6];
    char user_guess_[5];
    int num_letters_in_guess = 0;
    bool submit_guess_;
    std::vector<std::string> dictionary_;
    std::string correct_word_;
    size_t next_word_index_ = 0;
};
