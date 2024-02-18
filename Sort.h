#include "Window.h"
class Sort
{
private:
    /* data */
public:
    int *p_list;
    Window *p_window;
    Sort(/* args */);
    void bubbleSort(int length);
    int part(int start, int end);
    void quickSort(int start, int end);
    void merge(int list[], int start, int mid, int end);
    void mergeSort(int list[], int start, int end);
    ~Sort();
};
