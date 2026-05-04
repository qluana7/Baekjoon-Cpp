class Rectangle {
    private:
    
    int width;
    int height;
    
    public:
    
    Rectangle(int width, int height) : width(width), height(height) {  }
    
    void set_width(int width);
    void set_height(int height);
    int  get_width()  const;
    int  get_height() const;
    int  area()       const;
    int  perimeter()  const;
    bool is_square()  const;
};

void Rectangle::set_width(int width)   {
    if (width <= 0 || 1000 < width) return;
    this->width = width;
}
void Rectangle::set_height(int height) {
    if (height <= 0 || 2000 < height) return;
    this->height = height;
}
int  Rectangle::get_width()  const { return width; }
int  Rectangle::get_height() const { return height; }
int  Rectangle::area()       const { return width * height; }
int  Rectangle::perimeter()  const { return width + height << 1; }
bool Rectangle::is_square()  const { return width == height; }