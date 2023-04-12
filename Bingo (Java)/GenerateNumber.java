import java.util.ArrayList;
import java.util.Random;

public class GenerateNumber implements GameSystem {

    @Override
    public int action(ArrayList<Integer> cardValues, Random random, int bingoNum) {
        int numIdx = random.nextInt(cardValues.size());     // randomNum picks and index from 0 to ccurrent size of ArrayList, which denotes the index of the random number
        int randNum = cardValues.get(numIdx);               // assigns the value at index to randNum, which is our Random Number to be used

        for (int i = 0; i < cardValues.size(); i++) {
            if (cardValues.get(i) == randNum) {
                cardValues.remove(i);
            }
        }
        
        return randNum;
    }
}
