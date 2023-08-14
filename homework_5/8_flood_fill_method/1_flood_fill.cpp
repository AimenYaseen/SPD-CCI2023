using namespace std;

#include<vector>


class Solution {
    void floodFill(vector<vector<int>>& image, int sr, int sc, int color, int oldColor)
    {
        int rows = image.size(), cols = image[0].size();

        if(sr >= 0 && sr < rows && sc >= 0 && sc < cols && image[sr][sc] == oldColor)
        {
            image[sr][sc] = color;

            floodFill(image, sr - 1, sc, color, oldColor);
            floodFill(image, sr + 1, sc, color, oldColor);
            floodFill(image, sr, sc - 1, color, oldColor);
            floodFill(image, sr, sc + 1, color, oldColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        // No need to do anything if newColor is the same as the starting pixel's color
        if(oldColor == color)
            return image;  

        floodFill(image, sr, sc, color, oldColor);
        return image;
    }
};