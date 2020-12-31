#ifndef _UI_BOX_H_
#define _UI_BOX_H_

namespace ui
{
    class Box
    {
    public:
        Box(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
        unsigned int getX();
        unsigned int getY();
        unsigned int getWidth();
        unsigned int getHeight();
        Box offsetBy(Box other);

    private:
        unsigned int x, y, width, height;
    };
} // namespace ui

#endif