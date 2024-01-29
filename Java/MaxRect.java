import java.util.*;

class MaxRect {

    public static void nsl(int[] heights, List<Integer> v, Stack<Pair<Integer,Integer>> s, int size, int pseudoIndex) {
        for (int i = 0; i < size; i++) {
            if (s.isEmpty()) {
                v.add(pseudoIndex);
            } else if (!s.isEmpty() && s.peek().getKey() >= heights[i]) {
                while (!s.isEmpty() && s.peek().getKey() >= heights[i]) {
                    s.pop();
                }
                if (s.isEmpty()) {
                    v.add(pseudoIndex);
                } else {
                    v.add(s.peek().getValue());
                }
            } else {
                v.add(s.peek().getValue());
            }
            s.push(new Pair<>(heights[i], i));
        }
    }

   public static void nsr(int[] heights, List<Integer> v, Stack<Pair<Integer,Integer>> s, int size, int pseudoIndex) {
        for (int i = size - 1; i >= 0; i--) {
            if (s.isEmpty()) {
                v.add(pseudoIndex);
            } else if (!s.isEmpty() && s.peek().getKey() >= heights[i]) {
                while (!s.isEmpty() && s.peek().getKey() >= heights[i]) {
                    s.pop();
                }
                if (s.isEmpty()) {
                    v.add(pseudoIndex);
                } else {
                    v.add(s.peek().getValue());
                }
            } else {
                v.add(s.peek().getValue());
            }
            s.push(new Pair<>(heights[i], i));
        }
        Collections.reverse(v);
    }

    public static int largestRectangleArea(int[] heights) {
        int size = heights.length;
        List<Integer> left = new ArrayList<>();
        List<Integer> right = new ArrayList<>();
        Stack<Pair<Integer,Integer>> s = new Stack<>();
        nsl(heights, left, s, size, -1);
        s.clear();
        nsr(heights, right, s, size, size);
        int mx = Integer.MIN_VALUE;
        for (int i = 0; i < size; i++) {
            int n = (right.get(i) - left.get(i) - 1) * heights[i];
            mx = Math.max(mx, n);
        }
        return mx;
    }

    public static int maximalRectangle(char[][] matrix) {
        List<Integer> v = new ArrayList<>();
        for (int j = 0; j < matrix[0].length; j++) {
            v.add(Character.getNumericValue(matrix[0][j]));
        }
        int mx = largestRectangleArea(v);
        for (int i = 1; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                int n = Character.getNumericValue(matrix[i][j]);
                if (n == 0) {
                    v.set(j, 0);
                } else {
                    v.set(j, v.get(j) + n);
                }
            }
            mx = Math.max(largestRectangleArea(v), mx);
        }
        return mx;
    }

    public static void main (String[] args) {
        char[][] array = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
        System.out.println(maximalRectangle(array));
    }
}
