typedef struct
{
	int x;
	int y;
} TCoord;

void point(const TCoord* const point_coord);
void point_2(int x, int y);
void line(const TCoord* const point1, const TCoord* const point2);
void line_2(int x1, int y1, int x2, int y2);
void set_pen(const char a);
void print_text(char* str, int x, int y);
void print_text_2(char* str, const TCoord* const point_coord);
void update();