#pragma once

#include <ge211.hxx>
#include <initializer_list>

class Model
{
public:
    Model();

//    enum class Letter_outcome
//    {
//        absent,
//        present,
//        correct,
//    };
    //int grid_start = 0;
    const int grid_width = 5;
    const int grid_height = 6;
    const int window_width = 10;
    const int end_width = 10;
    const int end_height = 7;

    char end_at(int i, int j) const;
    char square_at(int i, int j) const;
    char guess_grid_at(int i) const;

    void update_guess(int i, char input) {
        user_guess_[i] = input;
    }
    void reset_guess() {
        memset(user_guess_, 0, sizeof user_guess_);
    }
    void reset_outcome() {
        memset(guess_outcome, 0, sizeof guess_outcome);
    }

    void update_num_letters() {
        num_letters_in_guess = num_letters_in_guess + 1;
    }
    void reset_num_letters() {
        num_letters_in_guess = 0;
    }
    void update_used_all_guesses() {
        used_all_guesses = true;
    }

    char get_guess_outcome(int i);

    void update_num_guesses() {
        num_guesses_used = num_guesses_used + 1;
    }

    bool valid_guess();

    void hit_key(char actual);

    char user_guess_[5];

    void load_word();

    void check_guess();

    char guess_outcome[5] = {'a', 'a','a', 'a','a'};

    bool invalid_guess = false;

    int num_guesses_used = 0;
//    void on_frame(double dt);
    char end_text[10][7];

    bool won = false;
private:
    char squares_[5][6];
    char guess_grid_[5];
    int num_letters_in_guess = 0;
    std::vector<std::string> dictionary_ = {"elder"};
    std::string correct_word_;
    size_t next_word_index_ = 0;
    bool used_all_guesses = false;
    char cor_guess_outcome[5] = {'c', 'c', 'c', 'c', 'c'};
};
