(function() {

  // Your web app's Firebase configuration
 var firebaseConfig = {
   apiKey: "AIzaSyA3t7S4VSlclYr2oT0GTN3A9nyJD8PUNU4",
   authDomain: "webguataca.firebaseapp.com",
   databaseURL: "https://webguataca.firebaseio.com",
   projectId: "webguataca",
   storageBucket: "webguataca.appspot.coo o resto de una división, usaremos la palm",
   messagingSenderId: "227338360674",
   appId: "1:227338360674:web:b7d2fde7926589e682be3b",
   measurementId: "G-NYK0TJ1XDZ"
 };
 // Initialize Firebase
 firebase.initializeApp(firebaseConfig);
 firebase.analytics();
  
 var mailCorrecto=false;

 //muestro usuarios en linea desde la base de datos
 var dbRef=firebase.database().ref();
 var userOnline=document.getElementById('userOnline');      
 var nameUser=document.getElementById('nameUser');  
 var onlines; //numero de usuarios en linea
 var aux;         
 var nuevousuario=false;
 dbRef.child('loginsTotales').on('value', snap => { 
   onlines=snap.val();
   userOnline.innerText=onlines;
   
 });      


 
 // Obtener elementos
 const txtEmail = document.getElementById('txtEmail');
 const txtPassword = document.getElementById('txtPassword');
 const btnLogin = document.getElementById('btnLogin');
 const btnSignUp = document.getElementById('btnSignUp');
 const btnLogout = document.getElementById('btnLogout');
 
 const rolUser= document.getElementById('modoUser');
 const rolRoot= document.getElementById('modoRoot');
 const modoRol= document.getElementById('modoRol');
 const modos= document.getElementById('modos');
 var modoRoot;

 // Añadir Evento login
 btnLogin.addEventListener('click', e => {
   //Obtener email y pass
   if (mailCorrecto)
    {
   const email = txtEmail.value;
   const pass = txtPassword.value;
   const auth = firebase.auth();
   // Sign in
   const promise = auth.signInWithEmailAndPassword(email, pass);
   promise.catch(e => console.log(e.message));     
      nuevousuario=false;
    }
   else alert("Email no válido");
   
     
 });
 
txtEmail.addEventListener('keyup', function(objeto) {
    //Creamos un objeto 
 var object=document.getElementById('txtEmail');
 var valor=object.value;  
 var patron=/..+@..+\...+/;
 if(valor.search(patron)==0)
 {
   //Mail correcto
   object.style.color="#000";
   mailCorrecto=true;
   return;
 } else
 //Mail incorrecto
 object.style.color="#f00";
  mailCorrecto=false;
   
});
 // Añadir evento signup
 btnSignUp.addEventListener('click', e => {
   // Obtener email y pass    
   
   if (mailCorrecto)
     {
   const email = txtEmail.value;
   const pass = txtPassword.value;
   const auth = firebase.auth();
   // Sign in
   const promise = auth.createUserWithEmailAndPassword(email, pass);
   promise.catch(e => console.log(e.message));   
   nuevousuario=true;        
     }
   else alert("Email no válido");
 
 });

 btnLogout.addEventListener('click', e => {
   firebase.auth().signOut();   

 });

 // Añadir un listener en tiempo real
  firebase.auth().onAuthStateChanged( firebaseUser => {
   if(firebaseUser) {
     console.log(firebaseUser);
     txtEmail.style.display="none";
     txtPassword.style.display="none";
     btnLogin.style.display="none";
     btnSignUp.style.display="none";
     nameUser.style.display="inline";
     nameUser.innerText=txtEmail.value;      
     btnLogout.style.display="inline";
     modoRol.style.display="inline";      
     modos.style.display="none";
     
    const email = txtEmail.value;
     aux= email.split('@');         
     
     dbRef.child('usuarios/' + aux[0] +"/Rol").on('value', snap => {     
     
       modoRol.innerText=" Actuando como: " + snap.val();    
       
 });      
     dbRef.child('loginsTotales').set(onlines+1);
     
     if (nuevousuario)
 {
 if (rolRoot.checked)
    modoRoot="Root";
 else modoRoot="User";  
      firebase.database().ref("usuarios/" + aux[0] + "/Rol").set(modoRoot);    
   nuevousuario=false;
 }
         
   } else {
     console.log('no logueado');
     //btnLogout.classList.add('hide');
     btnLogout.style.display="none";
     btnLogin.style.display="inline";
     btnSignUp.style.display="inline";
     nameUser.style.display="none";
     modoRol.style.display="none";
     txtEmail.style.display="inline";
     txtPassword.style.display="inline";      
     modos.style.display="inline";      
       dbRef.child('loginsTotales').set(onlines-1);   
   } 
            
   txtEmail.value="";
   txtPassword.value="";

 });
} ());
