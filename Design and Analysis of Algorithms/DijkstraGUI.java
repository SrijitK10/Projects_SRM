import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class DijkstraGUI extends JFrame implements ActionListener {

    // Components
    private JComboBox<String> sourceComboBox;
    private JComboBox<String> destinationComboBox;
    private JButton calculateButton;
    private JLabel imageLabel;

    // Data
    private String cities[] = {"Dehradun","Ponta Sahib","Yamunanagar","Saharanpur","Panipat","Muzzafanagar","Karnal","Delhi"};
    private int adj[][]={{0, 47, 0, 95, 0, 0, 0, 0}, {47, 0, 61, 0, 0, 0, 0, 0}, {0, 61, 0, 39, 0, 0, 67, 0}, {95, 0, 0, 0, 0, 66, 92, 0}, {0, 0, 0, 0, 0, 0, 36, 87}, {0, 0, 0, 66, 0, 0, 0, 150}, {0, 0, 67, 0, 36, 0, 0, 0}, {0, 0, 0, 0, 87, 150, 0, 0}};

    public DijkstraGUI() {
        setTitle("Dijkstra's Algorithm");
        setSize(800, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new GridBagLayout()); // Use GridBagLayout for precise component positioning

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5); // Add insets for padding

        // Components Initialization
        sourceComboBox = new JComboBox<>(cities);
        destinationComboBox = new JComboBox<>(cities);
        calculateButton = new JButton("Calculate");
        calculateButton.addActionListener(this);
        imageLabel = new JLabel();
        ImageIcon imageIcon = new ImageIcon("output.png");
        Image img = imageIcon.getImage();
        Image scaledImg = img.getScaledInstance(660, 500, Image.SCALE_SMOOTH);
        ImageIcon scaledIcon = new ImageIcon(scaledImg);
        imageLabel.setIcon(scaledIcon);

        // Panel for source and destination selection
        JPanel selectionPanel = new JPanel(new GridBagLayout());
        gbc.gridx = 0;
        gbc.gridy = 0;
        selectionPanel.add(new JLabel("Source: "), gbc);
        gbc.gridx = 1;
        selectionPanel.add(sourceComboBox, gbc);
        gbc.gridx = 2;
        selectionPanel.add(new JLabel("Destination: "), gbc);
        gbc.gridx = 3;
        selectionPanel.add(destinationComboBox, gbc);
        gbc.gridx = 4;
        selectionPanel.add(calculateButton, gbc);

        // Adding components to the frame
        gbc.gridx = 0;
        gbc.gridy = 0;
        add(selectionPanel, gbc);
        gbc.gridy = 1;
        gbc.gridwidth = 5; // span across all columns
        gbc.anchor = GridBagConstraints.CENTER; // align to center
        add(imageLabel, gbc);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == calculateButton) {
            int sourceIndex = sourceComboBox.getSelectedIndex();
            int destinationIndex = destinationComboBox.getSelectedIndex();
            if (sourceIndex == destinationIndex) {
                JOptionPane.showMessageDialog(this, "Source and Destination are the same.");
                return;
            }
            if (sourceIndex > destinationIndex) {
                int temp = sourceIndex;
                sourceIndex = destinationIndex;
                destinationIndex = temp;
            }
            int n = cities.length;
            String result = dijkstra(adj, n, sourceIndex, destinationIndex, cities);
            JOptionPane.showMessageDialog(this, result);
        }
    }

    static String dijkstra(int nodes[][], int n, int source, int des, String cities[]) {
        int visited[]=new int[n];
        int cost[][]=new int[n][n];
        int dist[]=new int[n];
        int pred[]=new int[n];
        int count,mindistance,next,i,j;
        next=0;
        for (i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(nodes[i][j]==0)
                {
                    cost[i][j]=10000;
                }
                else
                {
                    cost[i][j]=nodes[i][j];
                }
            }
        }
        for(i=0;i<n;i++)
        {
            dist[i]=cost[source][i];
            pred[i]=source;
            visited[i]=0;
        }
        dist[source]=0;
        visited[source]=1;
        count=1;

        while(count<n)
        {
            mindistance=10000;
            for(i=0;i<n;i++)
            {
                if(dist[i]<mindistance && visited[i]!=1)
                {
                    mindistance=dist[i];
                    next=i;
                }
            }
            visited[next]=1;
            for(i=0;i<n;i++)
            {
                if(visited[i]!=1)
                {
                    if(mindistance+cost[next][i]<dist[i])
                    {
                        dist[i]=mindistance+cost[next][i];
                        pred[i]=next;
                    }
                }
            }
            count++;
        }
        StringBuilder result = new StringBuilder();
        result.append("Best Path from " + cities[source] + " to " + cities[des] + "\n" + //
                        "or from "+cities[des]+" to "+cities[source]+": \n");
         j = des;
        String path = cities[j];
        do {
            j = pred[j];
            path = cities[j] + " <-> " + path;
        } while (j != source);
        result.append(path);
        result.append("\nDistance: " + dist[des]);
        return result.toString();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new DijkstraGUI().setVisible(true);
            }
        });
    }
}
