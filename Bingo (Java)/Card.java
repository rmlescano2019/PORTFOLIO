import java.util.ArrayList;

public class Card implements Fill {

    public void fillArrayList(ArrayList<Integer> cardValues, int start) {
        cardValues.clear();         // clears the ArrayList, ready to be added new values everytime this function is called
        int end = start + 14;

        for (int i = start; i <= end; i++) {    // i starts from 1, 16, 31, 46, 61
            cardValues.add(i);
        }
    }
}