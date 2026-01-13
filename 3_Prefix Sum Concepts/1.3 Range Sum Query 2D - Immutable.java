// Range Sum Query 2D - Immutable.java

class NumMatrix {
    private int[][] prefixSum;

    public NumMatrix(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return;

        int rows = matrix.length;
        int columns = matrix[0].length;

        // In Java, this is how we "assign" or initialize the size
        this.prefixSum = new int[rows][columns];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                // Start with the current number
                prefixSum[i][j] = matrix[i][j];
                
                // Add the sum from above
                if (i > 0) prefixSum[i][j] += prefixSum[i - 1][j];
                
                // Add the sum from the left
                if (j > 0) prefixSum[i][j] += prefixSum[i][j - 1];
                
                // Subtract the top-left corner because it was added twice
                if (i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i - 1][j - 1];
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        int rectangleSum = prefixSum[row2][col2];
        
        // Remove the part above our target rectangle
        if (row1 > 0) rectangleSum -= prefixSum[row1 - 1][col2];
        
        // Remove the part to the left of our target rectangle
        if (col1 > 0) rectangleSum -= prefixSum[row2][col1 - 1];
        
        // Add back the corner we subtracted twice
        if (row1 > 0 && col1 > 0) rectangleSum += prefixSum[row1 - 1][col1 - 1];

        return rectangleSum;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

 // TC : O(rows * columns)
 // SC : O(rows * columns)
