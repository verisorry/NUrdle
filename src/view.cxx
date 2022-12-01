#include "view.hxx"

using Color = ge211::Color;
using Dims = ge211::Dims<int>;
using Sprite = ge211::Sprite;
using Sprite_set = ge211::Sprite_set;
using Transform = ge211::Transform;

// adjust accordingly (or set to dynamic based on dims)
static int const cell_width = 40;
static int const cell_height = 60;
static int const cell_padding = 10;

static int const guess_width = 240;
static int const guess_height = 60;

static Color const cell_colour{192, 192, 192};

View::View(Model const& model)
        : model_(model),
        cell_sprite({int(cell_width), int(cell_height)}, cell_colour),
        guess_cell_sprite({int(guess_width), int(guess_height)}, cell_colour),
        input_sprite(),
        cell_text_sprite()


{ }

void
View::draw(ge211::Sprite_set& set)
{
    for (int i = 0; i < model_.grid_height; i++) {
        for (int j = 0; j < model_.grid_width; j++) {
            ge211::Text_sprite::Builder cell_builder(sans30_);
            cell_builder << model_.square_at(i, j);

            cell_text_sprite[i][j].reconfigure(cell_builder);

            set.add_sprite(cell_text_sprite[i][j], {i*cell_width, j*cell_height});

            

        }
    }
}
