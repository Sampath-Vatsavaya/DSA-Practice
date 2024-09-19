package com.client;
import java.io.IOException;

import javax.websocket.*;
public class Client {
	private Session session;
	private SwingApp swingApp;
	public Client(SwingApp swingApp)
	{
		this.swingApp=swingApp;
	}
	@OnOpen
	public void handleOpen(Session session)
	{
		this.session=session;
	}
	public SwingApp getSwingApp() {
		return swingApp;
	}
	public void setSwingApp(SwingApp swingApp) {
		this.swingApp = swingApp;
	}
	@OnMessage
	public void handleMessage(String incomingMessage) throws IOException
	{
		swingApp.messageSketch(incomingMessage);
	}
	
	@OnError
	public void handleError(Throwable t)
	{
		System.out.print(t);
	}
	public void close()
	{
		try {
			session.close();
			System.exit(0);
		}
		catch(Exception e)
		{
			System.out.println("Disconnect Error...."+e);
		}
	}
	public Session getSession() {
		return session;
	}
	public void setSession(Session session) {
		this.session = session;
	}
}
