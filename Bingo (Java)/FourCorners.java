import java.util.HashMap;

public class FourCorners implements Check {
    int fourCorners;
    
    @Override
    public Boolean checkCard(HashMap<Integer, Integer> buttonsMap, Boolean bool, int rowCount) {
        fourCorners = buttonsMap.get(0) + buttonsMap.get(4) + buttonsMap.get(20) + buttonsMap.get(24);

        if (fourCorners == 0) {
            bool = true;
        }

        return bool;
    }
}
