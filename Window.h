#include <iostream>
#include <SDL.h>
// #include SDL2_SDL2_H
// $ { SDL2_LIBRARIES }
class Window
{
private:
    SDL_Window *m_window;
    SDL_Texture *m_texture;
    SDL_Renderer *m_renderer;

    Uint32 *m_buffer;

public:
    const static int WINDOW_HEIGHT = 500;
    const static int WINDOW_WIDTH = 800;

    Window();

    bool Init();
    void setPixels(int x, int y, Uint8 r, Uint8 g, Uint8 b);
    void drawNumber(int list[]);
    void screenUpdate();

    void screenClear();

    void screenClose();

    ~Window();
};
