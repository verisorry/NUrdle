#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller();

    explicit Controller(std::vector<std::string> const& words);
    Controller(std::initializer_list<std::string> words);

protected:
    void draw(ge211::Sprite_set& set) override;

    View::Dimensions initial_window_dimensions() const override;

    void on_key(ge211::Key key) override;

private:
    Model model_;
    View view_;
};
