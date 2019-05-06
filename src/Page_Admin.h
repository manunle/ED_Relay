

//
//  HTML PAGE
//

const char PAGE_AdminMainPage[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<strong>Administration</strong>
<hr>
<a href="general.html" style="width:250px" class="btn btn--m btn--blue" >General Configuration</a><br>
<a href="schedule.html" style="width:250px" class="btn btn--m btn--blue" >Schedule Configuration</a><br>
<a href="config.html" style="width:250px" class="btn btn--m btn--blue" >Network Configuration</a><br>
<a href="info.html"   style="width:250px"  class="btn btn--m btn--blue" >Network Information</a><br>
<a href="ntp.html"   style="width:250px"  class="btn btn--m btn--blue" >NTP Settings</a><br>
<a href="status.html"   style="width:250px"  class="btn btn--m btn--blue" >Status</a><br>
<a href="restart.html"   style="width:250px"  class="btn btn--m btn--blue" >Restart</a><br>


<script>
window.onload = function ()
{
	load("style.css","css", function() 
	{
		load("microajax.js","js", function() 
		{
				// Do something after load...
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}

</script>

)=====";

const char PAGE_Wait_Restart[] PROGMEM = R"=====(
<meta http-equiv="refresh" content="5; URL=config.html">
Please Wait.... Restarting.
)=====";


void restartesp()
{
      server.send_P ( 200, "text/html", PAGE_Wait_Restart );

      ESP.restart();
}


