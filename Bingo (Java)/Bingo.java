import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;

public class Bingo implements ActionListener {
    JFrame frame;
    static JLabel[] label = new JLabel[5];                          // BINGO Letters
    static JButton[] numberButtons = new JButton[25];
    static JPanel panel, panel2;
    static JLabel patternLabel, bingoLabel, ballLabel, resultLabel;
    static JButton drawButton;


    static Random random = new Random();
    static ArrayList<Integer> cardValues = new ArrayList<Integer>();                   // list of possible values to be added to the MAIN CARD
    static HashMap<Integer, Integer> buttonsMap = new HashMap<Integer, Integer>();     // HashMap for the buttons and their assigned random number


    GeneratorFactory generate = new GeneratorFactory();     // for Factory Pattern
    Fill getCard = generate.fillValues("CARD");
    Fill getBall = generate.fillValues("BALL");

    SystemFacade execute = new SystemFacade();              // for Facade Pattern

    CheckContext checkCard;                                 // for Strategy Pattern


    Font myFont = new Font("Calibri", Font.BOLD, 40);
    Font myFont2 = new Font("Calibri", Font.PLAIN, 28);
    Font myFont3 = new Font("Calibri", Font.PLAIN, 15);


    String[] bingoWord = {"B", "I", "N", "G", "O"};
    static int[] lowerBounds = {1, 16, 31, 46, 61};
    static int count, randomNum, randomIndex, rowCount = 0;
    static int balls = 45, bingoNum = 0, choosePattern = 0, pattern;
    static String bingoLetter;
    static Boolean bool = false;


    public Bingo() {
        frame = new JFrame("BINGO");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(420, 595);
        frame.setLayout(null);


        for (int i = 0; i < 5; i++) {           // Adds the BINGO letters into an array
            label[i] = new JLabel(bingoWord[i]);
            label[i].setHorizontalAlignment(JLabel.CENTER);
            label[i].setFont(myFont);
        }


        for (int i = 0; i < 5; i++) {
            getCard.fillArrayList(cardValues, lowerBounds[i]); // Factory Pattern
        
            count = i;
            for (int j = 0; j < 5; j++) {
                if (count == 12) {
                    buttonsMap.put(count, 0);  
                }
                else {
                    randomIndex = random.nextInt(cardValues.size());
                    randomNum = cardValues.get(randomIndex);

                    buttonsMap.put(count, randomNum);
                    cardValues.remove(randomIndex);
                }
                count += 5;
            }
        }

        // Next, add the Values from the HashMap using its Keys
        for (int i = 0; i < 25; i++) {
            if (i == 12) {
                numberButtons[i] = new JButton("X");
                numberButtons[i].setEnabled(false);
                continue;
            }
            numberButtons[i] = new JButton(Integer.toString(buttonsMap.get(i)));
        }

        // Next, fill an ArrayList from 1-75 for the BINGO Number picker
        getBall.fillArrayList(cardValues, 1);


        panel = new JPanel();
        panel.setBounds(50, 30, 300, 300);
        panel.setLayout(new GridLayout(6, 5, 5, 5));

        for (int i = 0; i < 30; i++) {
            if (i < 5) {
                panel.add(label[i]);                // first row is for the BINGO letters
            }
            else {
                panel.add(numberButtons[i - 5]);    // next rows are for the buttons
            }
        }


        patternLabel = new JLabel();
        patternLabel.setText("Pattern: ");
        patternLabel.setFont(myFont2);
        patternLabel.setBounds(50, 335, 300, 50);

        bingoLabel = new JLabel();
        bingoLabel.setText("BINGO Number:");
        bingoLabel.setFont(myFont2);
        bingoLabel.setBounds(50, 375, 300, 50);

        drawButton = new JButton("DRAW");
        drawButton.setBounds(233, 425, 117, 45);
        drawButton.addActionListener(this);

        ballLabel = new JLabel();
        ballLabel.setText("No. of balls left: 45");     // only 45 balls will be drawn in 1 round
        ballLabel.setFont(myFont3);
        ballLabel.setBounds(233, 470, 116, 30);

        resultLabel = new JLabel("Thanks for playing!");
        resultLabel.setText("Thanks for playing!");
        resultLabel.setFont(myFont2);
        resultLabel.setBounds(90, 500, 217, 50);
        resultLabel.setVisible(false);

        frame.add(panel);
        frame.add(patternLabel);
        frame.add(bingoLabel);
        frame.add(drawButton);
        frame.add(ballLabel);
        frame.add(resultLabel);
        frame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        balls--;
        ballLabel.setText("No. of balls left: " + balls);

        bingoNum = execute.generateNumber(cardValues, random, bingoNum);
        bingoLetter = bingoWord[execute.displayBingoBall(cardValues, random, bingoNum)];

        bingoLabel.setText("BINGO Number: " + bingoLetter + " " + bingoNum);

        if (choosePattern == 0) {           // Shows what pattern will be used for the round
            pattern = execute.randomizePattern(cardValues, random, bingoNum);

            switch(pattern) {
                case 0: patternLabel.setText("Pattern: Four Corners");      break;
                case 1: patternLabel.setText("Pattern: Straight Across");   break;
                case 2: patternLabel.setText("Pattern: Straight Down");     break;
            }
            choosePattern = 1;
        }

        for (int key : buttonsMap.keySet()) {       // checks the HashMap if a Value is the same with the Bingo Number
            if (bingoNum == buttonsMap.get(key)) {
                numberButtons[key].setEnabled(false);
                numberButtons[key].setText("X");
                buttonsMap.put(key, 0);
            }
        }


        switch(pattern) {
            case 0:
                checkCard = new CheckContext(new FourCorners());    break;
            case 1:
                checkCard = new CheckContext(new StraightAcross()); break;
            case 2:
                checkCard = new CheckContext(new StraightDown());   break;
        }
        
        if (checkCard.executeCheck(buttonsMap, bool, rowCount) == true) {   // meaning the given pattern was accomplished, BINGO!
            drawButton.setEnabled(false);

            resultLabel.setText("BINGO! YOU WIN!");
            resultLabel.setVisible(true);
        }
        else if (balls == 0) {
            drawButton.setEnabled(false);

            resultLabel.setVisible(true);
        }
    }


    public static void main(String[] args) {
        new Bingo();
    }

}
