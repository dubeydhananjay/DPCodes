public class ScrambleString {

    public static String getSubStr(String str, int startInd, int lastInd) {
        return str.substring(startInd, lastInd + 1);
    }

    public static boolean solve(String a, String b) {
        if (a.equals(b))
            return true;
        if (a.length() <= 1 || b.length() <= 1)
            return false;

        int n = a.length();
        for (int i = 1; i < n; i++) {
            boolean cond1 = solve(getSubStr(a, 0, i - 1), getSubStr(b, n - i, n - 1))
                            && solve(getSubStr(a, i, n - 1), getSubStr(b, 0, n - i - 1));
            boolean cond2 = solve(getSubStr(a, 0, i - 1), getSubStr(b, 0, i - 1))
                            && solve(getSubStr(a, i, n - 1), getSubStr(b, i, n - 1));
            if (cond1 || cond2)
                return true;
        }
        return false;
    }

    public static void main(String[] args) {
        String a = "coder";
        String b = "ocder";

        if (solve(a, b)) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }
    }
}
