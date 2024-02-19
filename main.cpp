#include <iostream>
#include "Sort.h"
using namespace std;

int main()
{
    bool runing = true;
    bool sorted = false;

    Window window;
    Window *p_window = &window;
    if (!window.Init())
    {
        cout << "Error Initialiaing SDL" << endl;
    }

    int list[window.WINDOW_WIDTH];

    Sort sort(p_window, list, window.WINDOW_WIDTH, window.WINDOW_HEIGHT);

    sort.randomize();
    window.drawNumber(list);
    window.screenUpdate();

    while (runing)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                window.screenClose();
                runing = false;
            }
            if (!sorted)
            {
                sort.quickSort();
                sort.randomize();
                window.screenClear();
                window.drawNumber(list);
                window.screenUpdate();
                sort.bubbleSort();
                window.drawNumber(list);
                window.screenUpdate();
                sort.randomize();
                window.screenClear();
                window.drawNumber(list);
                window.screenUpdate();
                sort.mergeSort();
                sorted = true;
            }
        }
    }
    window.screenClose();
    return 0;
}