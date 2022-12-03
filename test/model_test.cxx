#include "model.hxx"
#include <catch.hxx>

using namespace ge211;

<<<<<<< HEAD
struct Test_access {
    Model& model;

    explicit Test_access(Model&);

    void set_guess(char user_guess_[5]);

};

TEST_CASE("Check Absent Character")
{
=======
struct Test_access
{
    Model &model;

    explicit Test_access(Model &);

    void set_guess(char user_guess_[5]);
};

TEST_CASE("Check Absent Character")
{
>>>>>>> kattempt
    Model model;
    Test_access access(model);

    char test[5] = {'t', 'o', 'x', 'i', 'c'};
    access.set_guess(test);

    CHECK(model.valid_guess() == true);
    model.check_guess();

<<<<<<< HEAD
    for (int i = 0; i < 5; i++) {
=======
    for (int i = 0; i < 5; i++)
    {
>>>>>>> kattempt
        CHECK(model.guess_outcome[i] == 'a');
    }
}

TEST_CASE("Check Present Character")
{
    Model model;
    Test_access access(model);

    char test[5] = {'t', 'h', 'e', 'm', 'e'};
    access.set_guess(test);

    CHECK(model.valid_guess() == true);
    model.check_guess();
    CHECK(model.guess_outcome[0] == 'a');
    CHECK(model.guess_outcome[1] == 'a');
    CHECK(model.guess_outcome[2] == 'p');
    CHECK(model.guess_outcome[3] == 'a');
    CHECK(model.guess_outcome[4] == 'p');
}

TEST_CASE("Check Correct Character")
{
    Model model;
    Test_access access(model);
    char test[5] = {'e', 'a', 'r', 't', 'h'};
    access.set_guess(test);

    CHECK(model.valid_guess() == true);
    model.check_guess();
    CHECK(model.guess_outcome[0] == 'c');
    CHECK(model.guess_outcome[1] == 'a');
    CHECK(model.guess_outcome[2] == 'p');
    CHECK(model.guess_outcome[3] == 'a');
    CHECK(model.guess_outcome[4] == 'a');
}

TEST_CASE("Check Correct Guess")
{
    Model model;
    Test_access access(model);
    char test[5] = {'e', 'l', 'd', 'e', 'r'};
    access.set_guess(test);

    CHECK(model.valid_guess() == true);
    model.check_guess();
    CHECK(model.guess_outcome[0] == 'c');
    CHECK(model.guess_outcome[1] == 'c');
    CHECK(model.guess_outcome[2] == 'c');
    CHECK(model.guess_outcome[3] == 'c');
    CHECK(model.guess_outcome[4] == 'c');
    CHECK(model.won == true);
}

TEST_CASE("Check Failed Game")
{
    Model model;
    Test_access access(model);

<<<<<<< HEAD
    for (int i = 0; i < 5; i++) {
=======
    for (int i = 0; i < 5; i++)
    {
>>>>>>> kattempt
        char test[5] = {'t', 'o', 'x', 'i', 'c'};
        access.set_guess(test);
        CHECK(model.valid_guess() == true);
        model.check_guess();
        CHECK(model.guess_outcome[0] == 'a');
        CHECK(model.guess_outcome[1] == 'a');
        CHECK(model.guess_outcome[2] == 'a');
        CHECK(model.guess_outcome[3] == 'a');
        CHECK(model.guess_outcome[4] == 'a');
<<<<<<< HEAD
        CHECK(model.num_guesses_used == i+1);
=======
        CHECK(model.num_guesses_used == i + 1);
>>>>>>> kattempt
        CHECK(model.won == false);
    }

    CHECK(model.used_all_guesses == true);
    CHECK(model.won == false);
}

<<<<<<< HEAD
Test_access::Test_access(Model& model) 
    : model(model) 
{ }

void Test_access::set_guess(char input[5]) {
    for (int i = 0; i < 5; i++) {
=======
Test_access::Test_access(Model &model)
    : model(model)
{
}

void Test_access::set_guess(char input[5])
{
    for (int i = 0; i < 5; i++)
    {
>>>>>>> kattempt
        model.user_guess_[i] = input[i];
    }
}