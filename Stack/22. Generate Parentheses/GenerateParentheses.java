import java.util.LinkedList;
import java.util.List;

public class GenerateParentheses {

    List<String> result;
    int startBrackets;

    void generator(String s, int n, int b) {

        if (n == 0) {
            while (b > 0) {
                s += ")";
                b--;
            }
            result.add(s);
            return;
        }

        if (b == 0) {
            generator(s + "(", n - 1, b + 1);
        } else {
            generator(s + "(", n - 1, b + 1);
            generator(s + ")", n, b - 1);
        }
    }

    public List<String> generateParenthesis(int n) {

        result = new LinkedList<>();
        startBrackets = 0;

        generator("", n, startBrackets);

        return result;
    }

    public static void main(String[] args) {

        GenerateParentheses ob = new GenerateParentheses();
        ob.generateParenthesis(3);
        var it = ob.result.iterator();

        while (it.hasNext()) {
            System.out.print(it.next() + " ");
        }
        System.out.println();
    }
}
