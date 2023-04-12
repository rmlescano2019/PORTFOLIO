import java.util.HashMap;

public class StraightAcross implements Check {
    int straightAcross;
    
    @Override
    public Boolean checkCard(HashMap<Integer, Integer> buttonsMap, Boolean bool, int rowCount) {
        
        for (int row = 0; row < 5; row++) {     
            straightAcross = 0;

            for (int column = 0; column < 5; column++) {
                straightAcross += buttonsMap.get(rowCount);
                rowCount++;
            }

            if (straightAcross == 0) {
                bool = true;
                break;
            }
        }

        return bool;
    }
}
