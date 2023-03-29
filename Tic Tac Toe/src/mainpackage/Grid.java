package mainpackage;
//class for initiating the board that will be played in
public class Grid {
	private int x[][] = new int[6][7];

	public Grid() {
		{
			//numbering the cells so the player can choose whether by cell or row and column
			int k = 1;
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 7; j++) {
					x[i][j] = k++;
				}
			}
		}
	}

	public int[][] getX() {
		//getter as the grid is private for security
		return x;
	}

}
