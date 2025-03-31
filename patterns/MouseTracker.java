import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MouseTracker extends JFrame implements MouseListener, MouseMotionListener {
    private JLabel eventLabel;
    private JLabel coordinatesLabel;
    private JPanel trackingArea;

    public MouseTracker() {
        // Set up the frame
        setTitle("Mouse Event Tracker");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Create labels
        eventLabel = new JLabel("No event yet");
        coordinatesLabel = new JLabel("Coordinates: (0, 0)");

        // Create tracking area
        trackingArea = new JPanel();
        trackingArea.setBackground(Color.LIGHT_GRAY);
        trackingArea.addMouseListener(this);
        trackingArea.addMouseMotionListener(this);

        // Create labels panel
        JPanel labelsPanel = new JPanel();
        labelsPanel.setLayout(new GridLayout(2, 1, 5, 5));
        labelsPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        labelsPanel.add(eventLabel);
        labelsPanel.add(coordinatesLabel);

        // Add components to frame
        add(labelsPanel, BorderLayout.NORTH);
        add(trackingArea, BorderLayout.CENTER);

        // Add instruction label
        JLabel instructionLabel = new JLabel("Move, click, or hover in the gray area");
        instructionLabel.setHorizontalAlignment(JLabel.CENTER);
        instructionLabel.setBorder(BorderFactory.createEmptyBorder(10, 0, 10, 0));
        add(instructionLabel, BorderLayout.SOUTH);
    }

    // MouseListener methods
    @Override
    public void mouseClicked(MouseEvent e) {
        eventLabel.setText("Mouse Clicked at (" + e.getX() + ", " + e.getY() + ")");
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        eventLabel.setText("Mouse Entered");
        trackingArea.setBackground(new Color(200, 200, 255));  // Light blue when mouse enters
    }

    @Override
    public void mouseExited(MouseEvent e) {
        eventLabel.setText("Mouse Exited");
        trackingArea.setBackground(Color.LIGHT_GRAY);
    }

    @Override
    public void mousePressed(MouseEvent e) {
        eventLabel.setText("Mouse Pressed");
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        eventLabel.setText("Mouse Released");
    }

    // MouseMotionListener methods
    @Override
    public void mouseMoved(MouseEvent e) {
        coordinatesLabel.setText("Coordinates: (" + e.getX() + ", " + e.getY() + ")");
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        coordinatesLabel.setText("Dragging at: (" + e.getX() + ", " + e.getY() + ")");
    }

    public static void main(String[] args) {
        // Run the application on the Event Dispatch Thread
        SwingUtilities.invokeLater(() -> {
            MouseTracker tracker = new MouseTracker();
            tracker.setLocationRelativeTo(null);  // Center on screen
            tracker.setVisible(true);
        });
    }
}