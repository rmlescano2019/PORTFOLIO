import java.util.ArrayList;
import java.util.Random;

public interface GameSystem {
    public int action(ArrayList<Integer> cardValues, Random random, int bingoNum);
}