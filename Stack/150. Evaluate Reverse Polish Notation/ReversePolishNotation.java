package Stack;

import java.util.*;

class ReversePolishNotation {

    boolean isOperator(String s) {
        String[] operators = { "+", "-", "*", "/" };

        for (var op : operators) {
            if (op.equals(s))
                return true;
        }

        return false;
    }

    int operation(String a, String b, String op) {

        int op1 = Integer.parseInt(a);
        int op2 = Integer.parseInt(b);

        switch (op.charAt(0)) {

            case '+':
                return op1 + op2;

            case '-':
                return op1 - op2;

            case '*':
                return op1 * op2;

            case '/':
                return op1 / op2;

        }

        return -1;
    }

    public int evalRPN(String[] tokens) {

        Deque<String> stack = new ArrayDeque<>();

        for (var token : tokens) {
            if (isOperator(token)) {
                String b = stack.pollLast();
                String a = stack.pollLast();
                stack.addLast(Integer.toString(operation(a, b, token)));
            } else
                stack.addLast(token);
        }

        return Integer.parseInt(stack.peekLast());
    }

    public static void main(String[] args) {

        String[] tokens = { "4", "13", "5", "/", "+" };
        ReversePolishNotation ob = new ReversePolishNotation();
        System.out.println("The result of the postfix expression: " + ob.evalRPN(tokens));
    }
}