function searchRecipe(term){
  var response;
  var req = new XMLHttpRequest();
  var apiKey = "dvxN9u0sKOMcEr2H15XUUg5Z9o1pLSwT";
  var titleKeyword = term;
  var url = "http://api.bigoven.com/recipes?pg=1&rpp=25&title_kw=" + titleKeyword + "&api_key="+apiKey;
  req.open("GET",url,true);
  req.onload = function (e){
    if(req.readyState == 4){
      if(req.status == 200){
        console.log(req.responseText);
        response = JSON.parse(req.responseText);
      }
    }
  };
  req.send(null);
}



Pebble.addEventListener("ready",
                         function(e){                           console.log("connect" + e.ready());
                            console.log("connect" + e.ready);
                         });