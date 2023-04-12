import java.util.HashMap;

public class StraightDown implements Check {
    int straightDown;

    @Override
    public Boolean checkCard(HashMap<Integer, Integer> buttonsMap, Boolean bool, int rowCount) {
        for (int column = 0; column < 5; column++) {    // for Straight Down
            rowCount = column;
            straightDown = 0;

            for (int row = 0; row < 5; row++) {
                straightDown += buttonsMap.get(rowCount);
                rowCount += 5;
            }

            if (straightDown == 0) {
                bool = true;
                break;
            }
        }

        return bool;
    }
}
