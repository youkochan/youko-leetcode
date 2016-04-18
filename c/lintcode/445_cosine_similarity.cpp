class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        if (A.size() != B.size())
            return 2.0000;
        long long sumA = 0;
        long long sumB = 0;
        long long sumAB = 0;

        for (int i = 0; i < A.size(); i ++) {
            sumA += A[i] * A[i];
            sumB += B[i] * B[i];
            sumAB += A[i] * B[i];
        }

        if (!sumA || !sumB)
            return 2.0000;
        else {
            return (double)sumAB / sqrt(sumA * sumB);
        }
    }
};
