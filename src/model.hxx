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
    }
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
    void update_num_letters() {
        num_letters_in_guess = num_letters_in_guess + 1;
    }

<<<<<<< Updated upstream
    void submit_guess() {
        submit_guess_ = true;
    }

=======
    // bool valid_guess(char* filename, char guess[5]);
>>>>>>> Stashed changes
    bool valid_guess();

    void hit_key(char actual);

    char user_guess_[5];

private:
    void load_word();
    char squares_[5][6];
    int num_letters_in_guess = 0;
    bool submit_guess_;
    std::vector<std::string> dictionary_;
    std::string correct_word_;
    size_t next_word_index_ = 0;
};
