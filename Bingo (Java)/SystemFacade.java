import java.util.ArrayList;
import java.util.Random;

public class SystemFacade {
    private GameSystem genNum;
    private GameSystem dispBall;
    private GameSystem randPatt;

    public SystemFacade() {
        genNum = new GenerateNumber();
        dispBall = new DisplayBall();
        randPatt = new RandomizePattern();
    }

    public int generateNumber(ArrayList<Integer> cardValues, Random random, int bingoNum) {
        return genNum.action(cardValues, random, bingoNum);
    }

    public int displayBingoBall(ArrayList<Integer> cardValues, Random random, int bingoNum) {
        return dispBall.action(cardValues, random, bingoNum);
    }

    public int randomizePattern(ArrayList<Integer> cardValues, Random random, int bingoNum) {
        return randPatt.action(cardValues, random, bingoNum);
    }
}