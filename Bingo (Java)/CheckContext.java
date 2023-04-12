import java.util.HashMap;

public class CheckContext {
    private Check check;

    public CheckContext (Check check) {     // Strategy strategy
        this.check = check;
    }

    public Boolean executeCheck(HashMap<Integer, Integer> buttonsMap, Boolean bool, int rowCount) {
        return check.checkCard(buttonsMap, bool, rowCount);
    }
}