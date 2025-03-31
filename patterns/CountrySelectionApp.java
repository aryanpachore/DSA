import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.Map;

public class CountrySelectionApp extends JFrame {
    private Map<String, String> countryCapitalMap;

    public CountrySelectionApp() {
        // Initialize the country-capital map
        initializeCountryCapitalMap();

        // Create a JComboBox for country selection
        JComboBox<String> countryComboBox = new JComboBox<>(countryCapitalMap.keySet().toArray(new String[0]));
        countryComboBox.setFont(new Font("Arial", Font.PLAIN, 16));

        // Create a JLabel to display the capital
        JLabel capitalLabel = new JLabel("Select a country to see its capital");
        capitalLabel.setFont(new Font("Arial", Font.BOLD, 16));
        capitalLabel.setBorder(new EmptyBorder(10, 0, 10, 0));

        // Add an ActionListener to the JComboBox
        countryComboBox.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String selectedCountry = (String) countryComboBox.getSelectedItem();
                String capital = countryCapitalMap.get(selectedCountry);
                capitalLabel.setText("Capital: " + capital);
            }
        });

        // Create a JPanel for the ComboBox and set its layout
        JPanel comboBoxPanel = new JPanel();
        comboBoxPanel.setBorder(new EmptyBorder(20, 20, 20, 20));
        comboBoxPanel.setLayout(new BorderLayout());
        comboBoxPanel.add(countryComboBox, BorderLayout.CENTER);

        // Create a JPanel for the Label and set its layout
        JPanel labelPanel = new JPanel();
        labelPanel.setBorder(new EmptyBorder(20, 20, 20, 20));
        labelPanel.setLayout(new BorderLayout());
        labelPanel.add(capitalLabel, BorderLayout.CENTER);

        // Create a main JPanel and add the other panels to it
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BorderLayout());
        mainPanel.add(comboBoxPanel, BorderLayout.NORTH);
        mainPanel.add(labelPanel, BorderLayout.SOUTH);

        // Add the main panel to the frame
        add(mainPanel);

        // Set frame properties
        setTitle("Country Selection Form");
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
    }

    private void initializeCountryCapitalMap() {
        countryCapitalMap = new HashMap<>();
        countryCapitalMap.put("United States", "Washington, D.C.");
        countryCapitalMap.put("Canada", "Ottawa");
        countryCapitalMap.put("United Kingdom", "London");
        countryCapitalMap.put("Germany", "Berlin");
        countryCapitalMap.put("France", "Paris");
        countryCapitalMap.put("Japan", "Tokyo");
        countryCapitalMap.put("Australia", "Canberra");
        countryCapitalMap.put("India", "New Delhi");
        countryCapitalMap.put("China", "Beijing");
        countryCapitalMap.put("Brazil", "Brasilia");
        // Add more countries and their capitals as needed
    }

    public static void main(String[] args) {
        // Run the GUI in the Event Dispatch Thread (EDT)
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new CountrySelectionApp().setVisible(true);
            }
        });
    }
}
