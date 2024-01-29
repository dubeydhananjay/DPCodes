public class SubsetSum {

    public static boolean isSubsetSum(int[] arr, int n, int sum) {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;

        if (arr[n - 1] > sum) {
            return isSubsetSum(arr, n - 1, sum);
        }
        return isSubsetSum(arr, n - 1, sum - arr[n - 1]) || isSubsetSum(arr, n - 1, sum);
    }

    public static void main(String[] args) {
        int[] arr = {2, 3, 7, 8, 10};
        int n = arr.length;
        int sum = 16;

        if (isSubsetSum(arr, n, sum)) {
            System.out.println("TRUE");
        } else {
            System.out.println("FALSE");
        }
    }
}
