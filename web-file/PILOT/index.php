<?php 
  include_once("db.php");
?>

<!DOCTYPE html>
<html lang="pl">

<head>

        <meta charset="utf-8">

        <title>PILOT</title>
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    
        <meta name="author" content="Jakub Strzałka">

        <meta http-equiv="X-Ua-Compatible" content="IE=edge,chrome=1">

        <link rel="stylesheet" href="src/css/bootstrap.css">
        <link rel="stylesheet" href="src/css/style.css">
        
       
        <!--[if lt IE 9]>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/html5shiv/3.7.3/html5shiv.min.js"></script>
	<![endif]-->
     
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script> 
        <script src="https://kit.fontawesome.com/3fa79b594e.js" crossorigin="anonymous"></script>
        <script src="src/js/skript.js"></script>
       
      
        <script>
               

        </script>
 <?php 
 
  


</head>

<body >
        <main class="container">
        <header class="row">
        
        <div class="col-12 mx-auto text-center">ARDUINO WIFI PILOT</div>
        <div class="col-lg-4 mx-auto text-center" style="font-size:1rem">v1.0</div>
        </header> 

        <section class="row">

                <div class="col-md-3 butt text-center m-2 p-2 mx-auto" onclick="save('opcja','rainbow')">
                        <i class="fas fa-rainbow"></i>
                
                </div> 
                <div class="col-md-3 butt text-center m-2 p-2 mx-auto" onclick="save('opcja','music')">
                <i class="fas fa-music"></i>
                </div>
                <div class="col-md-3 butt text-center m-2 p-2 mx-auto" onclick="save('opcja','setall')">
                <i class="fas fa-fill"></i>
                </div>
                 <div class="col-md-3 butt text-center m-2 p-2  mx-auto" >
           
                        <input class="col_p" type="color" id="col_pick" value="#FF0000"> <button class="save" onclick="colo('col_pick')"><i class="fas fa-save"></i></button>
                
                </div>
                <div class="col-md-3 butt text-center m-2 p-2 mx-auto" onclick="save('opcja','colorwipe')">
                <i class="fas fa-car"></i>
                
                </div>
               
                <div class="col-md-3 butt text-center m-2 p-2  mx-auto" onclick="save('opcja','rgbloop')">
                <i class="fas fa-lungs"></i>
                
                </div>
                <div class="col-md-3 butt text-center m-2 p-2  mx-auto" onclick="save('opcja','breath_one')">
                <i class="fas fa-lungs"></i>O
                
                </div>
                <div class="col-md-3 butt text-center m-2 p-2  mx-auto" onclick="save('opcja','breath_random')">
                <i class="fas fa-lungs"></i>R
                
                </div>
                <div class="col-md-3 butt text-center m-2 p-2  mx-auto" onclick="save('opcja','knightrider')">
                <i class="fas fa-car-crash"></i>
                
                </div>
                <div class="col-md-3 butt text-center m-2 p-2  mx-auto" onclick="save('opcja','runniglight')">
                <i class="fas fa-running"></i>
                
                </div>
                <div class="col-md-3 butt text-center m-2 p-2  mx-auto" onclick="save('opcja','meteor')">
                <i class="fas fa-meteor"></i>
                
                </div>
      
               
                <div class="col-md-3 butt text-center m-2 p-2  mx-auto off" onclick="save('opcja','off')">
                <i class="fas fa-power-off" ></i>
                
                </div>
      
             

        </section>



        </main>
</body>
</html>