import Expression.Expression;
import LinkedList.*;
import SortAlgorithms.SortAlgorithms;

public class Main {
    public static void main(String[] args) {
        Expression expression = new Expression("-+a*b^ca/bc");
        System.out.println(expression.prefixToInfix());
    }
}
