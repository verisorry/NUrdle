#include "controller.hxx"

int
main()
{
    //Controller().run();
    Controller({"explicit", "word", "list"}).run();
    return 0;
}
