import java.util.ArrayList;

public class Ball implements Fill {

    public void fillArrayList(ArrayList<Integer> cardValues, int start) {
        cardValues.clear();
        int end = 75;

        while (start != end + 1) {
            cardValues.add(start);      // adds 1 - 75 to the arraylist
            start++;
        }
    }
}