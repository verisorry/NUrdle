#pragma once

#include "controller.hxx"
#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game {
    public:

        // opens and reads one word per line
        explicit Controller(std::string const& filename);

    protected:
        // called by ge211 when it needs to redraw the screen
        void draw(ge211::Sprite_set& sprites) override;
        // called by ge211 once before game starts (set up)
        void on_start() override;
        //called by ge211 when game engine is ready
        void on_frame(double dt) override;
        //called by ge211 when the user presses a key
        void on_key(ge211::Key key) override;
        //called by ge211 to find out window dimensions
        ge211::Dims<int> initial_window_dimensions() const override;
    
    private:
        Model model_;
        View view_;
};

// Controller::Controller()
//         : view_(model_)
// { }

// void
// Controller::draw(ge211::Sprite_set& set)
// {
//     view_.draw(set);
// }
