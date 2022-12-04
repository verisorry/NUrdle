#include "model.hxx"
#include <catch.hxx>
#include <iostream> 

using namespace std;

// using namespace ge211;

TEST_CASE("Check Absent Character")
{
    Model m;
    m.reset_guess();
    m.reset_outcome();
    m.load_word();

    m.num_guesses_used = 0;

    for (int i = 0; i < 5; i++) {
        m.user_guess_[i] = 't';
    }

    m.check_guess();
    CHECK(m.valid_guess() == false);
    for (int i = 0; i < 5; i++) {
        CHECK(m.guess_outcome[i] == 'a');
    }
}

TEST_CASE("Check Present Character")
{
    Model m;
    m.reset_guess();
    m.reset_outcome();
    m.load_word();

    m.num_guesses_used = 0;

    char test[5] = {'t', 'h', 'e', 'm', 'e'};

    for (int i = 0; i < 5; i++) {
        m.user_guess_[i] = test[i];
    }

    m.check_guess();
    CHECK(m.valid_guess() == true);
    CHECK(m.guess_outcome[0] == 'a');
    CHECK(m.guess_outcome[1] == 'a');
    CHECK(m.guess_outcome[2] == 'p');
    CHECK(m.guess_outcome[3] == 'a');
    CHECK(m.guess_outcome[4] == 'p');
}

TEST_CASE("Check Correct Character")
{
    Model m;
    m.reset_guess();
    m.reset_outcome();
    m.load_word();

    m.num_guesses_used = 0;

    char test[5] = {'e', 'a', 'r', 't', 'h'};

    for (int i = 0; i < 5; i++) {
        m.user_guess_[i] = test[i];
    }

    m.check_guess();
    CHECK(m.valid_guess() == true);
    CHECK(m.guess_outcome[0] == 'c');
    CHECK(m.guess_outcome[1] == 'a');
    CHECK(m.guess_outcome[2] == 'p');
    CHECK(m.guess_outcome[3] == 'a');
    CHECK(m.guess_outcome[4] == 'a');
}

TEST_CASE("Check Correct Guess")
{
    Model m;
    m.reset_guess();
    m.reset_outcome();
    m.load_word();

    m.num_guesses_used = 0;

    char test[5] = {'e', 'l', 'd', 'e', 'r'};

    for (int i = 0; i < 5; i++) {
        m.user_guess_[i] = test[i];
    }

    m.check_guess();
    CHECK(m.valid_guess() == true);
    CHECK(m.guess_outcome[0] == 'c');
    CHECK(m.guess_outcome[1] == 'c');
    CHECK(m.guess_outcome[2] == 'c');
    CHECK(m.guess_outcome[3] == 'c');
    CHECK(m.guess_outcome[4] == 'c');

    if (m.compare(m.num_guesses_used)) {
        m.won = true;
    }
    CHECK(m.won == true);
}

TEST_CASE("Check Failed Game")
{
    Model m;
    m.reset_guess();
    m.reset_outcome();
    m.load_word();

    for (int i = 0; i < 5; i++) {
        char test[5] = {'t', 'o', 'x', 'i', 'c'};
        m.num_guesses_used = i;
        for (int i = 0; i < 5; i++) {
            m.user_guess_[i] = test[i];
        }

        CHECK(m.valid_guess() == true);
        m.check_guess();
        CHECK(m.guess_outcome[0] == 'a');
        CHECK(m.guess_outcome[1] == 'a');
        CHECK(m.guess_outcome[2] == 'a');
        CHECK(m.guess_outcome[3] == 'a');
        CHECK(m.guess_outcome[4] == 'a');
        if (m.compare(m.num_guesses_used)) {
            m.won = true;
        }
        CHECK(m.won == false);
    }
}
