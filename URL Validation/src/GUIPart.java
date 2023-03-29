import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class GUIPart {

	static JFrame frame = new JFrame();
	static JPanel panel = new JPanel();
	static JLabel label = new JLabel();
	static JLabel mainLink = new JLabel();
	static JTextField mainLinkText = new JTextField();
	static JLabel depth = new JLabel();
	static JTextField depthText = new JTextField();
	static JButton validate = new JButton();
	static JFrame frame2 = new JFrame();
	static JPanel panel2 = new JPanel();
	static JLabel validLinks = new JLabel();
	static JTextField validLinksText = new JTextField();
	static JLabel invalidLinks = new JLabel();
	static JTextField invalidLinksText = new JTextField();
	static JLabel minEx = new JLabel();
	static JTextField minExText = new JTextField();
	static JLabel numThread = new JLabel();
	static JTextField numThreadText = new JTextField();

	public static void main(String[] args) {
		frame = new JFrame();
		panel = new JPanel();
		frame.setSize(550,310);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		frame.add(panel);
		panel.setLayout(null);
	    label = new JLabel("HTML Checker");
	    label.setBounds(200,20,200,25);
	    panel.add(label);
	    
	    mainLink = new JLabel("Main Link");
		mainLink.setBounds(100,80,80,25);
		panel.add(mainLink);
		
		mainLinkText = new JTextField();
		mainLinkText.setBounds(200, 80, 250, 25);
		panel.add(mainLinkText);
		
		
	    depth = new JLabel("Depth");
		depth.setBounds(100,130,80,25);
		panel.add(depth);
		
		depthText = new JPasswordField();
		depthText.setBounds(200, 130, 250, 25);
		panel.add(depthText);
		
		validate = new JButton("Validate");
		validate.setBounds(300, 180, 100, 25);
		panel.add(validate);
		
		validate.addActionListener(new ActionListener()
		{

			@Override
			public void actionPerformed(ActionEvent e) {
				frame.dispose();
				frame2 = new JFrame();
				panel2 = new JPanel();
				frame2.setSize(550,410);
				frame2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				frame2.setVisible(true);
				frame2.add(panel2);
				panel2.setLayout(null);
				
				validLinks = new JLabel("Valid Links");
				validLinks.setBounds(60,80,80,25);
				panel2.add(validLinks);
				
				validLinksText = new JTextField();
				validLinksText.setBounds(200, 80, 250, 25);
				panel2.add(validLinksText);
				
				
				invalidLinks = new JLabel("InvalidLinks");
				invalidLinks.setBounds(60,130,80,25);
				panel2.add(invalidLinks);
				
				invalidLinksText = new JTextField();
				invalidLinksText.setBounds(200, 130, 250, 25);
				panel2.add(invalidLinksText);
				
				minEx = new JLabel("Min Execution Time");
				minEx.setBounds(60,180,130,25);
				panel2.add(minEx);
				
				minExText = new JTextField();
				minExText.setBounds(200, 180, 250, 25);
				panel2.add(minExText);
				
				
				numThread = new JLabel("Num of Threads");
				numThread.setBounds(60,230,110,25);
				panel2.add(numThread);
				
				numThreadText = new JTextField();
				numThreadText.setBounds(200, 230, 250, 25);
				panel2.add(numThreadText);
				
			}
	
		});

	}

}
