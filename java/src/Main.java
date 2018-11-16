import Expression.Expression;
import LinkedList.*;
import SortAlgorithms.SortAlgorithms;

public class Main {
    public static void main(String[] args) {
        Expression expression = new Expression("(a+(((b*c)^d)/a)-(c*b))");
        System.out.println(expression.infixToPrefix());
    }
}
