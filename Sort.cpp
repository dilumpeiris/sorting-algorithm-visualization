#include <algorithm>
#include <iostream>
#include "Sort.h"
using namespace std;
Sort::Sort(/* args */)
{
}
void Sort::bubbleSort(int length)
{
    int i, j;
    bool swapped;
    int skip = 0;
    for (i = 0; i < length - 1; i++)
    {
        swapped = false;
        for (j = 0; j < length - i - 1; j++)
        {
            if (*(p_list + j) > *(p_list + j + 1))
            {
                swap(*(p_list + j), *(p_list + j + 1));
                swapped = true;

                if ((skip % 40) == 0)
                {
                    p_window->screenClear();
                    p_window->drawNumber(p_list);
                    p_window->screenUpdate();
                }
                skip++;
            }
        }

        if (swapped == false)
            break;
    }
}
void Sort::merge(int list[], int start, int mid, int end)
{
    int l1_l = mid - start + 1;
    int l2_l = end - mid;

    int *list_1 = new int[l1_l];
    int *list_2 = new int[l2_l];

    for (int i = 0; i < l1_l; i++)
    {
        list_1[i] = list[i + start];
    }
    for (int i = 0; i < l2_l; i++)
    {
        list_2[i] = list[i + mid + 1];
    }

    int l1_i = 0;
    int l2_i = 0;
    int l_i = start;

    while (l1_i < l1_l & l2_i < l2_l)
    {
        if (list_1[l1_i] <= list_2[l2_i])
        {
            list[l_i] = list_1[l1_i];
            l1_i++;
            p_window->screenClear();
            p_window->drawNumber(p_list);
            p_window->screenUpdate();
        }
        else
        {
            list[l_i] = list_2[l2_i];
            l2_i++;
            p_window->screenClear();
            p_window->drawNumber(p_list);
            p_window->screenUpdate();
        }
        l_i++;
    }
    while (l1_i < l1_l)
    {
        list[l_i] = list_1[l1_i];
        l1_i++;
        l_i++;
        p_window->screenClear();
        p_window->drawNumber(p_list);
        p_window->screenUpdate();
    }
    while (l2_i < l2_l)
    {
        list[l_i] = list_2[l2_i];
        l2_i++;
        l_i++;
        p_window->screenClear();
        p_window->drawNumber(p_list);
        p_window->screenUpdate();
    }

    delete[] list_1;
    delete[] list_2;
}
void Sort::mergeSort(int list[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;
    mergeSort(list, start, mid);
    mergeSort(list, mid + 1, end);
    merge(list, start, mid, end);
}
int Sort::part(int start, int end)
{
    int skip = 0;
    int pivot = p_list[end];
    int part_i = start - 1;
    for (int i = start; i <= end; i++)
    {
        if (p_list[i] < pivot)
        {
            part_i++;
            swap(p_list[part_i], p_list[i]);
            if ((skip % 10) == 0)
            {
                p_window->screenClear();
                p_window->drawNumber(p_list);
                p_window->screenUpdate();
            }
            skip++;
        }
    }
    swap(p_list[part_i + 1], p_list[end]);
    return part_i + 1;
}

void Sort::quickSort(int start, int end)
{

    if (start < end)
    {
        int part_i = part(start, end);
        quickSort(start, part_i - 1);
        quickSort(part_i + 1, end);
    }
}

Sort::~Sort()
{
}