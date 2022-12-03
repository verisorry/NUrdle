#include "view.hxx"

using Color = ge211::Color;
using Dims = ge211::Dims<int>;
using Sprite = ge211::Sprite;
using Sprite_set = ge211::Sprite_set;
using Transform = ge211::Transform;

// adjust accordingly (or set to dynamic based on dims)
static int const cell_width = 40;
static int const cell_height = 60;
// static int const cell_padding = 10;

static int const guess_width = 230;
static int const guess_height = 60;

static Color const cell_colour{105,105,105};
static Color const present_colour{78, 42, 132};
static Color const correct_colour{255, 255, 255};

View::View(Model const& model)
        : model_(model),
        cell_sprite({int(cell_width*0.85), int(cell_height*0.85)}, cell_colour),
        present_cell_sprite({int(cell_width*0.85), int(cell_height*0.85)}, present_colour),
        correct_cell_sprite({int(cell_width*0.85), int(cell_height*0.85)}, correct_colour),
        guess_cell_sprite({int(guess_width*0.85), int(guess_height*0.85)}, cell_colour),
        input_sprite(),
        cell_text_sprite()
{ }

View::Dimensions
View::initial_window_dimensions() const {
    return {cell_width * model_.grid_width + 15, cell_height * model_.grid_height + guess_height+15};
}

std::string
View::initial_window_title() const {
    return "NUrdle";
}

void
View::draw(ge211::Sprite_set& set)
{
    // for each cell in the grid, initiate an empty text sprite 
    for (int i = 0; i < model_.grid_width; i++) {
        for (int j = 0; j < model_.grid_height; j++) {

            set.add_sprite(cell_sprite, {i*cell_width+10, j*cell_height+10}, 0);

            ge211::Text_sprite::Builder cell_builder(sans30_);
            cell_builder << model_.square_at(i, j);

            cell_text_sprite[i][j].reconfigure(cell_builder);

            set.add_sprite(cell_text_sprite[i][j], {i*cell_width+10+(cell_width/6), j*cell_height+10+(cell_height/20)}, 1);
        }
    }
    // add guess cell sprite to bottom
    set.add_sprite(guess_cell_sprite, {10, model_.grid_height * cell_height+10}, 0);

    for (int i = 0; i < model_.grid_width; i++) {
        ge211::Text_sprite::Builder input_builder(sans30_);
        //input_builder << model_.user_guess_;
        input_builder << model_.guess_grid_at(i);

        input_sprite[i].reconfigure(input_builder);
        //set.add_sprite(input_sprite[i], {10, model_.grid_height * cell_height+10}, 1);
        set.add_sprite(input_sprite[i], {i*cell_width+10+(cell_width/6), 6*cell_height+10+(cell_height/20)}, 1);
    }

    if (!model_.invalid_guess) {
        for (int i = 0; i < model_.grid_width; i++) {
            if (model_.guess_outcome[i] == 'c') {
                set.add_sprite(correct_cell_sprite, {i*cell_width+10, (model_.num_guesses_used-1)*cell_height+10}, 1);
            }
            else if (model_.guess_outcome[i] == 'p') {
                set.add_sprite(present_cell_sprite, {i*cell_width+10, (model_.num_guesses_used-1)*cell_height+10}, 1);
            }
            else {
                set.add_sprite(cell_sprite, {i*cell_width+10, (model_.num_guesses_used-1)*cell_height+10}, 1);
            }
        }
    }

//    if (model_.won) {
//        for (int i = 0; i < model_.grid_width; i++) {
//            set.add_sprite(cell_sprite, {i*cell_width+10, (model_.num_guesses_used-1)*cell_height+10}, 1);
//        }
//    }

    // animate
//    if (model_.invalid_guess) {
//
//    }

    for (int x = 5; x < model_.end_width; x++) {
        for (int y = 0; y < model_.end_height; y++) {

            ge211::Text_sprite::Builder cell_builder(sans30_);
            cell_builder.color(Color::white());
            cell_builder << model_.end_at(x, y);

            end_text_sprite[x][y].reconfigure(cell_builder);

            set.add_sprite(end_text_sprite[x][y], {x*cell_width+10+(cell_width/6), y*cell_height+10+(cell_height/20)}, 2);
        }
    }

}
