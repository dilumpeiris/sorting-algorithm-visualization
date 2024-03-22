#include <iostream>
#include <pthread/pthread.h>
#include "Sort.h"

using namespace std;

bool sorted = false;

void *sortThread(void *srt)
{
    cout << "Thread Created: " << pthread_self() << endl;
    Sort *sort = (Sort *)srt;
    sort->bubbleSort();
    sort->randomize();
    sort->mergeSort();
    return NULL;
}

int main()
{
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    bool runing = true;

    Window window;
    Window *p_window = &window;

    if (!window.Init())
    {
        cout << "Error Initialiaing SDL" << endl;
    }

    // cout << SDL_ThreadID() << endl;

    int list[window.WINDOW_WIDTH];

    Sort sort(p_window, list, window.WINDOW_WIDTH, window.WINDOW_HEIGHT);
    sort.randomize();
    window.drawNumber(list);
    window.screenUpdate();

    pthread_t t1;
    pthread_create(&t1, nullptr, sortThread, (void *)&sort);

    while (runing)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                sort.sorted = true;
                pthread_join(t1, NULL);
                window.screenClose();
                runing = false;
            }
            // if (!sorted)
            // {
            // sort.quickSort();
            // sort.randomize();
            // sort.bubbleSort();
            // window.drawNumber(list);
            // window.screenUpdate();
            // sort.randomize();
            // window.screenClear();
            // window.drawNumber(list);
            // window.screenUpdate();
            // sort.mergeSort();
            // sorted = true;
            // }
        }
        pthread_mutex_lock(&mutex);
        window.screenClear();
        window.drawNumber(list);
        window.screenUpdate();
        pthread_mutex_unlock(&mutex);
    }
    window.screenClose();
    return 0;
}