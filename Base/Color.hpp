#pragma once

class Color
{
  public:
    // default constructor
    Color() {}

    // create a Color object with red, green and blue values
    Color(int r, int g, int b)
    {
        red = r;
        green = g;
        blue = b;
    }

    int red;
    int green;
    int blue;
};
