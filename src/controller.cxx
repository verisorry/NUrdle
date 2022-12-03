// #pragma once

#include "controller.hxx"
#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

Controller::Controller()
        : view_(model_)
{ }

View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string
Controller::initial_window_title() const {
    return view_.initial_window_title();
}

void
Controller::on_start()
{
    model_.load_word();
}

void
Controller::on_key(ge211::Key key)
{
    if (key.is_textual() || char(key.code()) == 13) {
        model_.hit_key(char(key.code()));
//        if (model_.invalid_guess) {
//            move_window_dimensions();
//        }
    }


//    if (model_.game_is_finished()) {
//        model_ = Model {"gameover"};
//    }
}

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

//void Controller::on_frame(double dt) {
//    model_.on_frame(dt);
//}
