import java.util.ArrayList;
import java.util.Random;

public class DisplayBall implements GameSystem {
    int letter;

    @Override
    public int action(ArrayList<Integer> cardValues, Random random, int bingoNum) {
        if (bingoNum > 0 && bingoNum <= 15) {
            letter = 0;
        }
        else if (bingoNum > 15 && bingoNum <= 30) {
            letter = 1;
        }
        else if (bingoNum > 30 && bingoNum <= 45) {
            letter = 2;
        }
        else if (bingoNum > 45 && bingoNum <= 60) {
            letter = 3;
        }
        else if (bingoNum > 60 && bingoNum <= 75) {
            letter = 4;
        }
        return letter;
    }

}
