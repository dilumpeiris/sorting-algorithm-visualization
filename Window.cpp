#include "Window.h"

Window::Window() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL)
{
}

bool Window::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return 0;

    m_window = SDL_CreateWindow("Sorting Algorithms", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, WINDOW_WIDTH, WINDOW_HEIGHT);

    if (!m_window || !m_renderer || !m_texture)
    {
        SDL_DestroyWindow(m_window);
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyTexture(m_texture);
        SDL_Quit();
        return 0;
    }

    m_buffer = new Uint32[WINDOW_HEIGHT * WINDOW_WIDTH];
    memset(m_buffer, 0, WINDOW_HEIGHT * WINDOW_WIDTH * sizeof(Uint32));

    screenUpdate();

    return true;
}
void Window::setPixels(int x, int y, Uint8 r, Uint8 g, Uint8 b)
{

    Uint32 color = 0;

    color += r;
    color <<= 8;
    color += g;
    color <<= 8;
    color += b;
    color <<= 8;
    color += 0xFF;

    int pixel = (y * WINDOW_WIDTH + x);
    if (m_buffer[pixel])
        m_buffer[pixel] = color;
}
void Window::drawNumber(int list[])
{

    for (int i = 0; i < WINDOW_WIDTH; i++)
    {
        int r = (int)255.0 * (list[i] / (double)WINDOW_HEIGHT);
        for (int j = 0; j < list[i]; j++)
        {

            setPixels(i, WINDOW_HEIGHT - j, r, 255 - r, 0);
        }
    }
}
void Window::screenUpdate()
{

    SDL_RenderClear(m_renderer);
    SDL_UpdateTexture(m_texture, NULL, m_buffer, WINDOW_WIDTH * sizeof(Uint32));
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}
void Window::screenClear()
{
    memset(m_buffer, 1, WINDOW_HEIGHT * WINDOW_WIDTH * sizeof(Uint32));
}
void Window::screenClose()
{
    delete[] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
Window::~Window()
{
    screenClose();
}