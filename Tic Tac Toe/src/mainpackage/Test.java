package mainpackage;

import java.util.Scanner;

public class Test {

	public static void main(String[] args) {
		int i = 0, k, j = 0, l, c, t = 0, v = 0;
		Grid g = new Grid();
		// implementing grid to play in
		Scanner s = new Scanner(System.in);
		// scanner to take values
		do {
			System.out.println("Do you want to choose by");
			System.out.println("1.Cell\t2.Row/colomn");
			// giving the choice to play by cell or Row/Column
			v = s.nextInt();
			// scan the answer
		} while (v != 1 && v != 2);
		// do while loop to make sure a valid answer is given
		if (v == 1) {
			// game when choosing by cell
			Methods.display(g.getX());
			// print the grid
			System.out.println();
			while (!Methods.checkforwin(g.getX(), i, j, t) && !Methods.fullgridtest(g.getX())) {
				// loop to keep the game going while no one wins and not draw
				do {
					// loop to keep asking for input if input out of grid
					System.out.println("enter cell number");
					c = s.nextInt();
					// scanner to take cell value from player
					if (c < 0 || c > 42) {
						System.out.println("Out Of Grid");
					}
				} while (c < 0 || c > 42);
				// translating cell to Row and column
				if (c % 7 == 0) {
					i = c / 7 - 1;
					j = 6;
				} else {
					i = c / 7;
					j = c % 7 - 1;
				}

				if (Methods.setplay(g.getX(), i, j, t)) {
					// if the move was valid increase the turn value by 1
					t++;
				}
				Methods.display(g.getX());
				// display board after move
				boolean z = Methods.checkforwin(g.getX(), i, j, t);
				if (z) {
					// if someone wins break out of loop
					break;
				}
				if (!z && Methods.fullgridtest(g.getX())) {
					// if grid is full and no one wins print draw
					System.out.println("Draw");
				}
				System.out.println("turn number:" + t);
			}
			s.close();
			// closing the scanner
		} else {
			// code to be executed if playing by Row and Column
			Methods.display(g.getX());
			System.out.println();
			while (!Methods.checkforwin(g.getX(), i, j, t) && !Methods.fullgridtest(g.getX())) {
				// loop to keep the game going while no one wins and not draw
				do {
					// loop to keep asking for input if input out of grid
					System.out.println("enter row number:");
					k = s.nextInt();
					// take input from user to be converted to row number
					if (k > 6 || k < 1) {
						// if condition to check that input is valid
						System.out.println("Out Of Grid");
					}
				} while (k > 6 || k < 1);
				i = k - 1;
				// convert input to row number
				do {
					// loop to keep asking for input if input out of grid
					System.out.println("enter column number:");
					l = s.nextInt();
					// take input from user to be converted to column number
					if (l > 7 || l < 1) {
						// if condition to check that input is valid
						System.out.println("Out Of Grid");
					}
				} while (l > 7 || l < 1);
				j = l - 1;
				// convert input to column number
				if (Methods.setplay(g.getX(), i, j, t)) {
					// if the move was valid increase the turn value by 1
					t++;
				}
				Methods.display(g.getX());
				// call display to show grid after each move
				boolean z = Methods.checkforwin(g.getX(), i, j, t);
				if (z) { 
					// if someone wins break out of loop
					break;
				}
				if (!z && Methods.fullgridtest(g.getX())) {
					System.out.println("Draw");
					// if grid is full and no one wins print draw
				}
				System.out.println("turn number:" + t);
			}
			s.close();
			//close scanner
		}
	}
}
