// #pragma once

#include "controller.hxx"
#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

Controller::Controller()
        : view_(model_)
{ }
Controller::Controller(std::vector<std::string> const& words)
        : model_(words),
          view_(model_)
{ }
Controller::Controller(std::initializer_list<std::string> words)
        : Controller(std::vector<std::string>(words))
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
