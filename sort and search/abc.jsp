
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ page import="java.util.*,com.Model.Train" %>
<!DOCTYPE HTML5>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Train Ticket and Availability Status</title>
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous"> 

<style>
    .nav-link {
        margin: 0 5px; /* Space between links */
        color: #fff;
    }
    .nav-link:active {
        font-weight: bold; /* Make active link bold */
    }
    .nav-link::after {
        content: '';
        display: block;
        width: 0;
        height: 2px;
        background: white;
        transition: width .3s;
        position: absolute;
        bottom: -3px; /* Adjust this value to control the vertical space */
        left: 50%;
        transform: translateX(-50%);
    }
    .nav-link:hover::after {
        width: 50%; /* Adjust this value to control the width of the line */
    }
    .navbar {
        background: linear-gradient(to right, #00b09b, #96c93d) !important; /* Navbar gradient */
    }
    .nav-link.active {
        font-weight: bold !important; /* Make active link bold */
    }
    .class-info {
        display: none;
    }
</style>
</head>
<body>
	<%@ include file="header.jsp" %>
	
	<form action="SearchTrain" method="post" class="m-4">
    <div class="mb-3">
        <label for="sourceip" class="form-label">From:</label>
        <input type="text" class="form-control" id="sourceip" name="source">
    </div>
    <div class="mb-3">
        <label for="destinationip" class="form-label">To:</label>
        <input type="text" class="form-control" id="destinationip" name="destination">
    </div>
    <div class="mb-3">
        <label for="ddate" class="form-label">Date:</label>
        <input type="date" class="form-control" id="ddate" name="departuredate" placeholder="DD-MM-YYYY">
    </div>
    <button type="submit" class="btn btn-primary">Search Available Trains</button>
</form>
<% int reqtime = (int) request.getAttribute("reqtime");
 		if(reqtime==1)
 		{	%>
 			
 			<div class="container my-4">
 		    <h1>Available Trains</h1>
 		    <% ArrayList<Train> trains = (ArrayList<Train>) request.getAttribute("trains");
 		   if(trains!=null && trains.size()!=0)
 			{
 				for(Train train:trains)
 				{ %>

 		    <div class="card mb-4">
 		        <div class="card-header">
 		            <%= train.getTrainName() %>
 		        </div>
 		        <div class="card-body">
 		        	<% List<Train.ClassAvailability> cl = train.getClassAvailabilityList();
 		        		for(int i=1;i<=cl.size();i++){%>
 		            <button class="btn btn-outline-primary mb-2" onclick="showClassInfo('<%= train.getTrainName() %>', <%= i %>)"> <%=cl.get(i-1).getClassName() %></button>
 		           <% } %>
 		          
					<% for(int i=1;i<=cl.size();i++){%>
 		            <div id=<%= cl.get(i-1).getClassName() + String.valueOf(i) %> class="class-info mt-3">
 		                <p>Seats Available: <%= cl.get(i-1).getAvailableSeats() %></p>
 		                <p>Fare: <%= cl.get(i-1).getFare() %></p>
 		                <a class="btn btn-primary" href="Booking?trainId=1001&amp;className=First Class">Book Now</a>
 		            </div>
 		             <% } %>
 		        </div>
 		
 		    </div>

         
 		    
 	

 		  
 		</div>
 	

 			
 			


<script>
    function showClassInfo(train, classType) {
        document.querySelectorAll('.class-info').forEach(function(info) {
            info.style.display = 'none';
        });
        document.getElementById(train + '-' + classType).style.display = 'block';
    }
</script>
</body>
</html>