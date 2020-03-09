// IntersectProject.cpp 
//for personal project in SE course

#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef struct line
{
    int A;
    int B;
    int C;
}Line;                  //format: Ax+By+C=0

typedef struct dot
{
    double x;
    double y;

    dot() {
        this->x = 0;
        this->y = 0;
    }
    dot(double x, double y) {
        this->x = x;
        this->y = y;
    }

    bool operator<(const struct dot& right)const
    {
        if (this->x == right.x && this->y == right.y)
            return false;
        else {
            if (this->y != right.y) {
                return this->y > right.y;
            }
            else {
                return this->x > right.x;
            }
        }
    }
}Dot;                    //自定义去重函数

vector<Line> lines;
set<Dot> dots;
Line tempLine;
Dot tempDot;

void intersect(Line line1, Line line2)
{
    if (line1.A * line2.B == line2.A * line1.B) {
        if (line1.A == 0 && line2.B == 0) {
            tempDot.x = -line2.C / line2.A;
            tempDot.y = -line1.C / line1.B;
            dots.insert(tempDot);
        }
        else if (line1.B == 0 && line2.A == 0) {
            tempDot.x = -line1.C / line1.A;
            tempDot.y = -line2.C / line2.B;
            dots.insert(tempDot);
        }
    }
    else {
        int divisor = line1.A * line2.B - line2.A * line1.B;
        tempDot.x = ((double)line1.B * line2.C - (double)line2.B * line1.C) / divisor;
        tempDot.y = ((double)line2.A * line1.C - (double)line1.A * line2.C) / divisor;
        dots.insert(tempDot);
    }
}
void printDots() {
    set<Dot>::iterator iter = dots.begin();
    while (iter != dots.end())
    {
        std::cout << iter->x << " " <<iter->y<< endl;
        ++iter;
    }
}
int main()
{
    int n, i = 0, j = 0;
    int x1, y1, x2, y2;
    char c;
    std::cin >> n;
    while (n--) {
        std::cin >> c >> x1 >> y1 >> x2 >> y2;
        tempLine.A = y1 - y2;
        tempLine.B = x2 - x1;
        tempLine.C = x1 * y2 - x2 * y1;

        for (i = 0;i < j;i++) {
            intersect(tempLine, lines[i]);
        }
        {
            lines.push_back(tempLine);
            j++;
        }
    }

    std::cout << dots.size()<< endl;   //返回set集合大小（即交点个数
    printDots();
    return 0;
}