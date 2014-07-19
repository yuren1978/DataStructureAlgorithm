       #include <vector>
    #include <iostream>
       using namespace std; 



 struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
 };


    bool online(const Point& p1, const Point& p2, const Point& p3)
    {
        int dy1 = p2.y - p1.y;
        int dy2 = p3.y - p2.y;
        
        int dx1 = p2.x - p1.x;
        int dx2 = p3.x - p2.x;
        
        if (dy1 * dx2 == dy2 * dx1) return true;
        
        return false;
    }

    int maxPoints(vector<Point> &points) {
        int s = points.size();
        
        if (s < 3) return s;
        
        int max = 1;
        
        for (int i = 0; i < s; ++i)
        {
            Point& p1 = points[i];
            int cnt = 1;

            for (int j = i + 1; j < s; ++j)
            {
                Point& p2 = points[j];
                
                if ((p2.x == p1.x) && (p2.y == p1.y))
                {
                    cnt++;
                    continue;
                }

                cnt=2;
                if (cnt > max) max = cnt;
                
                for (int k = j + 1; k < s; ++k)
                {
                    Point& p3 = points[k];
                    if (online(p1, p2, p3)) cnt++;

                    if (cnt > max) max = cnt;
                }
            }


            
            if (cnt > max) max = cnt;
            
        }
        
        return max;
    }


    int main(int argc, char const *argv[])
    {
        vector<Point> v;
        Point p0(0,0);
        Point p1(1,1);
        Point p2(1,-1);
        v.push_back(p0);
        v.push_back(p1);
        v.push_back(p2);
        cout<<maxPoints(v);

        return 0;
    }