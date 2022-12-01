#pragma once

#include "model.hxx"

class View
{
public:
    using Dimensions = ge211:Dims<int>;
    using Position = ge211::Posn<int>;
    using Rectangle = ge211::Rect<int>;

    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

    // Dimensions initial_window_dimensions() const;

    // std::string initial_window_title() const;

private:
    Model const& model_;

    ge211::Rectangle_sprite const cell_sprite;
    ge211::Rectangle_sprite const guess_cell_sprite;
    ge211::Font sans30 {"sans.ttf", 30};
    ge211::Text_sprite input_sprite;
    ge211::Text_sprite cell_text_sprite;
};