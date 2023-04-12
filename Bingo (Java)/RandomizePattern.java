import java.util.ArrayList;
import java.util.Random;

public class RandomizePattern implements GameSystem {
    Random rand = new Random();

    @Override
    public int action(ArrayList<Integer> cardValues, Random random, int bingoNum) {
        int randomPattern = rand.nextInt(3);
        return randomPattern;
    }
}