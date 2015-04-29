/**
 * Given n non-negative integers a1, a2, ..., an, 
 * where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, 
 * such that the container contains the most water.
 *
 * 从两端开始扫描，短板向内移动。因为当长度减小时，只有板高度增加才有可能装更多的水。
 */

// 超时
// int maxArea(int* height, int heightSize) {
//     int i, j;
//     int min, dis;
//     int waterMax = -1;
    
//     for(i = 0; i <= heightSize-1; i++) {
//         for(j = i+1; j <= heightSize-1; j++) {
//             min = height[i] < height[j] ? height[i] : height[j];
//             dis = j - i;
            
//             if(min * dis > waterMax) {
//                 waterMax = min * dis;
//             }  
//         }
//     }
    
//     return waterMax;
// }

int maxArea(int* height, int heightSize) {
    int i, j;
    int min, dis;
    int waterMax = -1;
    
    i = 0;
    j = heightSize - 1;
    
    while(i < j) {
        min = height[i] < height[j] ? height[i] : height[j];
        dis = j - i;
        
        if(min * dis > waterMax) {
            waterMax = min * dis;
        }
        
        if(height[i] < height[j]) {
            i ++;
        }
        else {
            j --;
        }
    }
    
    return waterMax;
}