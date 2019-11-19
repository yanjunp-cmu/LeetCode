struct Pos
{
    int i, j;
    Pos (int i0, int j0) : i(i0), j(j0){}
};
/*
 * BFS method:
 * the idea is that we can use a waterMap to indicate the water level base on
 * the maximum height of the surrounding tiles
 * the update rule is that if the max(waterMap[i][j], heightMap[i][j]) is less 
 * than its surrouding tile, change the surrounding tile to this value, which either
 * indicates its waterlevel or height level
 * if a given tile has been updated with an overestimated waterLevel and its surrouding 
 * height is less, it will be updated again and remain that way
 * somewhat like Dijkstra
 */
class Solution {
public:
    int trapRainWater(vector<vector<int>> const & heightMap) {
        queue<Pos> que;
        // obtain map dimension
        int length = heightMap.size(); 
        int width = length > 0 ? heightMap.back().size() : 0;
        vector<vector<int>> waterMap (length, vector<int>(width, INT_MAX));
        // zero out the left most and the right most column in watermap
        for (int i = 0; i < length; ++ i){
            waterMap[i][0] = 0, que.emplace(i, 0);
            if (width - 1 > 0)
                waterMap[i][width - 1] = 0, que.emplace(i, width - 1);
        }
        // zero out the top and the bottom row in waterMap
        for (int j = 1; j < width - 1; ++ j){
            waterMap[0][j] = 0, que.emplace(0, j);
            if (length - 1 > 0)
                waterMap[length - 1][j] = 0, que.emplace(length - 1, j);
        }
        while (que.size()){
            auto p = que.front(); que.pop();
            // since four edges of the waterMap are all zeroed out, 
            // the edge values will become heightMap values 
            int i = p.i, j = p.j, waterLevel = max(waterMap[i][j], heightMap[i][j]);
            if (i + 1 < length && waterLevel < waterMap[i + 1][j])
                waterMap[i + 1][j] = waterLevel, que.emplace(i + 1, j);
            if (i - 1 >= 0 && waterLevel < waterMap[i - 1][j])
                waterMap[i - 1][j] = waterLevel, que.emplace(i - 1, j);
            if (j + 1 < width && waterLevel < waterMap[i][j + 1])
                waterMap[i][j + 1] = waterLevel, que.emplace(i, j + 1);
            if (j - 1 >= 0 && waterLevel < waterMap[i][j - 1])
                waterMap[i][j - 1] = waterLevel, que.emplace(i, j - 1);
        }
        int sum = 0;
        for (int i = 0; i < length; ++ i)
            for (int j = 0; j < width; ++ j)
                sum += max(heightMap[i][j], waterMap[i][j]) - heightMap[i][j];
        return sum;
    }
};