package com.server;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;
import java.util.*;
import javax.websocket.*;
import javax.websocket.server.ServerEndpoint;
@ServerEndpoint(value="/sketchServerEndpoint")
public class SketchServerEndpoint {
	static Set<Session> users = Collections.synchronizedSet(new HashSet<Session>());
	
	@OnOpen
	public void handleOpen(Session userSession)
	{
		users.add(userSession);
	}
	@OnMessage
	public void handleMessage(String incomingMessage,Session userSession)
	{
		users.stream().filter(x-> !x.equals(userSession)).forEach(x->{
			
		});
	}
	@OnClose
	public void handleClose(Session userSession)
	{
		users.remove(userSession);
	}
	@OnError
	public void handleError(Throwable t)
	{
		System.out.print(t);
	}
}
