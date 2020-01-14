// Función cambio de imagen

$(function() {
  var fruits = document.getElementsByClassName("trees");  //Clase de las frutas.
  for(var i = 0; i < fruits.length; ++ i)
    fruits[i].style.display = "none";
  
  $("#img-fruit").attr("src", "https://cdn.glitch.com/097eb43e-c343-4003-8dc1-0d09b75e76a6%2Fnaranjo.jpg?v=1578227215735");
  var txt_c = document.getElementById("text_c_naranjo");
  document.getElementById("txt-cuidados").innerHTML = document.getElementById("text_c_naranjo").innerHTML;
  document.getElementById("txt-descripcion").innerHTML = document.getElementById("text_d_naranjo").innerHTML;
  $("#v-fruit").attr("src", "https://www.youtube.com/embed/DTDRUWhhwWo"); 
  

});

function change(img, cuidados, descrip, video){
  
  var fruits = document.getElementsByClassName("trees");  //Clase de las frutas.
  for(var i = 0; i < fruits.length; ++ i)
    fruits[i].style.display = "none";
  
  $("#img-fruit").attr("src", img);
  document.getElementById("txt-cuidados").innerHTML = cuidados.innerHTML;
  document.getElementById("txt-descripcion").innerHTML = descrip.innerHTML;
  $("#v-fruit").attr("src", video); 
  
}
function change_html(html){
  
  $("#index_cont").load(html);
  //document.getElementsByClassName("index-cont").innerHTML = html.innerHTML;
}

$(function () {
  $('[data-toggle="popover"]').popover()
})

