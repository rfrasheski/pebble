function searchRecipe(numid){
  var response;
  var req = new XMLHttpRequest();
  var apiKey = "your-api-key-here";
  var id = numid;
  var url = "http://api.bigoven.com/recipe/" + id + "&api_key="+apiKey;
  req.open("GET",url,true);
  req.onload = function (e){
    if(req.readyState == 4){
      if(req.status == 200){
        console.log(req.responseText);
        response = JSON.parse(req.responseText);
      }
    }
  };  
}



Pebble.addEventListener("ready",
                         function(e){                           
                           console.log("connect" + e.ready());
                            console.log("connect" + e.ready);
                         });