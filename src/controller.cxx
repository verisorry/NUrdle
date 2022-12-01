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

void
Controller::on_key(ge211::Key key)
{
    model_.hit_key(char(key.code()));

//    if (model_.game_is_finished()) {
//        model_ = Model {"gameover"};
//    }
//
//    if (model_.typing_progress().empty()) {
//        load_word_();
//    }
}

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}
