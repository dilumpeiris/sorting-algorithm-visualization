#include "Window.h"
class Sort
{
private:
    int *p_list;
    Window *p_window;
    int p_list_len;
    int p_list_max;

    int part(int start, int end);
    void merge(int start, int mid, int end);

public:
    Sort(Window *window, int *list, int len, int max);
    void randomize();
    void bubbleSort();
    void quickSort(int start = 0, int end = Window::WINDOW_WIDTH - 1);
    void mergeSort(int start = 0, int end = Window::WINDOW_WIDTH - 1);
    ~Sort();
};
