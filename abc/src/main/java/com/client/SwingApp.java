package com.client;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.websocket.ContainerProvider;
import javax.websocket.DeploymentException;

public class SwingApp extends JFrame {
	public JFrame frame;
	private Client client =null;
	public SwingApp() throws DeploymentException, IOException, URISyntaxException
	{
		startPanel();
		String serverPath = "ws://localhost:8080/abc/sketchServerEndpoint";
		client = new Client(this);
		ContainerProvider.getWebSocketContainer().connectToServer(client, new URI(serverPath));
		addWindowListener(new WindowAdapter() {
			
			public void windowClosing(WindowEvent e)
			{
				client.close();
			}
			
		});
	}
	public void startPanel()
	{
		frame.setSize(400, 400);
		frame.setVisible(true);
	}
	public void messageSketch(String msg) throws IOException
	{
		JOptionPane.showMessageDialog(frame, msg);
		client.getSession().getBasicRemote().sendText(msg);
		
	}
	public static void main(String[] args) throws DeploymentException, IOException, URISyntaxException
	{
		new SwingApp();
		
	}
	
}
