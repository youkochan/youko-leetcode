class Solution(object):
    
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        row = len(matrix)
        col = len(matrix[0])
        
        candidate = set()
        selected = set()
        
        candidate.add((matrix[0][0], 0, 0))
        
        while k != 0:
            smallest = min(candidate)
            i, j = smallest[1:]
            selected.add(smallest)
            candidate.remove(smallest)
            k -= 1
            
            if j + 1 < col:
                candidate.add((matrix[i][j+1], i, j+1))
            if i + 1 < row and j == 0:
                candidate.add((matrix[i+1][j], i+1, j))
            if i + 1 < row and j != 0 and (matrix[i+1][j], i+1, j-1) in selected:
                candidate.add((matrix[i+1][j], i+1, j-1))
        
        return smallest[0]
