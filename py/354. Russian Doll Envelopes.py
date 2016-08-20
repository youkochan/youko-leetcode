class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        # TLE
        l = len(envelopes)
        in_degree = [0] * l
        out = [[] for _ in range(0, l)]
        count = l
        for i in range(0, l):
            for j in range(0, l):
                if i != j and envelopes[i][0] < envelopes[j][0] and envelopes[i][1] < envelopes[j][1]:
                    in_degree[j] += 1
                    out[i].append(j)
        
        result = 0
        while True:
            # in_degree[i] == 0
            if result == 0:
                idx_list = map(lambda x: x[0], filter(lambda x: x[1] == 0, enumerate(in_degree)))
        
            if len(idx_list) == 0:
                break
        
            for x in reduce(lambda x, y: x + y, [out[idx] for idx in idx_list]):
                in_degree[x] -= 1
                if in_degree[x] == 0:
                    temp_idx_list.append(x)
            for x in idx_list:
                in_degree[x] = -1
        
            idx_list = temp_idx_list
            result += 1
        
        return result
        
