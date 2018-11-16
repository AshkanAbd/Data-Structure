package Expression;

import LinkedList.Stack;

public class Expression {
    private String expression;
    private Stack<String> stack;
    private Stack<String> stack1;

    public Expression(String expression) {
        this.expression = expression;
        stack = new Stack<String>();
        stack1 = new Stack<String>();
    }

    public String infixToPostfix() {
        stack.clear();
        StringBuilder postfixBuilder = new StringBuilder();
        for (Character character : expression.toCharArray()) {
            if (character.equals('(')) {
                stack.push(character + "");
            }
            if (Character.isAlphabetic(character)) {
                postfixBuilder.append(character);
            }
            if (character.equals('+') || character.equals('-')) {
                if (stack.peek().equals("+") || stack.peek().equals("-") || stack.peek().equals("*")
                        || stack.peek().equals("/") || stack.peek().equals("^")) {
                    while (stack.peek().equals(")") || stack.peek().equals("("))
                        stack.pop();
                    postfixBuilder.append(stack.pop());
                }
                stack.push(character + "");
            }
            if (character.equals('*') || character.equals('/')) {
                if (stack.peek().equals("/") || stack.peek().equals("*") || stack.peek().equals("^")) {
                    while (stack.peek().equals(")") || stack.peek().equals("("))
                        stack.pop();
                    postfixBuilder.append(stack.pop());
                }
                stack.push(character + "");
            }
            if (character.equals('^')) {
                if (stack.peek().equals("^")) {
                    while (stack.peek().equals(")") || stack.peek().equals("("))
                        stack.pop();
                    postfixBuilder.append(stack.pop());
                }
                stack.push(character + "");
            }
            if (character.equals(')')) {
                while (!stack.peek().equals("(")) {
                    if (!stack.peek().equals(")"))
                        postfixBuilder.append(stack.pop());
                    else
                        stack.pop();
                }
                stack.pop();
            }
        }
        return postfixBuilder.toString();
    }

    public String infixToPrefix() {
        stack.clear();
        stack1.clear();
        String a;
        for (Character character : expression.toCharArray()) {
            if (character.equals('(')) {
                stack.push(character + "");
            }
            if (Character.isAlphabetic(character)) {
                stack1.push(character + "");
            }
            if (character.equals('+') || character.equals('-')) {
                if (stack.peek().equals("+") || stack.peek().equals("-") || stack.peek().equals("*")
                        || stack.peek().equals("/") || stack.peek().equals("^")) {
                    while (stack.peek().equals(")") || stack.peek().equals("(")) {
                        stack.pop();
                    }
                    a = stack1.pop();
                    a = stack1.pop() + a;
                    a = stack.pop() + a;
                    stack1.push(a);
                }
                stack.push(character + "");
            }
            if (character.equals('*') || character.equals('/')) {
                if (stack.peek().equals("/") || stack.peek().equals("*") || stack.peek().equals("^")) {
                    while (stack.peek().equals(")") || stack.peek().equals("(")) {
                        stack.pop();
                    }
                    a = stack1.pop();
                    a = stack1.pop() + a;
                    a = stack.pop() + a;
                    stack1.push(a);
                }
                stack.push(character + "");
            }
            if (character.equals('^')) {
                if (stack.peek().equals("^")) {
                    while (stack.peek().equals(")") || stack.peek().equals("(")) {
                        stack.pop();
                    }
                    a = stack1.pop();
                    a = stack1.pop() + a;
                    a = stack.pop() + a;
                    stack1.push(a);
                }
                stack.push(character + "");
            }
            if (character.equals(')')) {
                while (!stack.peek().equals("(")) {
                    if (!stack.peek().equals(")")) {
                        a = stack1.pop();
                        a = stack1.pop() + a;
                        a = stack.pop() + a;
                        stack1.push(a);
                    } else {
                        stack.pop();
                    }
                }
                stack.pop();
            }
        }
        return stack1.pop();
    }

    public String postfixToInfix() {
        stack.clear();
        String postfix = expression;
        String a;
        for (Character character : postfix.toCharArray()) {
            if (Character.isAlphabetic(character)) {
                stack.push(character + "");
            }
            if (character.equals('+') || character.equals('-') || character.equals('*')
                    || character.equals('/') || character.equals('^')) {
                a = stack.pop() + ")";
                a = character + a;
                a = "(" + stack.pop() + a;
                stack.push(a);
            }
        }
        return stack.pop();
    }

    public String prefixToInfix() {
        stack.clear();
        String prefix = new StringBuilder(expression).reverse().toString();
        String a;
        for (Character character : prefix.toCharArray()) {
            if (Character.isAlphabetic(character)) {
                stack.push(character + "");
            }
            if (character.equals('+') || character.equals('-') || character.equals('*')
                    || character.equals('/') || character.equals('^')) {
                a = "(" + stack.pop();
                a = a + character;
                a = a + stack.pop() + ")";
                stack.push(a);
            }
        }
        return stack.pop();
    }

    public String getExpression() {
        return expression;
    }

    public void setExpression(String expression) {
        this.expression = expression;
    }
}
