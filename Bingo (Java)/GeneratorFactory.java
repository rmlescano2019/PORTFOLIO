public class GeneratorFactory {

    public Fill fillValues(String fillType) {
        try {
            if (fillType.equals("CARD")) {
                return new Card();
            }
            else if (fillType.equals("BALL")) {
                return new Ball();
            }
        } catch (Exception e) {
            System.out.println("Something went wrong.");
        }
        return null;
    }
}