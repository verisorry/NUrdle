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
    // This needs to do something!
}
