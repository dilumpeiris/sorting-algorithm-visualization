#include <iostream>

#include "Sort.h"

using namespace std;

void randomize(int list[], int length, int max)
{
    for (size_t i = 0; i < length; i++)
    {
        int random = rand() % (max);

        list[i] = random;
    }
}

int main()
{
    bool runing = true;

    Window window;
    Window *p_window = &window;

    Sort sort;

    if (!window.Init())
    {
        std::cout << "Error Initialiaing SDL" << std::endl;
    }

    int list[window.WINDOW_WIDTH];

    randomize(list, window.WINDOW_WIDTH, window.WINDOW_HEIGHT);

    sort.p_list = list;
    sort.p_window = &window;

    // sort.quickSort();
    bool sorted = false;
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
                // sort.quickSort(0, 799);
                // randomize(list, window.WINDOW_WIDTH, window.WINDOW_HEIGHT);
                // window.screenClear();
                // window.drawNumber(sort.p_list);
                // window.screenUpdate();
                // sort.bubbleSort(window.WINDOW_WIDTH);
                sort.mergeSort(sort.p_list, 0, 799);
                sorted = true;
            }
        }
    }
    window.screenClose();
    return 0;
}