package mainpackage;

public class Methods {
	public static void display(int g[][]) {
		// function that print the board after each play and at the begining
		System.out.println("0\t1\t2\t3\t4\t5\t6\t7");
		// column numbering
		for (int i = 0; i < 6; i++) {
			System.out.print((i + 1) + "\t");
			// row numbering
			for (int j = 0; j < 7; j++) {
				if (g[i][j] == 70) {
					// to convert the code for X to the letter 'X'
					System.out.print("X\t");
				} else if (g[i][j] == 60) {
					// to convert the code for O to the letter 'O'
					System.out.print("O\t");
				} else {
					System.out.print(g[i][j] + "\t");
					// to print cell number if it doesn't have 'X' or 'Y'
				}
			}
			System.out.println();
			// to go to a new line
		}
	}

	public static boolean checkforwin(int x[][], int i, int j, int t) {
		// method to check if their is two cells next to the last entered cell
		// containing the same value (in all directions)
		if (i < 4 && j < 5) {
			if (x[i][j] == x[i + 1][j + 1] && x[i + 1][j + 1] == x[i + 2][j + 2]) {
				if (t % 2 == 0) {
					// if statement tha is to be executed if three similar cells are found next to
					// each other to determine who is the winner based on the turn
					System.out.println("Second player(O) wins");
				} else {
					System.out.println("First player(X) wins");
				}
				return true;
			}
		}
		if (i < 4) {
			if (x[i][j] == x[i + 1][j] && x[i + 1][j] == x[i + 2][j]) {
				if (t % 2 == 0) {
					System.out.println("Second player(O) wins");
				} else {
					System.out.println("First player(X) wins");
				}
				return true;
			}
		}
		if (j < 6) {
			if (x[i][j] == x[i][j + 1] && x[i][j + 1] == x[i][j + 2]) {
				if (t % 2 == 0) {
					System.out.println("Second player(O) wins");
				} else {
					System.out.println("First player(X) wins");
				}
				return true;
			}
		}
		if (i > 0 && i < 5) {
			if (x[i - 1][j] == x[i][j] && x[i][j] == x[i + 1][j]) {
				if (t % 2 == 0) {
					System.out.println("Second player(O) wins");
				} else {
					System.out.println("First player(X) wins");
				}
				return true;
			}
		}
		if (j > 0 && j < 6) {
			if (x[i][j - 1] == x[i][j] && x[i][j] == x[i][j + 1]) {
				if (t % 2 == 0) {
					System.out.println("Second player(O) wins");
				} else {
					System.out.println("First player(X) wins");
				}
				return true;
			}
		}
		if (i > 0 && j > 0 && i < 5 && j < 6) {
			if (x[i - 1][j - 1] == x[i][j] && x[i][j] == x[i + 1][j + 1]) {
				if (t % 2 == 0) {
					System.out.println("Second player(O) wins");
				} else {
					System.out.println("First player(X) wins");
				}
				return true;
			}
		}
		if (i > 1) {
			if (x[i - 2][j] == x[i - 1][j] && x[i - 1][j] == x[i][j]) {
				if (t % 2 == 0) {
					System.out.println("Second player(O) wins");
				} else {
					System.out.println("First player(X) wins");
				}
				return true;
			}
		}
		if (j > 1) {
			if (x[i][j - 2] == x[i][j - 1] && x[i][j - 1] == x[i][j]) {
				if (t % 2 == 0) {
					System.out.println("Second player(O) wins");
				} else {
					System.out.println("First player(X) wins");
				}
				return true;
			}
		}
		if (j > 1 && i > 1) {
			if (x[i - 2][j - 2] == x[i - 1][j - 1] && x[i - 1][j - 1] == x[i][j]) {
				if (t % 2 == 0) {
					System.out.println("Second player(O) wins");
				} else {
					System.out.println("First player(X) wins");
				}
				return true;
			}
		}
		if (i < 4 && j > 1) {
			if (x[i + 2][j - 2] == x[i + 1][j - 1] && x[i + 1][j - 1] == x[i][j]) {
				if (t % 2 == 0) {
					System.out.println("Second player(O) wins");
				} else {
					System.out.println("First player(X) wins");
				}
				return true;
			}
		}
		if (i < 5 && j < 6 && i > 0 && j > 0) {
			if (x[i + 1][j - 1] == x[i][j] && x[i][j] == x[i - 1][j + 1]) {
				if (t % 2 == 0) {
					System.out.println("Second player(O) wins");
				} else {
					System.out.println("First player(X) wins");
				}
				return true;
			}
		}
		if (i > 1 && j < 5) {
			if (x[i][j] == x[i - 1][j + 1] && x[i - 1][j + 1] == x[i - 2][j + 2]) {
				if (t % 2 == 0) {
					System.out.println("Second player(O) wins");
				} else {
					System.out.println("First player(X) wins");
				}
				return true;
			}
		}
		if (j < 6 && j > 0) {
			if (x[i][j - 1] == x[i][j] && x[i][j] == x[i][j + 1]) {
				if (t % 2 == 0) {
					System.out.println("Second player(O) wins");
				} else {
					System.out.println("First player(X) wins");
				}
				return true;
			}
		}
		return false;
		// return false if no winning condition was found
	}

	public static boolean setplay(int g[][], int i, int j, int t) {
		//method to change cell value to X or O based on the turn
		if (g[i][j] == 70 || g[i][j] == 60) {
			//if condition to check if the cell contain X or O to return false
			System.out.println("Not Available!");
			return false;
		} else {
			if (t % 2 == 0) {
				g[i][j] = 70;
				//if player wants to add X '70' is inserted which is later translated to X in the display method
			} else {
				g[i][j] = 60;
				//if player wants to add O '60' is inserted which is later translated to O in the display method
			}
			return true;
		}
	}

	public static boolean fullgridtest(int g[][]) {
		//method to check if the grid is full of Xs and Os so if no one wins and the grid is full it prints draw
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 7; j++) {
				if (g[i][j] != 60 && g[i][j] != 70) {
					return false;
				}
			}
		}
		return true;
	}
}
